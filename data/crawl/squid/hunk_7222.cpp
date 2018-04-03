 	    fatal(tmp_error_buf);
 	}
     }
-    debug(20, 1, "Created directory %s\n", path);
+    debug(20, 1) ("Created directory %s\n", path);
     if (stat(path, &sb) < 0 || !S_ISDIR(sb.st_mode)) {
 	sprintf(tmp_error_buf,
 	    "Failed to create directory %s: %s", path, xstrerror());
