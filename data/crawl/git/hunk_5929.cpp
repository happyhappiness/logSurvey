 			die("Not a git repository (or any of the parent directories): %s", DEFAULT_GIT_DIR_ENVIRONMENT);
 		}
 		if (chdir(".."))
-			die("Cannot change to %s/..: %s", cwd, strerror(errno));
+			die_errno("Cannot change to '%s/..'", cwd);
 	}
 
 	inside_git_dir = 0;
