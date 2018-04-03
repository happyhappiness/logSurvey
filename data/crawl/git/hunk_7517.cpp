 	return git_status_config(k, v);
 }
 
-static int is_a_merge(const unsigned char *sha1)
-{
-	struct commit *commit = lookup_commit(sha1);
-	if (!commit || parse_commit(commit))
-		die("could not parse HEAD commit");
-	return !!(commit->parents && commit->parents->next);
-}
-
 static const char commit_utf8_warn[] =
 "Warning: commit message does not conform to UTF-8.\n"
 "You may want to amend it after fixing the message, or set the config\n"
