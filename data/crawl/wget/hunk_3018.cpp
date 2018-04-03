   xfree (resp);
 }
 
-/* Print [b, e) to the log, omitting the trailing CRLF.  */
-
-static void
-print_server_response_1 (const char *prefix, const char *b, const char *e)
-{
-  char *ln;
-  if (b < e && e[-1] == '\n')
-    --e;
-  if (b < e && e[-1] == '\r')
-    --e;
-  BOUNDED_TO_ALLOCA (b, e, ln);
-  logprintf (LOG_VERBOSE, "%s%s\n", prefix, escnonprint (ln));
-}
-
-/* Print the server response, line by line, omitting the trailing CR
-   characters, prefixed with PREFIX.  */
+/* Print the server response, line by line, omitting the trailing CRLF
+   from individual header lines, and prefixed with PREFIX.  */
 
 static void
 print_server_response (const struct response *resp, const char *prefix)
