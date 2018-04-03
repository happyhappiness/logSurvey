 					       "git diff header lacks filename information when removing "
 					       "%d leading pathname components (line %d)",
 					       state_p_value),
-					    state_p_value, linenr);
+					    state_p_value, state_linenr);
 				patch->old_name = xstrdup(patch->def_name);
 				patch->new_name = xstrdup(patch->def_name);
 			}
 			if (!patch->is_delete && !patch->new_name)
 				die("git diff header lacks filename information "
-				    "(line %d)", linenr);
+				    "(line %d)", state_linenr);
 			patch->is_toplevel_relative = 1;
 			*hdrsize = git_hdr_len;
 			return offset;
