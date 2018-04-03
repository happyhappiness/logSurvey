 	struct strbuf oldref = STRBUF_INIT, newref = STRBUF_INIT, logmsg = STRBUF_INIT;
 	unsigned char sha1[20];
 	struct strbuf oldsection = STRBUF_INIT, newsection = STRBUF_INIT;
+	int recovery = 0;
 
 	if (!oldname)
 		die("cannot rename the current branch while not on any.");
 
-	if (strbuf_check_branch_ref(&oldref, oldname))
-		die("Invalid branch name: '%s'", oldname);
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
 
 	if (strbuf_check_branch_ref(&newref, newname))
 		die("Invalid branch name: '%s'", newname);
