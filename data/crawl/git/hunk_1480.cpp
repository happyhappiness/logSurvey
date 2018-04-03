 		printf("%s%06o %s %d\t",
 		       tag,
 		       ce->ce_mode,
-		       find_unique_abbrev(ce->sha1,abbrev),
+		       find_unique_abbrev(ce->oid.hash,abbrev),
 		       ce_stage(ce));
 	}
 	write_eolinfo(ce, ce->name);
