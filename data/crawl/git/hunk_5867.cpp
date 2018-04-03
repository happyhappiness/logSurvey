 		hook_arg1 = "message";
 	} else if (logfile) {
 		if (strbuf_read_file(&sb, logfile, 0) < 0)
-			die("could not read log file '%s': %s",
-			    logfile, strerror(errno));
+			die_errno("could not read log file '%s'",
+				  logfile);
 		hook_arg1 = "message";
 	} else if (use_message) {
 		buffer = strstr(use_message_buffer, "\n\n");
