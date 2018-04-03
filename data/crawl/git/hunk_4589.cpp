 		setup_early_output(rev);
 
 	if (prepare_revision_walk(rev))
-		die("revision walk setup failed");
+		die(_("revision walk setup failed"));
 
 	if (rev->early_output)
 		finish_early_output(rev);
