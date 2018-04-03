 		return;
 
 	/* Show the base commit */
-	fprintf(file, "base-commit: %s\n", oid_to_hex(&bases->base_commit));
+	fprintf(file, "\nbase-commit: %s\n", oid_to_hex(&bases->base_commit));
 
 	/* Show the prerequisite patches */
 	for (i = bases->nr_patch_id - 1; i >= 0; i--)
