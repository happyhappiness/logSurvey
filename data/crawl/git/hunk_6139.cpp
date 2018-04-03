 	struct strbuf oldref = STRBUF_INIT, newref = STRBUF_INIT, logmsg = STRBUF_INIT;
 	unsigned char sha1[20];
 	struct strbuf oldsection = STRBUF_INIT, newsection = STRBUF_INIT;
+	int recovery = 0;
 
 	if (!oldname)
 		die("cannot rename the current branch while not on any.");
 
-	strbuf_addf(&oldref, "refs/heads/%s", oldname);
-
-	if (check_ref_format(oldref.buf))
-		die("Invalid branch name: %s", oldref.buf);
-
-	strbuf_addf(&newref, "refs/heads/%s", newname);
+	if (strbuf_check_branch_ref(&oldref, oldname)) {
+		/*
+		 * Bad name --- this could be an attempt to rename a
+		 * ref that we used to allow to be created by accident.
+		 */
+		if (resolve_ref(oldref.buf, sha1, 1, NULL))
+			recovery = 1;
+		else
+			die("Invalid branch name: '%s'", oldname);
+	}
 
-	if (check_ref_format(newref.buf))
-		die("Invalid branch name: %s", newref.buf);
+	if (strbuf_check_branch_ref(&newref, newname))
+		die("Invalid branch name: '%s'", newname);
 
 	if (resolve_ref(newref.buf, sha1, 1, NULL) && !force)
-		die("A branch named '%s' already exists.", newname);
+		die("A branch named '%s' already exists.", newref.buf + 11);
 
 	strbuf_addf(&logmsg, "Branch: renamed %s to %s",
 		 oldref.buf, newref.buf);
