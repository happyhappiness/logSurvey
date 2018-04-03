 		   *author ? author : "nobody",
 		   *author ? author : "nobody",
 		   *uuid ? uuid : "local", timestamp);
-	printf("data %"PRIu32"\n%s%s\n",
-		   (uint32_t) (strlen(log) + strlen(gitsvnline)),
-		   log, gitsvnline);
+	printf("data %"PRIuMAX"\n", log->len + strlen(gitsvnline));
+	fwrite(log->buf, log->len, 1, stdout);
+	printf("%s\n", gitsvnline);
 	if (!first_commit_done) {
 		if (revision > 1)
 			printf("from refs/heads/master^0\n");
