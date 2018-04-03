 
         debug("Got %d bytes '%s' from Squid\n", buflen, buf);
 
-        /* send 'no-change' result back to Squid */
-        fprintf(stdout,"\n");
+        p = NULL;
+        int64_t channelId = strtoll(buf, &p, 10);
+        if (*p != ' ') {
+            /* send 'no-change' result back to Squid in non-concurrent format */
+            fprintf(stdout,"ERR\n");
+        } else {
+            /* send 'no-change' result back to Squid in concurrent format */
+            fprintf(stdout, "%" PRId64 " ERR\n", channelId);
+        }
     }
     debug("%s build " __DATE__ ", " __TIME__ " shutting down...\n", my_program_name);
-    exit(0);
+    return 0;
 }
