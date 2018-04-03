 	if (!packed_ref_cache->lock)
 		die("internal error: packed refs not locked");
 	add_ref_entry(get_packed_ref_dir(packed_ref_cache),
-		create_ref_entry(refname, sha1, REF_ISPACKED, 1));
+		      create_ref_entry(refname, sha1, REF_ISPACKED, 1));
 }
 
 /*
  * Read the loose references from the namespace dirname into dir
  * (without recursing).  dirname must end with '/'.  dir must be the
  * directory entry corresponding to dirname.
  */
-static void read_loose_refs(const char *dirname, struct ref_dir *dir)
+void read_loose_refs(const char *dirname, struct ref_dir *dir)
 {
 	struct files_ref_store *refs = dir->ref_store;
 	DIR *d;
