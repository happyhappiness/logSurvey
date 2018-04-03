 
   /* Writing succeeded. */
   saved_append (write_ptr);
-  fputs (write_ptr, logfp);
+  fputs (write_ptr, fp);
   if (state->bigmsg)
     xfree (state->bigmsg);
 
