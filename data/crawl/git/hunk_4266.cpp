 	return line;
 }
 
-static void add_ref(const char *name, const unsigned char *sha1,
+static void add_ref(const char *refname, const unsigned char *sha1,
 		    int flag, int check_name, struct ref_array *refs,
 		    struct ref_entry **new_entry)
 {
 	int len;
 	struct ref_entry *entry;
 
 	/* Allocate it and add it in.. */
-	len = strlen(name) + 1;
+	len = strlen(refname) + 1;
 	entry = xmalloc(sizeof(struct ref_entry) + len);
 	hashcpy(entry->sha1, sha1);
 	hashclr(entry->peeled);
 	if (check_name &&
-	    check_refname_format(name, REFNAME_ALLOW_ONELEVEL|REFNAME_DOT_COMPONENT))
-		die("Reference has invalid format: '%s'", name);
-	memcpy(entry->name, name, len);
+	    check_refname_format(refname, REFNAME_ALLOW_ONELEVEL|REFNAME_DOT_COMPONENT))
+		die("Reference has invalid format: '%s'", refname);
+	memcpy(entry->name, refname, len);
 	entry->flag = flag;
 	if (new_entry)
 		*new_entry = entry;
