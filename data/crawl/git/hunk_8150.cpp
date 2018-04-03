 	alloc = 0;
 	buf = NULL;
 	if (cached) {
-		if (ce) {
-			enum object_type type;
-			buf = read_sha1_file(ce->sha1, &type, &size);
-			if (!buf)
+		if (read_file_or_gitlink(ce, &buf, &size))
+			return error("read of %s failed", patch->old_name);
+		alloc = size;
+	} else if (patch->old_name) {
+		if (S_ISGITLINK(patch->old_mode)) {
+			if (ce)
+				read_file_or_gitlink(ce, &buf, &size);
+			else {
+				/*
+				 * There is no way to apply subproject
+				 * patch without looking at the index.
+				 */
+				patch->fragments = NULL;
+				size = 0;
+			}
+		}
+		else {
+			size = xsize_t(st->st_size);
+			alloc = size + 8192;
+			buf = xmalloc(alloc);
+			if (read_old_data(st, patch->old_name,
+					  &buf, &alloc, &size))
 				return error("read of %s failed",
 					     patch->old_name);
-			alloc = size;
 		}
 	}
-	else if (patch->old_name) {
-		size = xsize_t(st->st_size);
-		alloc = size + 8192;
-		buf = xmalloc(alloc);
-		if (read_old_data(st, patch->old_name, &buf, &alloc, &size))
-			return error("read of %s failed", patch->old_name);
-	}
 
 	desc.size = size;
 	desc.alloc = alloc;
