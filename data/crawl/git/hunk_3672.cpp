 	/* Do not pack the symbolic refs */
 	if ((flags & REF_ISSYMREF))
 		return 0;
-	is_tag_ref = !prefixcmp(path, "refs/tags/");
+	is_tag_ref = !prefixcmp(refname, "refs/tags/");
 
 	/* ALWAYS pack refs that were already packed or are tags */
 	if (!(cb->flags & PACK_REFS_ALL) && !is_tag_ref && !(flags & REF_ISPACKED))
 		return 0;
 
-	fprintf(cb->refs_file, "%s %s\n", sha1_to_hex(sha1), path);
+	fprintf(cb->refs_file, "%s %s\n", sha1_to_hex(sha1), refname);
 
-	o = parse_object_or_die(sha1, path);
+	o = parse_object_or_die(sha1, refname);
 	if (o->type == OBJ_TAG) {
-		o = deref_tag(o, path, 0);
+		o = deref_tag(o, refname, 0);
 		if (o)
 			fprintf(cb->refs_file, "^%s\n",
 				sha1_to_hex(o->sha1));
 	}
 
 	if ((cb->flags & PACK_REFS_PRUNE) && !do_not_prune(flags)) {
-		int namelen = strlen(path) + 1;
+		int namelen = strlen(refname) + 1;
 		struct ref_to_prune *n = xcalloc(1, sizeof(*n) + namelen);
 		hashcpy(n->sha1, sha1);
-		strcpy(n->name, path);
+		strcpy(n->name, refname);
 		n->next = cb->ref_to_prune;
 		cb->ref_to_prune = n;
 	}