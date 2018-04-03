 	if (inetd_mode || serve_mode)
 		return execute();
 
-	if (detach)
-		daemonize();
-	else
+	if (detach) {
+		if (daemonize())
+			die("--detach not supported on this platform");
+	} else
 		sanitize_stdfds();
 
 	if (pid_file)
