 	    snprintf(buf, BUFSIZ, "Connection: Keep-Alive\r\n");
 	strcat(msg, buf);
     }
+    strcat(msg, extra_hdrs);
     snprintf(buf, BUFSIZ, "\r\n");
     strcat(msg, buf);
 
+    if (opt_verbose)
+	fprintf(stderr, "headers: '%s'\n", msg);
+
     if (ping) {
 #if HAVE_SIGACTION
 	struct sigaction sa, osa;
