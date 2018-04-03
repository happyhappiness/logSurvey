 	      goto done_header;
 	    }
 	}
+      /* Check for the `Keep-Alive' header. */
+      if (!http_keep_alive_1)
+	{
+	  if (header_process (hdr, "Keep-Alive", header_exists,
+			      &http_keep_alive_1))
+	    goto done_header;
+	}
+      /* Check for `Connection: Keep-Alive'. */
+      if (!http_keep_alive_2)
+	{
+	  if (header_process (hdr, "Connection", http_process_connection,
+			      &http_keep_alive_2))
+	    goto done_header;
+	}
     done_header:
       free (hdr);
     }
 
   logputs (LOG_VERBOSE, "\n");
 
+  if (contlen != -1
+      && (http_keep_alive_1 || http_keep_alive_2))
+    keep_alive = 1;
+  if (keep_alive && !reused_connection)
+    register_persistent (u->host, u->port, sock);
+
   if ((statcode == HTTP_STATUS_UNAUTHORIZED)
       && authenticate_h)
     {
