 
 	suspect->commit->object.flags |= METAINFO_SHOWN;
 	get_commit_info(suspect->commit, &ci, 1);
-	printf("author %s\n", ci.author);
-	printf("author-mail %s\n", ci.author_mail);
+	printf("author %s\n", ci.author.buf);
+	printf("author-mail %s\n", ci.author_mail.buf);
 	printf("author-time %lu\n", ci.author_time);
-	printf("author-tz %s\n", ci.author_tz);
-	printf("committer %s\n", ci.committer);
-	printf("committer-mail %s\n", ci.committer_mail);
+	printf("author-tz %s\n", ci.author_tz.buf);
+	printf("committer %s\n", ci.committer.buf);
+	printf("committer-mail %s\n", ci.committer_mail.buf);
 	printf("committer-time %lu\n", ci.committer_time);
-	printf("committer-tz %s\n", ci.committer_tz);
-	printf("summary %s\n", ci.summary);
+	printf("committer-tz %s\n", ci.committer_tz.buf);
+	printf("summary %s\n", ci.summary.buf);
 	if (suspect->commit->object.flags & UNINTERESTING)
 		printf("boundary\n");
 	if (suspect->previous) {
 		struct origin *prev = suspect->previous;
 		printf("previous %s ", sha1_to_hex(prev->commit->object.sha1));
 		write_name_quoted(prev->path, stdout, '\n');
 	}
+
+	commit_info_destroy(&ci);
+
 	return 1;
 }
 
