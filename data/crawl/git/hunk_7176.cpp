 	 */
 
 	if (last_dot == NULL) {
-		fprintf(stderr, "key does not contain a section: %s\n", key);
+		error("key does not contain a section: %s", key);
 		ret = 2;
 		goto out_free;
 	}
