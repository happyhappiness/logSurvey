 				return;
 			}
 			if (lstat(one->path, &st) < 0)
-				die("stat %s", one->path);
+				die_errno("stat '%s'", one->path);
 			if (index_path(one->sha1, one->path, &st, 0))
 				die("cannot hash %s", one->path);
 		}
