#include "stdafx.h"
#include <server/log.h>

namespace oms
{

BOOST_LOG_GLOBAL_LOGGER_DEFAULT(logger, boost::log::sources::severity_logger_mt< boost::log::sinks::syslog::level >);

// The function registers syslog sinks in the logging library
void init_logging()
{
	boost::shared_ptr< boost::log::core > core = boost::log::core::get();

	// Create a backend
	boost::shared_ptr< boost::log::sinks::syslog_backend > backend(new boost::log::sinks::syslog_backend(
				// set the logging facility
				boost::log::keywords::facility = boost::log::sinks::syslog::user,
				// specify that the native UNIX API should be used
				boost::log::keywords::use_impl = boost::log::sinks::syslog::native
				));

	// Set the straightforward level translator for the "Severity" attribute of type int
	backend->set_severity_mapper(boost::log::sinks::syslog::direct_severity_mapping< int >("Severity"));

	// Wrap it into the frontend and register in the core.
	// The backend requires synchronization in the frontend.
	typedef boost::log::sinks::synchronous_sink< boost::log::sinks::syslog_backend > sink_t;
	core->add_sink(boost::make_shared< sink_t >(backend));

	// Create a new backend
	//backend.reset(new boost::log::sinks::syslog_backend(
	//			// set the logging facility
	//			boost::log::keywords::facility = boost::log::sinks::syslog::local0,
	//			// specify that the built-in implementation should be used
	//			boost::log::keywords::use_impl = boost::log::sinks::syslog::udp_socket_based
	//			));

	// Setup the target address and port to send syslog messages to. By default used localhost:514
	//backend->set_target_address("192.164.1.10", 514);

	// Create and fill in another level translator for "MyLevel" attribute of type string
	boost::log::sinks::syslog::custom_severity_mapping< std::string > mapping("MyLevel");
	mapping["debug"] = boost::log::sinks::syslog::debug;
	mapping["normal"] = boost::log::sinks::syslog::info;
	mapping["warning"] = boost::log::sinks::syslog::warning;
	mapping["failure"] = boost::log::sinks::syslog::critical;
	backend->set_severity_mapper(mapping);

	// Wrap it into the frontend and register in the core.
	core->add_sink(boost::make_shared< sink_t >(backend));
}
} // namespace oms
