 		die(_("unable to write temporary index file"));
 
 	discard_cache();
-	read_cache_from(false_lock.filename.buf);
-
-	return false_lock.filename.buf;
+	ret = get_lock_file_path(&false_lock);
+	read_cache_from(ret);
+	return ret;
 }
 
 static int run_status(FILE *fp, const char *index_file, const char *prefix, int nowarn,
