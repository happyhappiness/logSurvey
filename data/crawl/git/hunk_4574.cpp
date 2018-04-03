 		 * add/rm <file>', just 'git commit'.
 		 */
 		if (advice_resolve_conflict)
-			die("You have not concluded your merge (MERGE_HEAD exists).\n"
-			    "Please, commit your changes before you can merge.");
+			die(_("You have not concluded your merge (MERGE_HEAD exists).\n"
+				  "Please, commit your changes before you can merge."));
 		else
-			die("You have not concluded your merge (MERGE_HEAD exists).");
+			die(_("You have not concluded your merge (MERGE_HEAD exists)."));
 	}
 	resolve_undo_clear();
 
