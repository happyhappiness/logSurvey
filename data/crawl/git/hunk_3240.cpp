 	return 1;
 }
 
-static void report_refname_conflict(struct ref_entry *entry,
-				    const char *refname)
-{
-	error("'%s' exists; cannot create '%s'", entry->name, refname);
-}
-
 /*
  * Return true iff a reference named refname could be created without
  * conflicting with the name of an existing reference in dir.  If
