 				continue; /* Yup, this one exists unmerged */
 		}
 
-		/*
-		 * we might have removed this as part of earlier
-		 * recursive directory removal, so lstat() here could
-		 * fail with ENOENT.
-		 */
 		if (lstat(ent->name, &st))
-			continue;
+			die_errno("Cannot lstat '%s'", ent->name);
 
 		if (pathspec) {
 			memset(seen, 0, argc > 0 ? argc : 1);
