/*!
 * Test 0MQ server, that might be used for testing purposes
*/
#include <zmq.hpp>
#include <string>
#include <iostream>
#include <unistd.h>

int main () {
	int major;
	int minor;
	int patch;

	zmq::version (&major, &minor, &patch);
	std::cout << "Using 0mq library of version " << major << "." << minor << "." << patch << "\n";

	// Prepare our context and socket
	zmq::context_t context (1);
	zmq::socket_t socket (context, ZMQ_REP);
	socket.bind ("tcp://*:5555");

	while (true) {
		zmq::message_t request;
		// Wait for next request from client
		socket.recv (&request);
		std::cout << "Received Hello" << std::endl;

		// Do some 'work'
		sleep (1);

		// Send reply back to client
		zmq::message_t reply (5);
		memcpy ((void *) reply.data (), "World", 5);
		socket.send (reply);
	}
	return 0;
}
