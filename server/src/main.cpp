/*!
 * Test 0MQ server, that receive incomming connection, get from the connection
 * response address, spawn separate thread that make some work and send response 
 * to the address specified in request
*/

#include "stdafx.h"
#include "CMessageProcessor.h"
#include <server/log.h>

int main(int argc, char** argv)
{
	oms::init_logging();
	BOOST_LOG_SEV(oms::logger::get(), boost::log::sinks::syslog::warning) << "Starting OMS server";
	int major;
	int minor;
	int patch;
	

	zmq::version (&major, &minor, &patch);
	BOOST_LOG_SEV(oms::logger::get(), boost::log::sinks::syslog::debug) << "Using 0mq library of version " << major << "." << minor << "." << patch << "\n";

	std::string clients_request_socket = "tcp://*:5555";

// Prepare our context and socket
	zmq::context_t context (1);
	zmq::socket_t socket (context, ZMQ_REP);
	socket.bind (clients_request_socket.c_str());

	oms::CMessageProcessor processor(&context);

	while (true) {
		zmq::message_t request;
		// Wait for next request from client
		socket.recv (&request);
		std::cout << "Received Some message" << std::endl;
		zmq::message_t reply;
		if (!processor.processMessage(request))
		{
			// failed to process message, that is really bad
			BOOST_ASSERT(false);
			reply.rebuild(3);
			memcpy ((void *) reply.data (), "Bad", 3);

		}
		else
		{
			reply.rebuild(4);
			memcpy ((void *) reply.data (), "Good", 4);
		}
		// Send reply back to client
		socket.send (reply);

	}
	return 0;
}

