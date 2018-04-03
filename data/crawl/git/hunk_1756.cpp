 		if (!one->sha1_valid) {
 			struct stat st;
 			if (one->is_stdin) {
-				hashclr(one->sha1);
+				oidclr(&one->oid);
 				return;
 			}
 			if (lstat(one->path, &st) < 0)
 				die_errno("stat '%s'", one->path);
-			if (index_path(one->sha1, one->path, &st, 0))
+			if (index_path(one->oid.hash, one->path, &st, 0))
 				die("cannot hash %s", one->path);
 		}
 	}
 	else
-		hashclr(one->sha1);
+		oidclr(&one->oid);
 }
 
 static void strip_prefix(int prefix_length, const char **namep, const char **otherp)
