 		 */
 		exit_if_skipped_commits(tried, NULL);
 
-		printf("%s was both good and bad\n",
-		       oid_to_hex(current_bad_oid));
+		printf("%s was both %s and %s\n",
+		       oid_to_hex(current_bad_oid),
+		       term_good,
+		       term_bad);
 		exit(1);
 	}
 
