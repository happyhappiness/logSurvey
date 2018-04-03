 
 /* Write data in BUF to OUT.  However, if *SKIP is non-zero, skip that
    amount of data and decrease SKIP.  Increment *TOTAL by the amount
-   of data written.  */
+   of data written.  If OUT2 is not NULL, also write BUF to OUT2.
+   In case of error writing to OUT, -1 is returned.  In case of error
+   writing to OUT2, -2 is returned.  In case of any other error,
+   1 is returned.  */
 
 static int
-write_data (FILE *out, const char *buf, int bufsize, wgint *skip,
-            wgint *written)
+write_data (FILE *out, FILE *out2, const char *buf, int bufsize,
+            wgint *skip, wgint *written)
 {
-  if (!out)
+  if (out == NULL && out2 == NULL)
     return 1;
   if (*skip > bufsize)
     {
