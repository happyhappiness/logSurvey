 	return get_packed_ref_dir(get_packed_ref_cache(refs));
 }
 
-/*
- * Add or overwrite a reference in the in-memory packed reference
- * cache. This may only be called while the packed-refs file is locked
- * (see packed_refs_lock()). To actually write the packed-refs file,
- * call commit_packed_refs().
- */
-void add_packed_ref(struct ref_store *ref_store,
-		    const char *refname, const struct object_id *oid)
-{
-	struct packed_ref_store *refs =
-		packed_downcast(ref_store, REF_STORE_WRITE,
-				"add_packed_ref");
-	struct ref_dir *packed_refs;
-	struct ref_entry *packed_entry;
-
-	if (!is_lock_file_locked(&refs->lock))
-		die("BUG: packed refs not locked");
-
-	if (check_refname_format(refname, REFNAME_ALLOW_ONELEVEL))
-		die("Reference has invalid format: '%s'", refname);
-
-	packed_refs = get_packed_refs(refs);
-	packed_entry = find_ref_entry(packed_refs, refname);
-	if (packed_entry) {
-		/* Overwrite the existing entry: */
-		oidcpy(&packed_entry->u.value.oid, oid);
-		packed_entry->flag = REF_ISPACKED;
-		oidclr(&packed_entry->u.value.peeled);
-	} else {
-		packed_entry = create_ref_entry(refname, oid, REF_ISPACKED);
-		add_ref_entry(packed_refs, packed_entry);
-	}
-}
-
 /*
  * Return the ref_entry for the given refname from the packed
  * references.  If it does not exist, return NULL.
