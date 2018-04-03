 	return result;
 }
 
-static int is_refname_available(const char *ref, const char *oldref,
+static int is_refname_available(const char *refname, const char *oldrefname,
 				struct ref_array *array, int quiet)
 {
-	int i, namlen = strlen(ref); /* e.g. 'foo/bar' */
+	int i, namlen = strlen(refname); /* e.g. 'foo/bar' */
 	for (i = 0; i < array->nr; i++ ) {
 		struct ref_entry *entry = array->refs[i];
 		/* entry->name could be 'foo' or 'foo/bar/baz' */
-		if (!oldref || strcmp(oldref, entry->name)) {
+		if (!oldrefname || strcmp(oldrefname, entry->name)) {
 			int len = strlen(entry->name);
 			int cmplen = (namlen < len) ? namlen : len;
-			const char *lead = (namlen < len) ? entry->name : ref;
-			if (!strncmp(ref, entry->name, cmplen) &&
+			const char *lead = (namlen < len) ? entry->name : refname;
+			if (!strncmp(refname, entry->name, cmplen) &&
 			    lead[cmplen] == '/') {
 				if (!quiet)
 					error("'%s' exists; cannot create '%s'",
-					      entry->name, ref);
+					      entry->name, refname);
 				return 0;
 			}
 		}
