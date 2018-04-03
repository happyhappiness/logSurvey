}

static void exit_usage (const char *name, int status) {
  fprintf ((status == 0) ? stdout : stderr, "Usage: %s [options]\n"
      "\n"
      "Valid options are:\n"
      "  -h, --help               Display this help message.\n"
      "  -s, --socket=<socket>    Path to collectd's UNIX socket. Default: /var/run/collectd-unixsock\n"
      "  -p, --plugin=<plugin>    Plugin to flush _to_ (not from). Example: rrdtool\n"
      "  -i, --identifier=<identifier>\n"
      "                           Only flush data specified by <identifier>, which has the format: \n"
      "\n"
      "                             [<hostname>/]<plugin>[-<plugin_instance>]/<type>[-<type_instance>]\n"
      "\n"
      "                           Hostname defaults to the local hostname if omitted.\n"
      "                           No error is returned if the specified identifier does not exist.\n"
      "                           Examples: uptime/uptime\n"
      "                                     somehost/cpu-0/cpu-wait\n"
      "  -t, --timeout=<timeout>  Only flush values older than this timeout.\n", name);
  exit (status);
}

