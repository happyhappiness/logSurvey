 		else
 			die("You have not concluded your merge (MERGE_HEAD exists).");
 	}
+	if (file_exists(git_path("CHERRY_PICK_HEAD"))) {
+		if (advice_resolve_conflict)
+			die("You have not concluded your cherry-pick (CHERRY_PICK_HEAD exists).\n"
+			    "Please, commit your changes before you can merge.");
+		else
+			die("You have not concluded your cherry-pick (CHERRY_PICK_HEAD exists).");
+	}
 	resolve_undo_clear();
 
 	if (verbosity < 0)
