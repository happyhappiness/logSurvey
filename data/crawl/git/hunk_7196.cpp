 		if (only_include_assumed)
 			fprintf(fp, "# %s\n", only_include_assumed);
 
+		author_ident = xstrdup(fmt_name(author_name, author_email));
+		committer_ident = fmt_name(getenv("GIT_COMMITTER_NAME"),
+					   getenv("GIT_COMMITTER_EMAIL"));
+		if (strcmp(author_ident, committer_ident))
+			fprintf(fp,
+				"#\n"
+				"# Author:    %s\n"
+				"#\n",
+				author_ident);
+		free(author_ident);
+
 		saved_color_setting = wt_status_use_color;
 		wt_status_use_color = 0;
 		commitable = run_status(fp, index_file, prefix, 1);
