 
 static void show_new(enum object_type type, unsigned char *sha1_new)
 {
-	fprintf(stderr, "  %s: %s\n", typename(type),
+	fprintf(stderr, "  %s: %s\n", type_name(type),
 		find_unique_abbrev(sha1_new, DEFAULT_ABBREV));
 }
 
