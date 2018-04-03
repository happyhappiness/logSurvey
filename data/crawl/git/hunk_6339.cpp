 	if (!oldname)
 		die("cannot rename the current branch while not on any.");
 
-	strbuf_branchname(&oldref, oldname);
-	strbuf_splice(&oldref, 0, 0, "refs/heads/", 11);
-	if (check_ref_format(oldref.buf))
+	if (strbuf_check_branch_ref(&oldref, oldname))
 		die("Invalid branch name: '%s'", oldname);
 
-	strbuf_branchname(&newref, newname);
-	strbuf_splice(&newref, 0, 0, "refs/heads/", 11);
-	if (check_ref_format(newref.buf))
+	if (strbuf_check_branch_ref(&newref, newname))
 		die("Invalid branch name: '%s'", newname);
 
 	if (resolve_ref(newref.buf, sha1, 1, NULL) && !force)
