
#include "libcollectdclient/client.h"

#include <assert.h>

#include <errno.h>

#include <getopt.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#define DEFAULT_SOCK LOCALSTATEDIR"/run/"PACKAGE_NAME"-unixsock"

extern char *optarg;
extern int   optind;

static void exit_usage (const char *name, int status) {
  fprintf ((status == 0) ? stdout : stderr,
      "Usage: %s [options] <command> [cmd options]\n\n"

      "Available options:\n"
      "  -s       Path to collectd's UNIX socket.\n"
      "           Default: "DEFAULT_SOCK"\n"

      "\n  -h       Display this help and exit.\n"

      "\nAvailable commands:\n\n"

      " * flush [timeout=<seconds>] [plugin=<name>] [identifier=<id>]\n"

      "\nIdentifiers:\n\n"

      "An identifier has the following format:\n\n"

      "  [<hostname>/]<plugin>[-<plugin_instance>]/<type>[-<type_instance>]\n\n"

