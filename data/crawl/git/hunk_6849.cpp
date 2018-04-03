 		if (pathspec_match(pathspec, NULL, ce->name, 0)) {
 			if (!ce_stage(ce))
 				continue;
-			errs = 1;
-			error("path '%s' is unmerged", ce->name);
+			if (opts->force) {
+				warning("path '%s' is unmerged", ce->name);
+			} else {
+				errs = 1;
+				error("path '%s' is unmerged", ce->name);
+			}
 			pos = skip_same_name(ce, pos) - 1;
 		}
 	}
