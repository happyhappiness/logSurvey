 
 	refs = (struct files_ref_store *)ref_store;
 
-	if (!submodule_allowed)
-		files_assert_main_repository(refs, caller);
+	if ((refs->store_flags & required_flags) != required_flags)
+		die("BUG: operation %s requires abilities 0x%x, but only have 0x%x",
+		    caller, required_flags, refs->store_flags);
 
 	return refs;
 }
