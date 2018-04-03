 			return 0;
 		if (!state->force) {
 			if (!state->quiet)
-				fprintf(stderr, "git-checkout-index: %s already exists\n", path);
+				fprintf(stderr, "%s already exists, no checkout\n", path);
 			return -1;
 		}
 