   if (!resp->headers)
     return;
   for (i = 0; resp->headers[i + 1]; i++)
-    print_server_response_1 (prefix, resp->headers[i], resp->headers[i + 1]);
+    {
+      const char *b = resp->headers[i];
+      const char *e = resp->headers[i + 1];
+      /* Skip CRLF */
+      if (b < e && e[-1] == '\n')
+	--e;
+      if (b < e && e[-1] == '\r')
+	--e;
+      /* This is safe even on printfs with broken handling of "%.<n>s"
+	 because resp->headers ends with \0.  */
+      logprintf (LOG_VERBOSE, "%s%.*s\n", prefix, e - b, b);
+    }
 }
 
 /* Parse the `Content-Range' header and extract the information it
