 #endif
 }
 
+#if HAVE_SYSLOG
+#ifdef LOG_LOCAL4
+
+static struct syslog_facility_name {
+    const char *name;
+    int facility;
+}
+
+syslog_facility_names[] = {
+
+#ifdef LOG_AUTH
+                              {
+                                  "auth", LOG_AUTH
+                              },
+#endif
+#ifdef LOG_AUTHPRIV
+                              {
+                                  "authpriv", LOG_AUTHPRIV
+                              },
+#endif
+#ifdef LOG_CRON
+                              {
+                                  "cron", LOG_CRON
+                              },
+#endif
+#ifdef LOG_DAEMON
+                              {
+                                  "daemon", LOG_DAEMON
+                              },
+#endif
+#ifdef LOG_FTP
+                              {
+                                  "ftp", LOG_FTP
+                              },
+#endif
+#ifdef LOG_KERN
+                              {
+                                  "kern", LOG_KERN
+                              },
+#endif
+#ifdef LOG_LPR
+                              {
+                                  "lpr", LOG_LPR
+                              },
+#endif
+#ifdef LOG_MAIL
+                              {
+                                  "mail", LOG_MAIL
+                              },
+#endif
+#ifdef LOG_NEWS
+                              {
+                                  "news", LOG_NEWS
+                              },
+#endif
+#ifdef LOG_SYSLOG
+                              {
+                                  "syslog", LOG_SYSLOG
+                              },
+#endif
+#ifdef LOG_USER
+                              {
+                                  "user", LOG_USER
+                              },
+#endif
+#ifdef LOG_UUCP
+                              {
+                                  "uucp", LOG_UUCP
+                              },
+#endif
+#ifdef LOG_LOCAL0
+                              {
+                                  "local0", LOG_LOCAL0
+                              },
+#endif
+#ifdef LOG_LOCAL1
+                              {
+                                  "local1", LOG_LOCAL1
+                              },
+#endif
+#ifdef LOG_LOCAL2
+                              {
+                                  "local2", LOG_LOCAL2
+                              },
+#endif
+#ifdef LOG_LOCAL3
+                              {
+                                  "local3", LOG_LOCAL3
+                              },
+#endif
+#ifdef LOG_LOCAL4
+                              {
+                                  "local4", LOG_LOCAL4
+                              },
+#endif
+#ifdef LOG_LOCAL5
+                              {
+                                  "local5", LOG_LOCAL5
+                              },
+#endif
+#ifdef LOG_LOCAL6
+                              {
+                                  "local6", LOG_LOCAL6
+                              },
+#endif
+#ifdef LOG_LOCAL7
+                              {
+                                  "local7", LOG_LOCAL7
+                              },
+#endif
+                              {
+                                  NULL, 0
+                              }
+                          };
+
+#endif
+
+void
+_db_set_syslog(const char *facility) {
+    opt_syslog_enable = 1;
+#ifdef LOG_LOCAL4
+#ifdef LOG_DAEMON
+
+    syslog_facility = LOG_DAEMON;
+#else
+
+    syslog_facility = LOG_LOCAL4;
+#endif
+
+    if (facility) {
+
+        struct syslog_facility_name *n;
+
+        for (n = syslog_facility_names; n->name; n++) {
+            if (strcmp(n->name, facility) == 0) {
+                syslog_facility = n->facility;
+                return;
+            }
+        }
+
+        fprintf(stderr, "unknown syslog facility '%s'\n", facility);
+        exit(1);
+    }
+
+#else
+    if (facility)
+        fprintf(stderr, "syslog facility type not supported on your system\n");
+
+#endif
+}
+
+#endif
+
 void
 Debug::parseOptions(char const *options) {
     int i;
