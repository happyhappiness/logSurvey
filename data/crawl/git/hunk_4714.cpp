 	int recovery = 0;
 
 	if (!oldname)
-		die("cannot rename the current branch while not on any.");
+		die(_("cannot rename the current branch while not on any."));
 
 	if (strbuf_check_branch_ref(&oldref, oldname)) {
 		/*
