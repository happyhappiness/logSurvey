 
 	commit = lookup_commit(sha1);
 	if (!commit)
-		die("couldn't look up newly created commit\n");
+		die("couldn't look up newly created commit");
 	if (!commit || parse_commit(commit))
 		die("could not parse newly created commit");
 
