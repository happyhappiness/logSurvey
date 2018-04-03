         }
       else if (ALLOW_CLOBBER)
         {
+	  if (opt.unlink && file_exists_p (hs->local_file))
+	    {
+	      int res = unlink (hs->local_file);
+	      if (res < 0)
+		{
+		  logprintf (LOG_NOTQUIET, "%s: %s\n", hs->local_file,
+			     strerror (errno));
+		  CLOSE_INVALIDATE (sock);
+		  xfree (head);
+		  return UNLINKERR;
+		}
+	    }
+
 #ifdef __VMS
           int open_id;
 
