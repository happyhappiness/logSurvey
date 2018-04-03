 		if (only_include_assumed)
 			fprintf(fp, "# %s\n", only_include_assumed);
 
-		author_ident = xstrdup(fmt_name(author_name, author_email));
-		committer_ident = fmt_name(getenv("GIT_COMMITTER_NAME"),
-					   getenv("GIT_COMMITTER_EMAIL"));
-		if (strcmp(author_ident, committer_ident))
+		ai_tmp = cut_ident_timestamp_part(author_ident->buf);
+		ci_tmp = cut_ident_timestamp_part(committer_ident.buf);
+		if (strcmp(author_ident->buf, committer_ident.buf))
 			fprintf(fp,
 				"%s"
 				"# Author:    %s\n",
 				ident_shown++ ? "" : "#\n",
-				author_ident);
-		free(author_ident);
+				author_ident->buf);
 
 		if (!user_ident_sufficiently_given())
 			fprintf(fp,
 				"%s"
 				"# Committer: %s\n",
 				ident_shown++ ? "" : "#\n",
-				committer_ident);
+				committer_ident.buf);
 
 		if (ident_shown)
 			fprintf(fp, "#\n");
