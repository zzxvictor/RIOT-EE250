include ../Makefile.tests_common

BOARD_INSUFFICIENT_MEMORY := chronos nucleo32-f031 nucleo32-f042 nucleo32-l031 \
                             telosb wsn430-v1_3b wsn430-v1_4

USEMODULE += gnrc_ipv6
USEMODULE += gnrc_ipv6_nib
USEMODULE += gnrc_netif
USEMODULE += embunit
USEMODULE += netdev_eth
USEMODULE += netdev_test

CFLAGS += -DGNRC_NETTYPE_NDP=GNRC_NETTYPE_TEST
CFLAGS += -DGNRC_PKTBUF_SIZE=512
CFLAGS += -DTEST_SUITES

include $(RIOTBASE)/Makefile.include

test:
	tests/01-run.py
