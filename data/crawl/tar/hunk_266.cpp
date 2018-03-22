       }
 #endif /* not MSDOS */
 
-#ifdef S_ISLNK
+#ifdef HAVE_READLINK
     case SYMTYPE:
       {
-	char linkbuf[NAME_FIELD_SIZE + 3]; /* FIXME: may be too short.  */
+	size_t len = strlen (current_stat_info.link_name);
+	char *linkbuf = alloca (len + 1);
 
-	status = readlink (current_file_name, linkbuf, (sizeof linkbuf) - 1);
+	status = readlink (current_stat_info.file_name, linkbuf, len + 1);
 
 	if (status < 0)
 	  {
 	    if (errno == ENOENT)
-	      report_difference (_("No such file or directory"));
+	      readlink_warn (current_stat_info.file_name);
 	    else
-	      {
-		WARN ((0, errno, _("Cannot read link %s"), current_file_name));
-		report_difference (NULL);
-	      }
-	    break;
+	      readlink_error (current_stat_info.file_name);
+	    report_difference (0);
 	  }
-
-	linkbuf[status] = '\0';	/* null-terminate it */
-	if (strncmp (current_link_name, linkbuf, (size_t) status) != 0)
+	else if (status != len
+		 || strncmp (current_stat_info.link_name, linkbuf, len) != 0)
 	  report_difference (_("Symlink differs"));
 
 	break;
       }
-#endif /* not S_ISLNK */
+#endif
 
-#ifdef S_IFCHR
     case CHRTYPE:
-      current_stat.st_mode |= S_IFCHR;
-      goto check_node;
-#endif /* not S_IFCHR */
-
-#ifdef S_IFBLK
-      /* If local system doesn't support block devices, use default case.  */
-
     case BLKTYPE:
-      current_stat.st_mode |= S_IFBLK;
-      goto check_node;
-#endif /* not S_IFBLK */
-
-#ifdef S_ISFIFO
-      /* If local system doesn't support FIFOs, use default case.  */
-
     case FIFOTYPE:
-# ifdef S_IFIFO
-      current_stat.st_mode |= S_IFIFO;
-# endif
-      current_stat.st_rdev = 0;	/* FIXME: do we need this? */
-      goto check_node;
-#endif /* S_ISFIFO */
-
-    check_node:
+
       /* FIXME: deal with umask.  */
 
-      if (!get_stat_data (&stat_data))
+      if (!get_stat_data (current_stat_info.file_name, &stat_data))
 	break;
 
-      if (current_stat.st_rdev != stat_data.st_rdev)
+      if (current_header->header.typeflag == CHRTYPE
+	  ? !S_ISCHR (stat_data.st_mode)
+	  : current_header->header.typeflag == BLKTYPE
+	  ? !S_ISBLK (stat_data.st_mode)
+	  : /* current_header->header.typeflag == FIFOTYPE */
+	  !S_ISFIFO (stat_data.st_mode))
 	{
-	  report_difference (_("Device numbers changed"));
+	  report_difference (_("File type differs"));
 	  break;
 	}
 
-      if (
-#ifdef S_IFMT
-	  current_stat.st_mode != stat_data.st_mode
-#else
-	  /* POSIX lossage.  */
-	  (current_stat.st_mode & 07777) != (stat_data.st_mode & 07777)
-#endif
-	  )
+      if ((current_header->header.typeflag == CHRTYPE
+	   || current_header->header.typeflag == BLKTYPE)
+	  && current_stat_info.stat.st_rdev != stat_data.st_rdev)
+	{
+	  report_difference (_("Device number differs"));
+	  break;
+	}
+
+      if ((current_stat_info.stat.st_mode & MODE_ALL) != (stat_data.st_mode & MODE_ALL))
 	{
-	  report_difference (_("Mode or device-type changed"));
+	  report_difference (_("Mode differs"));
 	  break;
 	}
 
