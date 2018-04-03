 	debug(50, 0, "%s: %s\n", swaplog_path, xstrerror());
 	fatal("Failed to open swap log for reading");
     }
+    memset(&clean_sb, '\0', sizeof(struct stat));
     if (stat(clean_path, &clean_sb) < 0)
 	*clean_flag = 0;
     else if (clean_sb.st_mtime < log_sb.st_mtime)
