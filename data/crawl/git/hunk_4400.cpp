 	if (read_cache_unmerged()) {
 		die_resolve_conflict(me);
 	} else {
-		if (advice_commit_before_merge)
-			die("Your local changes would be overwritten by %s.\n"
-			    "Please, commit your changes or stash them to proceed.", me);
-		else
-			die("Your local changes would be overwritten by %s.\n", me);
+		if (advice_commit_before_merge) {
+			if (action == REVERT)
+				die(_("Your local changes would be overwritten by revert.\n"
+					  "Please, commit your changes or stash them to proceed."));
+			else
+				die(_("Your local changes would be overwritten by cherry-pick.\n"
+					  "Please, commit your changes or stash them to proceed."));
+		} else {
+			if (action == REVERT)
+				die(_("Your local changes would be overwritten by revert.\n"));
+			else
+				die(_("Your local changes would be overwritten by cherry-pick.\n"));
+		}
 	}
 }
 
