#pragma once

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/thread.hpp>

#ifndef BOOST_LOG_USE_NATIVE_SYSLOG
#define BOOST_LOG_USE_NATIVE_SYSLOG
#endif
#include <boost/log/core.hpp>
#include <boost/log/sinks/syslog_backend.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/sources/record_ostream.hpp>

#include <zmq.hpp>

#include <iostream>
#include <string>
#include <unistd.h>

