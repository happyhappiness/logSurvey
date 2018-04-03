 			if (!ce_stage(ce))
 				continue;
 			if (opts->force) {
-				warning("path '%s' is unmerged", ce->name);
+				warning(_("path '%s' is unmerged"), ce->name);
 			} else if (stage) {
 				errs |= check_stage(stage, ce, pos);
 			} else if (opts->merge) {
 				errs |= check_all_stages(ce, pos);
 			} else {
 				errs = 1;
-				error("path '%s' is unmerged", ce->name);
+				error(_("path '%s' is unmerged"), ce->name);
 			}
 			pos = skip_same_name(ce, pos) - 1;
 		}
