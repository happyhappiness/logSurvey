 		die("BUG: unhandled setup_git_directory_1() result");
 	}
 
-	/*
-	 * NEEDSWORK: This was a hack in order to get ls-files and grep to have
-	 * properly formated output when recursing submodules.  Once ls-files
-	 * and grep have been changed to perform this recursing in-process this
-	 * needs to be removed.
-	 */
-	env_prefix = getenv(GIT_TOPLEVEL_PREFIX_ENVIRONMENT);
-	if (env_prefix)
-		prefix = env_prefix;
-
 	if (prefix)
 		setenv(GIT_PREFIX_ENVIRONMENT, prefix, 1);
 	else