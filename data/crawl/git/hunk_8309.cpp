 			die("Not a git repository");
 		}
 		setenv(GIT_DIR_ENVIRONMENT, cwd, 1);
+		gitdirenv = getenv(GIT_DIR_ENVIRONMENT);
+		if (!gitdirenv)
+			die("getenv after setenv failed");
 	}
 
 	if (PATH_MAX - 40 < strlen(gitdirenv)) {
