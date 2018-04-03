     }
     close(0);
 
-    if (!strncmp(operation, "info", 4) ||
-	!strncmp(operation, "Cache Information", 17)) {
+    if (!strcmp(operation, "info") ||
+	!strcmp(operation, "Cache Information")) {
 	op = INFO;
-	sprintf(msg, "GET cache_object://%s/info\r\n", hostname);
-    } else if (!strncmp(operation, "squid.conf", 10) ||
-	!strncmp(operation, "Cache Configuration File", 24)) {
+    } else if (!strcmp(operation, "squid.conf") ||
+	!strcmp(operation, "Cache Configuration File")) {
 	op = CACHED;
-	sprintf(msg, "GET cache_object://%s/squid.conf\r\n", hostname);
-    } else if (!strncmp(operation, "server_list", 11) ||
-	!strncmp(operation, "Cache Server List", 17)) {
+    } else if (!strcmp(operation, "server_list") ||
+	!strcmp(operation, "Cache Server List")) {
 	op = SERVER;
-	sprintf(msg, "GET cache_object://%s/server_list\r\n", hostname);
 #ifdef MENU_SHOW_LOG
-    } else if (!strncmp(operation, "log", 3) ||
-	!strncmp(operation, "Cache Log", 9)) {
+    } else if (!strcmp(operation, "log") ||
+	!strcmp(operation, "Cache Log")) {
 	op = LOG;
-	sprintf(msg, "GET cache_object://%s/log\r\n", hostname);
 #endif
-    } else if (!strncmp(operation, "parameter", 9) ||
-	!strncmp(operation, "Cache Parameters", 16)) {
+    } else if (!strcmp(operation, "parameter") ||
+	!strcmp(operation, "Cache Parameters")) {
 	op = PARAM;
-	sprintf(msg, "GET cache_object://%s/parameter\r\n", hostname);
-#ifdef MENU_RESPONSETIME
-    } else if (!strncmp(operation, "responsetime", 11) ||
-	!strncmp(operation, "Cache Response Time Histogram", 28)) {
-	op = RESPT;
-	sprintf(msg, "GET cache_object://%s/responsetime\r\n", hostname);
-#endif
-    } else if (!strncmp(operation, "stats/general", 13) ||
-	!strncmp(operation, "General Statistics", 18)) {
+    } else if (!strcmp(operation, "stats/general") ||
+	!strcmp(operation, "General Statistics")) {
 	op = STATS_G;
-	sprintf(msg, "GET cache_object://%s/stats/general\r\n", hostname);
-    } else if (!strncmp(operation, "stats/vm_objects", 16)) {
-	op = STATS_O;
-	sprintf(msg, "GET cache_object://%s/stats/vm_objects\r\n", hostname);
-    } else if (!strncmp(operation, "stats/objects", 13) ||
-	!strncmp(operation, "Objects", 7)) {
+    } else if (!strcmp(operation, "stats/vm_objects") ||
+	!strcmp(operation, "VM_Objects")) {
+	op = STATS_VM;
+    } else if (!strcmp(operation, "stats/objects") ||
+	!strcmp(operation, "Objects")) {
 	op = STATS_O;
-	sprintf(msg, "GET cache_object://%s/stats/objects\r\n", hostname);
-    } else if (!strncmp(operation, "stats/utilization", 17) ||
-	!strncmp(operation, "Utilization", 11)) {
+    } else if (!strcmp(operation, "stats/utilization") ||
+	!strcmp(operation, "Utilization")) {
 	op = STATS_U;
-	sprintf(msg, "GET cache_object://%s/stats/utilization\r\n", hostname);
-    } else if (!strncmp(operation, "shutdown", 8)) {
+    } else if (!strcmp(operation, "shutdown")) {
 	op = SHUTDOWN;
-	sprintf(msg, "GET cache_object://%s/shutdown@%s\r\n", hostname, password);
-    } else if (!strncmp(operation, "refresh", 7)) {
+    } else if (!strcmp(operation, "refresh")) {
 	op = REFRESH;
-	sprintf(msg, "GET %s HTTP/1.0\r\nPragma: no-cache\r\nAccept: */*\r\n\r\n", url);
 #ifdef REMOVE_OBJECT
-    } else if (!strncmp(operation, "remove", 6)) {
+    } else if (!strcmp(operation, "remove")) {
 	op = REMOVE;
-	/* Peter: not sure what to do here - depends what you do at your end! */
-	sprintf(msg, "REMOVE %s HTTP/1.0\r\nPragma: no-cache\r\nAccept: */*\r\n\r\n", url);
 #endif
-
     } else {
 	printf("Unknown operation: %s\n", operation);
 	exit(0);
     }
 
+    switch (op) {
+    case INFO:
+    case CACHED:
+    case SERVER:
+    case LOG:
+    case PARAM:
+    case STATS_G:
+    case STATS_O:
+    case STATS_VM:
+    case STATS_U:
+	sprintf(msg, "GET cache_object://%s/%s HTTP/1.0\r\n\r\n",
+	    hostname, op_cmds[op]);
+	break;
+    case SHUTDOWN:
+	sprintf(msg, "GET cache_object://%s/%s@%s HTTP/1.0\r\n\r\n",
+	    hostname, op_cmds[op], password);
+	break;
+    case REFRESH:
+	sprintf(msg, "GET %s HTTP/1.0\r\nPragma: no-cache\r\nAccept: */*\r\n\r\n", url);
+	break;
+#ifdef REMOVE_OBJECT
+    case REMOVE:
+	printf("Remove not yet supported\n");
+	exit(0);
+	/* NOTREACHED */
+#endif
+    default:
+    case MAXOP:
+	printf("Unknown operation: %s\n", operation);
+	exit(0);
+	/* NOTREACHED */
+    }
 
     time_val = time(NULL);
     time_string = ctime(&time_val);
