LIB = network

SRCS =							\
	basictypes					\
	bsd_snprintf				\
	bundle						\
	channel						\
	condemned_channels			\
	endpoint					\
	file_stream					\
	forwarding_string_handler	\
	interface_element			\
	irregular_channels			\
	keepalive_channels			\
	logger_message_forwarder	\
	machine_guard				\
	mercury						\
	monitored_channels			\
	netmask						\
	nub							\
	packet						\
	packet_filter				\
	remote_stepper				\
	watcher_glue				\
	watcher_nub					\
	watcher_packet_handler		\

ifndef USE_OPENSSL
	USE_OPENSSL = 1
endif

ifeq ($(USE_OPENSSL),1)
	SRCS +=							\
		encryption_filter			\
		public_key_cipher			\

endif

ifndef MF_ROOT
export MF_ROOT := $(subst /src/lib/$(LIB),,$(CURDIR))
endif

include $(MF_ROOT)/src/lib/makestuf/stdmake.mak

all::

ifeq ($(wildcard bsd_snprintf.cp*),bsd_snprintf.cpp)
# Do not optimise this file. bsdFormatFloat does not perform
# correctly when it is optimised past O2
$(MF_CONFIG)/bsd_snprintf.o: bsd_snprintf.cpp
ifdef QUIET_BUILD
	test -e $(MSG_FILE) && cat $(MSG_FILE); rm -f $(MSG_FILE)
	@echo $<
endif
	$(COMPILE.cc) -O0 $< $(OUTPUT_OPTION)
	@if test -e bsd_snprintf.d; then 						\
		echo -n $(MF_CONFIG)/ > $(MF_CONFIG)/bsd_snprintf.d;	\
		cat bsd_snprintf.d >> $(MF_CONFIG)/bsd_snprintf.d;\
		rm bsd_snprintf.d;									\
	fi
endif

