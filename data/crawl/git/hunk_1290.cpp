 		get_patch_ids(&rev, &ids);
 	}
 
-	if (!use_stdout)
-		realstdout = xfdopen(xdup(1), "w");
-
 	if (prepare_revision_walk(&rev))
 		die(_("revision walk setup failed"));
 	rev.boundary = 1;
