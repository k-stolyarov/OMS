#include "stdafx.h"
#include "CThreadManager.h"
#include "BetDaqRequestThread.h"

namespace oms
{
class CThreadManager::Impl
{
public:
	Impl(zmq::context_t *context);

	std::string getThreadCommunicationPoint();
private:
	//! get communication endpoint name that will be passed to the client and to the performing thread
	std::string get_communication_endpoint_name();
private:
	zmq::context_t *context_;
};

CThreadManager::CThreadManager(zmq::context_t *context)
	: impl_(boost::make_shared<CThreadManager::Impl>(context))
{
}

CThreadManager::~CThreadManager()
{
}

std::string CThreadManager::getThreadCommunicationPoint()
{
	return impl_->getThreadCommunicationPoint();
}

//===========================================================================================================

CThreadManager::Impl::Impl(zmq::context_t *context)
	: context_(context)
{
}

std::string CThreadManager::Impl::getThreadCommunicationPoint()
{
	std::string endpoint = get_communication_endpoint_name();

	// TODO: add thared pool without spawning threads if not required
	// start thread instance
	BetDaqRequestThread t(context_, endpoint);
	boost::thread thread(t);

	return endpoint;
}

std::string  CThreadManager::Impl::get_communication_endpoint_name()
{
	static int counter = 0 ;
	std::stringstream ss;
	ss << "inproc://" << counter++ << "x" << time(0);
	return ss.str();
}

} // namespace oms
