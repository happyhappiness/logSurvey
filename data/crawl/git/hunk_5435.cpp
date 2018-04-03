 		return assumed;
 	}
 
-	fprintf(stderr, "git: '%s' is not a git-command. See 'git --help'.\n", cmd);
+	fprintf(stderr, "git: '%s' is not a git command. See 'git --help'.\n", cmd);
 
 	if (SIMILAR_ENOUGH(best_similarity)) {
 		fprintf(stderr, "\nDid you mean %s?\n",