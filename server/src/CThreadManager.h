#pragma once

#include <server/IThreadManager.h>

namespace oms
{
/*!
 * Class for managing set of worker threads that perform all the main job and do 
 * long-running operations with remote servers communication
 * */
class CThreadManager : public IThreadManager
{
public:
	CThreadManager(zmq::context_t *context);
	~CThreadManager();

	/*!
	 * Get 0mq communication point for that thread that will be used to shedule specific task to be performed
	 * */
	virtual std::string getThreadCommunicationPoint();
private:
	class Impl;
	boost::shared_ptr<Impl> impl_;
};

} // namespace oms

