}

static void exit_usage (const char *name, int status) {
  fprintf ((status == 0) ? stdout : stderr,
      "Usage: %s [options]\n\n"

      "Available options:\n"
      "  -s             Path to collectd's UNIX socket.\n"
      "                 Default: /var/run/collectd-unixsock\n"
      "  -p <plugin>    Plugin to be flushed.\n"
      "  -i <id>        Flush data identified by <id> only (see below).\n"
      "  -t <seconds>   Flush values older than this value only.\n"

      "\n  -h             Display this help and exit.\n"

      "\nIdentfiers:\n\n"

      "An identifier (as accepted by the -i option) has the following\n"
      "format:\n\n"

      "  [<hostname>/]<plugin>[-<plugin_instance>]/<type>[-<type_instance>]\n\n"

      "Hostname defaults to the local hostname if omitted (e.g., uptime/uptime).\n"
      "No error is returned if the specified identifier does not exist.\n"

      "\nExample:\n\n"

      "  collectd-flush -p rrdtool -i somehost/cpu-0/cpu-wait\n\n"

      "Flushes all CPU wait RRD values of the first CPU of the local host.\n"
      "I.e., writes all pending RRD updates of that data-source to disk.\n"
      , name);
  exit (status);
}

