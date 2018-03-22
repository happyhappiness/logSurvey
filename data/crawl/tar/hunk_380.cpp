 	  if (remove_files_option)
 	    {
 	      if (unlink (p) == -1)
-		ERROR ((0, errno, _("Cannot remove %s"), p));
+		unlink_error (p);
 	    }
 	  return;
 	}
