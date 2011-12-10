#pragma once
#include <zmq.h>

namespace oms
{
/*!
 * Interface for processing all messages that come from clients
 * */
class IMessageProcessor
{
public:
	~IMessageProcessor(){}

	/*!
	 * Process incoming 0mq message. Perform message processing and scheduling of long-running operations to separate threads
	 * \param message message body to process
	 * \return true if message processing succeed
	 * */
	virtual bool processMessage(const zmq::message_t &message) = 0;
};

} // namespace oms

