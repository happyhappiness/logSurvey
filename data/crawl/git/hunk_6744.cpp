 	}
 
 	if (!state.quiet) {
-		fprintf(stderr, "git-checkout-index: %s ", name);
+		fprintf(stderr, "git checkout-index: %s ", name);
 		if (!has_same_name)
 			fprintf(stderr, "is not in the cache");
 		else if (checkout_stage)
