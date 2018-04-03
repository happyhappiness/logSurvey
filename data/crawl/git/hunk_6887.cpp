 	}
 
 	if (log_syslog) {
-		openlog("git-daemon", 0, LOG_DAEMON);
+		openlog("git-daemon", LOG_PID, LOG_DAEMON);
 		set_die_routine(daemon_die);
 	}
+	else
+		setlinebuf(stderr); /* avoid splitting a message in the middle */
 
 	if (inetd_mode && (group_name || user_name))
 		die("--user and --group are incompatible with --inetd");
