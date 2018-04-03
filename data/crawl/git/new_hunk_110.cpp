		}
		if (!strcmp(arg, "--inetd")) {
			inetd_mode = 1;
			continue;
		}
		if (!strcmp(arg, "--verbose")) {
			verbose = 1;
			continue;
		}
		if (!strcmp(arg, "--syslog")) {
			log_destination = LOG_DESTINATION_SYSLOG;
			continue;
		}
		if (skip_prefix(arg, "--log-destination=", &v)) {
			if (!strcmp(v, "syslog")) {
				log_destination = LOG_DESTINATION_SYSLOG;
				continue;
			} else if (!strcmp(v, "stderr")) {
				log_destination = LOG_DESTINATION_STDERR;
				continue;
			} else if (!strcmp(v, "none")) {
				log_destination = LOG_DESTINATION_NONE;
				continue;
			} else
				die("unknown log destination '%s'", v);
		}
		if (!strcmp(arg, "--export-all")) {
			export_all_trees = 1;
			continue;
