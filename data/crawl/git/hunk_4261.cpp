 
 /*
  * Called by resolve_gitlink_ref_recursive() after it failed to read
- * from "name", which is "module/.git/<refname>". Find <refname> in
- * the packed-refs file for the submodule.
+ * from the loose refs in ref_cache refs. Find <refname> in the
+ * packed-refs file for the submodule.
  */
-static int resolve_gitlink_packed_ref(char *name, int pathlen,
+static int resolve_gitlink_packed_ref(struct ref_cache *refs,
 				      const char *refname, unsigned char *sha1)
 {
-	int retval = -1;
 	struct ref_entry *ref;
-	struct ref_array *array;
+	struct ref_array *array = get_packed_refs(refs);
 
-	/* being defensive: resolve_gitlink_ref() did this for us */
-	if (pathlen < 6 || memcmp(name + pathlen - 6, "/.git/", 6))
-		die("Oops");
-	name[pathlen - 6] = '\0'; /* make it path to the submodule */
-	array = get_packed_refs(get_ref_cache(name));
 	ref = search_ref_array(array, refname);
-	if (ref != NULL) {
-		memcpy(sha1, ref->sha1, 20);
-		retval = 0;
-	}
-	return retval;
+	if (ref == NULL)
+		return -1;
+
+	memcpy(sha1, ref->sha1, 20);
+	return 0;
 }
 
-static int resolve_gitlink_ref_recursive(char *name, int pathlen,
+static int resolve_gitlink_ref_recursive(struct ref_cache *refs,
+					 char *name, int pathlen,
 					 const char *refname, unsigned char *sha1,
 					 int recursion)
 {
