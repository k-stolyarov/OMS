#pragma once

namespace oms
{

/*!
 * Class for performing some one-shot user requests to BetDaq server
 * */
class BetDaqRequestThread
{
public:
	/*!
	 * Constructor
	 * \param context -- 0mq context to create separate connunication endpoint(s)
	 * \param communication_endpoint -- 0mq communication endpoint for passing BetDaq request-specific information
	 */
	BetDaqRequestThread(zmq::context_t *context, const std::string &communication_endpoint);
	~BetDaqRequestThread();

	//! main thread execution function 
	void operator()();
private:
	class Impl;
	boost::shared_ptr<Impl> impl_;
};

} // namespace oms
