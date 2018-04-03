 		if (!head_rev)
 			die("Couldn't look up commit object for HEAD");
 	}
-	for (i = 0; i < argc; i++) {
-		if (kinds == REF_LOCAL_BRANCH && !strcmp(head, argv[i])) {
+	for (i = 0; i < argc; i++, strbuf_release(&bname)) {
+		int len = strlen(argv[i]);
+
+		if (interpret_nth_last_branch(argv[i], &bname) != len)
+			strbuf_add(&bname, argv[i], len);
+
+		if (kinds == REF_LOCAL_BRANCH && !strcmp(head, bname.buf)) {
 			error("Cannot delete the branch '%s' "
-				"which you are currently on.", argv[i]);
+			      "which you are currently on.", bname.buf);
 			ret = 1;
 			continue;
 		}
 
 		free(name);
 
-		name = xstrdup(mkpath(fmt, argv[i]));
+		name = xstrdup(mkpath(fmt, bname.buf));
 		if (!resolve_ref(name, sha1, 1, NULL)) {
 			error("%sbranch '%s' not found.",
-					remote, argv[i]);
+					remote, bname.buf);
 			ret = 1;
 			continue;
 		}
