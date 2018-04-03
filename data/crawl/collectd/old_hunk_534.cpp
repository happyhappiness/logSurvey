	fprintf (stderr, "Usage: %s <-s socket> <-n value_spec> [options]\n"
			"\n"
			"Valid options are:\n"
			" -s <socket>   Path to collectd's UNIX-socket\n"
			" -n <v_spec>   Value specification to get from collectd\n"
			" -c <range>    Critical range\n"
			" -w <range>    Range for critical values\n",
			name);
	exit (1);
} /* void usage */

