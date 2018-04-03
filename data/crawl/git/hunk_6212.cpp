 	}
 
 	if (!path) {
-		logerror("'%s': unable to chdir or not a git archive", dir);
+		logerror("'%s' does not appear to be a git repository", dir);
 		return NULL;
 	}
 
