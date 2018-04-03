 # define GLOB_NOMAGIC	 (1 << 11)/* If no magic chars, return the pattern.  */
 # define GLOB_TILDE	 (1 << 12)/* Expand ~user and ~ to home directories. */
 # define GLOB_ONLYDIR	 (1 << 13)/* Match only directories.  */
+# define GLOB_TILDE_CHECK (1 << 14)/* Like GLOB_TILDE but return an error
+				      if the user name is not available.  */
 # define __GLOB_FLAGS	(GLOB_ERR|GLOB_MARK|GLOB_NOSORT|GLOB_DOOFFS| \
 			 GLOB_NOESCAPE|GLOB_NOCHECK|GLOB_APPEND|     \
 			 GLOB_PERIOD|GLOB_ALTDIRFUNC|GLOB_BRACE|     \
-			 GLOB_NOMAGIC|GLOB_TILDE|GLOB_ONLYDIR)
+			 GLOB_NOMAGIC|GLOB_TILDE|GLOB_ONLYDIR|GLOB_TILDE_CHECK)
 #else
 # define __GLOB_FLAGS	(GLOB_ERR|GLOB_MARK|GLOB_NOSORT|GLOB_DOOFFS| \
 			 GLOB_NOESCAPE|GLOB_NOCHECK|GLOB_APPEND|     \
