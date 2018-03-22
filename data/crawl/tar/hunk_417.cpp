 
       if (status == 0)
 	{
-	  /* Fix ownership.  */
-
-	  if (we_are_root)
-	    if (chown (file_name, current_stat.st_uid, current_stat.st_gid) < 0)
-	      ERROR ((0, errno,
-		      _("%s: Cannot change owner to uid %lu, gid %lu"),
-		      file_name,
-		      (unsigned long) current_stat.st_uid,
-		      (unsigned long) current_stat.st_gid));
-
 	  print_for_mkdir (file_name, cursor - file_name,
 			   ~newdir_umask & MODE_RWX);
 	  did_something = 1;
