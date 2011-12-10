#include "stdafx.h"
#include "BetDaqRequestThread.h"

namespace oms
{

class BetDaqRequestThread::Impl
{
public:
	Impl(zmq::context_t *context, const std::string &communication_endpoint);

	void operator()();
private:
	zmq::context_t *context_;
	std::string communication_endpoint_;
};

BetDaqRequestThread::BetDaqRequestThread(zmq::context_t *context, const std::string &communication_endpoint)
	: impl_(boost::make_shared<BetDaqRequestThread::Impl>(context, communication_endpoint))
{
}

BetDaqRequestThread::~BetDaqRequestThread()
{
}

void BetDaqRequestThread::operator()()
{
	impl_->operator()();
}

//===========================================================================================================

BetDaqRequestThread::Impl::Impl(zmq::context_t *context, const std::string &communication_endpoint)
	: context_(context)
	, communication_endpoint_(communication_endpoint)
{
}
	
void BetDaqRequestThread::Impl::operator()()
{
	// TODO: add some actions like
	// receiving communication information,
	// connection to the BetDaq server 
	// sending communication result back to the client that made the request
	//
	std::cerr << "start sleeping in thread " << boost::this_thread::get_id() << "\n";
	sleep(1);
	std::cerr << "Sleep complete! \n";
}

} // namespace oms
