 	 * make it another option?  For now suppress them.
 	 */
 	if (opt->count && count)
-		printf("%s:%u\n", name, count);
+		printf("%s%c%u\n", name,
+		       opt->null_following_name ? '\0' : ':', count);
 	return !!last_hit;
 }
 
