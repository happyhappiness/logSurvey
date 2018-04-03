 } /* static void update_kstat (void) */
 #endif /* HAVE_LIBKSTAT */
 
+/* TODO
+ * Remove all settings but `-f' and `-C'
+ */
+static void exit_usage (char *name)
+{
+	printf ("Usage: "PACKAGE" [OPTIONS]\n\n"
+			
+			"Available options:\n"
+			"  General:\n"
+			"    -C <file>       Configuration file.\n"
+			"                    Default: "CONFIGFILE"\n"
+#if COLLECT_DAEMON
+			"    -f              Don't fork to the background.\n"
+#endif
+			"\n"PACKAGE" "VERSION", http://verplant.org/collectd/\n"
+			"by Florian octo Forster <octo@verplant.org>\n"
+			"for contributions see `AUTHORS'\n");
+	exit (0);
+} /* static void exit_usage (char *name) */
+
 static int start_client (void)
 {
 	int sleepingtime;
