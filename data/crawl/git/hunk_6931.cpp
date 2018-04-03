 		char index[PATH_MAX];
 		const char *env[2] = { index, NULL };
 		snprintf(index, sizeof(index), "GIT_INDEX_FILE=%s", index_file);
-		launch_editor(git_path(commit_editmsg), NULL, env);
+		if (launch_editor(git_path(commit_editmsg), NULL, env)) {
+			fprintf(stderr,
+			"Please supply the message using either -m or -F option.\n");
+			exit(1);
+		}
 	}
 
 	if (!no_verify &&
