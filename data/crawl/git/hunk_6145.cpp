 
 	if (!old.commit && !opts->force) {
 		if (!opts->quiet) {
-			fprintf(stderr, "warning: You appear to be on a branch yet to be born.\n");
-			fprintf(stderr, "warning: Forcing checkout of %s.\n", new->name);
+			warning("You appear to be on a branch yet to be born.");
+			warning("Forcing checkout of %s.", new->name);
 		}
 		opts->force = 1;
 	}
