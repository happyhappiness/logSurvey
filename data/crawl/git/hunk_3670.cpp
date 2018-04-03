 	return (flags & (REF_ISSYMREF|REF_ISPACKED));
 }
 
-static int pack_one_ref(const char *refname, const unsigned char *sha1,
-			  int flags, void *cb_data)
+static int pack_one_ref(struct ref_entry *entry, void *cb_data)
 {
 	struct pack_refs_cb_data *cb = cb_data;
 	struct object *o;
 	int is_tag_ref;
 
-	/* Do not pack the symbolic refs */
-	if ((flags & REF_ISSYMREF))
+	/* Do not pack symbolic or broken refs: */
+	if ((entry->flag & REF_ISSYMREF) || !ref_resolves_to_object(entry))
 		return 0;
-	is_tag_ref = !prefixcmp(refname, "refs/tags/");
+	is_tag_ref = !prefixcmp(entry->name, "refs/tags/");
 
 	/* ALWAYS pack refs that were already packed or are tags */
-	if (!(cb->flags & PACK_REFS_ALL) && !is_tag_ref && !(flags & REF_ISPACKED))
+	if (!(cb->flags & PACK_REFS_ALL) && !is_tag_ref &&
+	    !(entry->flag & REF_ISPACKED))
 		return 0;
 
-	fprintf(cb->refs_file, "%s %s\n", sha1_to_hex(sha1), refname);
+	fprintf(cb->refs_file, "%s %s\n", sha1_to_hex(entry->u.value.sha1),
+		entry->name);
 
-	o = parse_object_or_die(sha1, refname);
+	o = parse_object_or_die(entry->u.value.sha1, entry->name);
 	if (o->type == OBJ_TAG) {
-		o = deref_tag(o, refname, 0);
+		o = deref_tag(o, entry->name, 0);
 		if (o)
 			fprintf(cb->refs_file, "^%s\n",
 				sha1_to_hex(o->sha1));
 	}
 
-	if ((cb->flags & PACK_REFS_PRUNE) && !do_not_prune(flags)) {
-		int namelen = strlen(refname) + 1;
+	if ((cb->flags & PACK_REFS_PRUNE) && !do_not_prune(entry->flag)) {
+		int namelen = strlen(entry->name) + 1;
 		struct ref_to_prune *n = xcalloc(1, sizeof(*n) + namelen);
-		hashcpy(n->sha1, sha1);
-		strcpy(n->name, refname);
+		hashcpy(n->sha1, entry->u.value.sha1);
+		strcpy(n->name, entry->name);
 		n->next = cb->ref_to_prune;
 		cb->ref_to_prune = n;
 	}
