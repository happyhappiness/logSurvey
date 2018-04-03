 	struct ref *ref = find_ref_by_name_abbrev(remote_refs, name);
 
 	if (!ref)
-		die("Couldn't find remote ref %s\n", name);
+		return NULL;
 
 	return copy_ref(ref);
 }
