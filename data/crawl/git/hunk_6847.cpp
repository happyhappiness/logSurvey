 				continue;
 			if (opts->force) {
 				warning("path '%s' is unmerged", ce->name);
+			} else if (stage) {
+				errs |= check_stage(stage, ce, pos);
 			} else {
 				errs = 1;
 				error("path '%s' is unmerged", ce->name);
