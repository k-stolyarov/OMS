#pragma once

namespace oms
{
/*!
 * interface for managing set of worker threads that perform all the main job and do 
 * long-running operations with remote servers communication
 * */
class IThreadManager
{
public:
	virtual ~IThreadManager(){}

	/*!
	 * Get 0mq communication point for that thread that will be used to shedule specific task to be performed
	 * */
	virtual std::string getThreadCommunicationPoint() = 0;
};

typedef boost::shared_ptr<IThreadManager> IThreadManagerPtr;

} // namespace oms
