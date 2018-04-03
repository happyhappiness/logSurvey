 	} else {
 		if (!cached) {
 			if (lstat(path, &st) < 0)
-				die("unable to stat newly created file %s",
-				    path);
+				die_errno("unable to stat newly created file '%s'",
+					  path);
 			fill_stat_cache_info(ce, &st);
 		}
 		if (write_sha1_file(buf, size, blob_type, ce->sha1) < 0)
