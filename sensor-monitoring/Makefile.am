AM_DEFAULT_SOURCE_EXT = .cpp
AM_CPPFLAGS = -I${top_src_dir}

sbin_PROGRAMS = phosphor-sensor-monitor

phosphor_sensor_monitor_SOURCES = \
	main.cpp \
	monitor.cpp \
	functor.cpp \
	generated.cpp
phosphor_sensor_monitor_LDFLAGS = $(SDBUSPLUS_LIBS)
phosphor_sensor_monitor_CXXFLAGS = $(SDBUSPLUS_CFLAGS)
