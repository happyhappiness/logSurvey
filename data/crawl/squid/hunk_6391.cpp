 	if (S_ISDIR(st.st_mode)) {
 	    debug(20, should_exist ? 3 : 1) ("%s exists\n", path);
 	} else {
-	    snprintf(tmp_error_buf, ERROR_BUF_SZ,
-		"Swap directory %s is not a directory.", path);
-	    fatal(tmp_error_buf);
+	    fatalf("Swap directory %s is not a directory.", path);
 	}
     } else if (0 == mkdir(path, 0755)) {
 	debug(20, should_exist ? 1 : 3) ("%s created\n", path);
 	created = 1;
     } else {
-	snprintf(tmp_error_buf, ERROR_BUF_SZ,
-	    "Failed to make swap directory %s: %s",
+	fatalf("Failed to make swap directory %s: %s",
 	    path, xstrerror());
-	fatal(tmp_error_buf);
     }
     return created;
 }
