         else
             buflen = strlen(buf);   /* keep this so we only scan the buffer for \0 once per loop */
 
-        helper_debug("Got %d bytes '%s' from Squid\n", buflen, buf);
+        debug("Got %d bytes '%s' from Squid\n", buflen, buf);
 
         /* send 'no-change' result back to Squid */
         fprintf(stdout,"\n");
     }
-    helper_debug("%s build " __DATE__ ", " __TIME__ " shutting down...\n", my_program_name);
+    debug("%s build " __DATE__ ", " __TIME__ " shutting down...\n", my_program_name);
     exit(0);
 }