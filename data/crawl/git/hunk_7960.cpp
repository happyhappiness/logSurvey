 		else
 			sha1_ptr = sha1;
 
-		printf("%06o %s	",patch->old_mode, sha1_to_hex(sha1_ptr));
-		if (line_termination && quote_c_style(name, NULL, NULL, 0))
-			quote_c_style(name, NULL, stdout, 0);
-		else
-			fputs(name, stdout);
-		putchar(line_termination);
+		ce = make_cache_entry(patch->old_mode, sha1_ptr, name, 0, 0);
+		if (add_index_entry(&result, ce, ADD_CACHE_OK_TO_ADD))
+			die ("Could not add %s to temporary index", name);
 	}
+
+	fd = open(filename, O_WRONLY | O_CREAT, 0666);
+	if (fd < 0 || write_index(&result, fd) || close(fd))
+		die ("Could not write temporary index to %s", filename);
+
+	discard_index(&result);
 }
 
 static void stat_patch_list(struct patch *patch)
