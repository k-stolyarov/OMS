import os

env = Environment(CPPPATH = [os.environ['OMS_ROOT'], '.'])
Export('env')

#SConscript('0mq_server/SConscript', variant_dir=os.path.join('build', '0mq_server'), duplicate=0)
#SConscript('0mq_client/SConscript', variant_dir=os.path.join('build', '0mq_client'), duplicate=0)

SConscript('testapp/SConscript');
SConscript('server/SConscript');
