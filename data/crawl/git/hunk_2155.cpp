 		list.entry[list.nr].is_submodule = S_ISGITLINK(ce->ce_mode);
 		if (list.entry[list.nr++].is_submodule &&
 		    !is_staging_gitmodules_ok())
-			die (_("Please, stage your changes to .gitmodules or stash them to proceed"));
+			die (_("Please stage your changes to .gitmodules or stash them to proceed"));
 	}
 
 	if (pathspec.nr) {