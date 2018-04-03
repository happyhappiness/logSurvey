 				continue;
 			}
 			if (!removed)
-				die("git rm: %s: %s", path, strerror(errno));
+				die_errno("git rm: '%s'", path);
 		}
 	}
 
