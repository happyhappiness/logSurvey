 	if ((st_mode ^ patch->old_mode) & S_IFMT)
 		return error("%s: wrong type", old_name);
 	if (st_mode != patch->old_mode)
-		fprintf(stderr, "warning: %s has type %o, expected %o\n",
+		warning("%s has type %o, expected %o",
 			old_name, st_mode, patch->old_mode);
 	if (!patch->new_mode && !patch->is_delete)
 		patch->new_mode = st_mode;
