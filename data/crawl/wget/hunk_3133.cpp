   if (b < e && e[-1] == '\r')
     --e;
   BOUNDED_TO_ALLOCA (b, e, ln);
-  logprintf (LOG_VERBOSE, "  %s\n", ln);
+  logprintf (LOG_VERBOSE, "%s%s\n", prefix, ln);
 }
 
+/* Print the server response, line by line, omitting the trailing CR
+   characters, prefixed with PREFIX.  */
+
 static void
-print_server_response (const struct response *resp)
+print_server_response (const struct response *resp, const char *prefix)
 {
   int i;
   if (!resp->headers)
     return;
   for (i = 0; resp->headers[i + 1]; i++)
-    print_server_response_1 (resp->headers[i], resp->headers[i + 1]);
+    print_server_response_1 (prefix, resp->headers[i], resp->headers[i + 1]);
 }
 
 /* Parse the `Content-Range' header and extract the information it
