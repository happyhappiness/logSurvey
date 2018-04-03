 	    !(entry->flag & REF_ISPACKED))
 		return 0;
 
-	fprintf(cb->refs_file, "%s %s\n", sha1_to_hex(entry->u.value.sha1),
-		entry->name);
-
 	peel_status = peel_entry(entry, 1);
-	if (peel_status == PEEL_PEELED)
-		fprintf(cb->refs_file, "^%s\n", sha1_to_hex(entry->u.value.peeled));
-	else if (peel_status != PEEL_NON_TAG)
+	if (peel_status != PEEL_PEELED && peel_status != PEEL_NON_TAG)
 		die("internal error peeling reference %s (%s)",
 		    entry->name, sha1_to_hex(entry->u.value.sha1));
+	write_packed_entry(cb->fd, entry->name, entry->u.value.sha1,
+			   peel_status == PEEL_PEELED ?
+			   entry->u.value.peeled : NULL);
 
 	/* If the ref was already packed, there is no need to prune it. */
 	if ((cb->flags & PACK_REFS_PRUNE) && !(entry->flag & REF_ISPACKED)) {
