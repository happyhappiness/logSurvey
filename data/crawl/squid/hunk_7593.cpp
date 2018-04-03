     /* NOTREACHED */
     return 0;
 }
+
+static void sendSignal()
+{
+	int pid;
+	debug_log = stderr;
+	if (ConfigFile == NULL)
+	    ConfigFile = xstrdup(DefaultConfigFile);
+	parseConfigFile(ConfigFile);
+	pid = readPidFile();
+	if (pid > 1) {
+	    if (kill(pid, opt_send_signal) &&
+		/* ignore permissions if just running check */
+		!(opt_send_signal == 0 && errno == EPERM)) {
+		fprintf(stderr, "%s: ERROR: Could not send ", appname);
+		fprintf(stderr, "signal %d to process %d: %s\n",
+			opt_send_signal, pid, xstrerror());
+		exit(1);
+	    }
+	} else {
+	    fprintf(stderr, "%s: ERROR: No running copy\n", appname);
+	    exit(1);
+	}
+	/* signal successfully sent */
+	exit(0);
+    }
