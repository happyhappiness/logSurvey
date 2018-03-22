 		    file_name,
 		    (unsigned long) stat_info->st_uid,
 		    (unsigned long) stat_info->st_gid));
-	}
-
-#else /* not HAVE_LCHOWN */
 
-      if (!symlink_flag)
-
-	if (chown (file_name, stat_info->st_uid, stat_info->st_gid) < 0)
-	  ERROR ((0, errno, _("%s: Cannot chown to uid %lu gid %lu"),
-		  file_name,
-		  (unsigned long) stat_info->st_uid,
-		  (unsigned long) stat_info->st_gid));
-
-#endif/* not HAVE_LCHOWN */
-
-      if (!symlink_flag)
-
-	/* On a few systems, and in particular, those allowing to give files
-	   away, changing the owner or group destroys the suid or sgid bits.
-	   So let's attempt setting these bits once more.  */
-
-	if (stat_info->st_mode & (S_ISUID | S_ISGID | S_ISVTX))
-	  set_mode (file_name, stat_info);
+	  /* On a few systems, and in particular, those allowing to give files
+	     away, changing the owner or group destroys the suid or sgid bits.
+	     So let's attempt setting these bits once more.  */
+	  if (stat_info->st_mode & (S_ISUID | S_ISGID | S_ISVTX))
+	    set_mode (file_name, stat_info);
+	}
     }
 }
 
