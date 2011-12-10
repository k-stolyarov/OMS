#include "stdafx.h"
#include "CMessageProcessor.h"
#include "CThreadManager.h"

namespace oms
{

class CMessageProcessor::Impl
{
public:
	Impl(zmq::context_t *context);

	bool processMessage(const zmq::message_t &message);
private:
	zmq::context_t *context_;
	IThreadManagerPtr thread_manager_;
};

CMessageProcessor::CMessageProcessor(zmq::context_t *context)
	: impl_(boost::make_shared<CMessageProcessor::Impl>(context))
{
}

CMessageProcessor::~CMessageProcessor()
{
}

bool CMessageProcessor::processMessage(const zmq::message_t &message)
{
	return impl_->processMessage(message);
}

//===========================================================================================================

CMessageProcessor::Impl::Impl(zmq::context_t *context)
	: context_(context)
	, thread_manager_(boost::make_shared<CThreadManager>(context))
{
}

bool CMessageProcessor::Impl::processMessage(const zmq::message_t &message)
{
	// TODO: implement
	
	BOOST_ASSERT(false);
	
	// get thread that will perform current task
	std::string endpoint = thread_manager_->getThreadCommunicationPoint();
	std::cout << "Got thread communication endpoint: " << endpoint << std::endl;

	return false;
}

} // namespace oms
