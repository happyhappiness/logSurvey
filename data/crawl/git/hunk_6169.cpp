 
 	if (repository_format_version &&
 	    repository_format_version != GIT_REPO_VERSION) {
-		fprintf(stderr, "warning: not copying templates of "
-			"a wrong format version %d from '%s'\n",
+		warning("not copying templates of "
+			"a wrong format version %d from '%s'",
 			repository_format_version,
 			template_dir);
 		closedir(dir);
