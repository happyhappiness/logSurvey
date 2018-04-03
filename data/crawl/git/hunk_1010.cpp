 				patch->new_name = xstrdup(patch->def_name);
 			}
 			if (!patch->is_delete && !patch->new_name) {
-				error("git diff header lacks filename information "
-					     "(line %d)", state->linenr);
+				error(_("git diff header lacks filename information "
+					     "(line %d)"), state->linenr);
 				return -128;
 			}
 			patch->is_toplevel_relative = 1;
