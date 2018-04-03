 		unsigned long size;
 
 		if (S_ISGITLINK(mode))
-			die("cannot read object %s '%s': It is a submodule!",
-			    sha1_to_hex(sha), path);
+			/*
+			 * We may later decide to recursively descend into
+			 * the submodule directory and update its index
+			 * and/or work tree, but we do not do that now.
+			 */
+			goto update_index;
 
 		buf = read_sha1_file(sha, &type, &size);
 		if (!buf)
