 	{
 #if HAVE_LCHOWN
 	  if (lchown (file_name, stat_info->st_uid, stat_info->st_gid) < 0)
-	    {
-	      int e = errno;
-	      ERROR ((0, e, _("%s: Cannot lchown to uid %lu gid %lu"),
-		      quotearg_colon (file_name),
-		      (unsigned long) stat_info->st_uid,
-		      (unsigned long) stat_info->st_gid));
-	    }
+	    chown_error_details (file_name,
+				 stat_info->st_uid, stat_info->st_gid);
 #endif
 	}
       else
 	{
 	  if (chown (file_name, stat_info->st_uid, stat_info->st_gid) < 0)
-	    {
-	      int e = errno;
-	      ERROR ((0, e, _("%s: Cannot chown to uid %lu gid %lu"),
-		      quotearg_colon (file_name),
-		      (unsigned long) stat_info->st_uid,
-		      (unsigned long) stat_info->st_gid));
-	    }
+	    chown_error_details (file_name,
+				 stat_info->st_uid, stat_info->st_gid);
 
 	  /* On a few systems, and in particular, those allowing to give files
 	     away, changing the owner or group destroys the suid or sgid bits.
