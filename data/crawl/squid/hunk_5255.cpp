 usage(void)
 {
     fprintf(stderr,
+#if USE_WIN32_SERVICE
+            "Usage: %s [-dhirsvzCDFNRVYX] [-f config-file] [-[au] port] [-k signal] [-n name] [-O CommandLine]\n"
+#else
             "Usage: %s [-dhsvzCDFNRVYX] [-f config-file] [-[au] port] [-k signal]\n"
+#endif
             "       -a port   Specify HTTP port number (default: %d).\n"
             "       -d level  Write debugging to stderr also.\n"
             "       -f file   Use given config-file instead of\n"
             "                 %s\n"
             "       -h        Print help message.\n"
+#if USE_WIN32_SERVICE
+            "       -i        Installs as a Windows Service (see -n option).\n"
+#endif
             "       -k reconfigure|rotate|shutdown|interrupt|kill|debug|check|parse\n"
             "                 Parse configuration file, then send signal to \n"
             "                 running copy (except -k parse) and exit.\n"
+#if USE_WIN32_SERVICE
+            "       -n name   Specify Windows Service name to use for service operations\n"
+            "                 default is: " _WIN_SQUID_DEFAULT_SERVICE_NAME ".\n"
+            "       -r        Removes a Windows Service (see -n option).\n"
+#endif
             "       -s        Enable logging to syslog.\n"
             "       -u port   Specify ICP port number (default: %d), disable with 0.\n"
             "       -v        Print version.\n"