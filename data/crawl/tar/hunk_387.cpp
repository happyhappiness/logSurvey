 		ERROR ((0, errno, "%s: fstat", p));
 	      else if (final_stat.st_mtime != restore_times.modtime
 		       || final_stat.st_size != restore_size)
-		ERROR ((0, errno, _("%s: file changed as we read it"), p));
+		ERROR ((0, 0, _("%s: file changed as we read it"), p));
 	      if (close (f) != 0)
 		ERROR ((0, errno, _("%s: close"), p));
 	      if (atime_preserve_option)
