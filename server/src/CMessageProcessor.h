#pragma once

#include <server/IMessageProcessor.h>

namespace oms
{
/*!
 * Basic implementation of message processor
 * */
class CMessageProcessor : public IMessageProcessor
{
public:
	CMessageProcessor(zmq::context_t *context);
	virtual ~CMessageProcessor();

public: // IMessageProcessor
	virtual bool processMessage(const zmq::message_t &message);
private:
	class Impl;
	boost::shared_ptr<Impl> impl_;

};

} //namespace oms
