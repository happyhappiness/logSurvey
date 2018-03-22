 	    {
 	      struct stat final_stat;
 	      if (fstat (f, &final_stat) != 0)
-		stat_error (p);
+		{
+		  if (ignore_failed_read_option)
+		    stat_warn (p);
+		  else
+		    stat_error (p);
+		}
 	      else if (final_stat.st_ctime != original_ctime)
-		ERROR ((0, 0, _("File %s changed as we read it"), quote (p)));
+		{
+		  char const *qp = quotearg_colon (p);
+		  WARN ((0, 0, _("%s: file changed as we read it"), qp));
+		  if (! ignore_failed_read_option)
+		    exit_status = TAREXIT_FAILURE;
+		}
 	      if (close (f) != 0)
-		close_error (p);
+		{
+		  if (ignore_failed_read_option)
+		    close_warn (p);
+		  else
+		    close_error (p);
+		}
 	      if (atime_preserve_option)
 		utime (p, &restore_times);
 	    }
