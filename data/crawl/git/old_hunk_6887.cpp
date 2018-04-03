	}

	if (log_syslog) {
		openlog("git-daemon", 0, LOG_DAEMON);
		set_die_routine(daemon_die);
	}

	if (inetd_mode && (group_name || user_name))
		die("--user and --group are incompatible with --inetd");
