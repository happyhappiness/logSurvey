 	  utimbuf.modtime = stat_info->st_mtime;
 
 	  if (utime (file_name, &utimbuf) < 0)
-	    {
-	      int e = errno;
-	      ERROR ((0, e,
-		      _("%s: Cannot change access and modification times"),
-		      quotearg_colon (file_name)));
-	    }
+	    utime_error (file_name);
 	}
 
       /* Some systems allow non-root users to give files away.  Once this
