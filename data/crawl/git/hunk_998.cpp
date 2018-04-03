 				return error(_("Cannot revert during a cherry-pick."));
 	}
 
-	if (res)
-		return error(_("Unusable instruction sheet: %s"), todo_file);
 	return 0;
 }
 