       saved_append (write_ptr);
       fputs (write_ptr, logfp);
       if (bigmsg)
-	free (bigmsg);
+	xfree (bigmsg);
     }
   if (!opt.no_flush)
     fflush (logfp);
