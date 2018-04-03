 }
 
 struct ref_entry *create_ref_entry(const char *refname,
-				   const struct object_id *oid, int flag,
-				   int check_name)
+				   const struct object_id *oid, int flag)
 {
 	struct ref_entry *ref;
 
-	if (check_name &&
-	    check_refname_format(refname, REFNAME_ALLOW_ONELEVEL))
-		die("Reference has invalid format: '%s'", refname);
 	FLEX_ALLOC_STR(ref, name, refname);
 	oidcpy(&ref->u.value.oid, oid);
 	oidclr(&ref->u.value.peeled);
