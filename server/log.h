#pragma once

#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/global_logger_storage.hpp>

namespace oms
{
BOOST_LOG_GLOBAL_LOGGER(logger, boost::log::sources::severity_logger_mt< boost::log::sinks::syslog::level >);

//! perform logging facilities initialization
void init_logging();

} // namespace oms
