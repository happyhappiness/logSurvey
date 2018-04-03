 	} else {
 		printf("%s%06o %s %d\t",
 		       tag,
-		       ntohl(ce->ce_mode),
+		       ce->ce_mode,
 		       abbrev ? find_unique_abbrev(ce->sha1,abbrev)
 				: sha1_to_hex(ce->sha1),
 		       ce_stage(ce));
