 	author = strstr(commit_buffer, "\nauthor ");
 	if (!author)
 		die ("Could not find author in commit %s",
-		     sha1_to_hex(commit->object.sha1));
+		     oid_to_hex(&commit->object.oid));
 	author++;
 	author_end = strchrnul(author, '\n');
 	committer = strstr(author_end, "\ncommitter ");
 	if (!committer)
 		die ("Could not find committer in commit %s",
-		     sha1_to_hex(commit->object.sha1));
+		     oid_to_hex(&commit->object.oid));
 	committer++;
 	committer_end = strchrnul(committer, '\n');
 	message = strstr(committer_end, "\n\n");
