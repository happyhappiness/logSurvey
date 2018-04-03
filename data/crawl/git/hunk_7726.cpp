 	}
 }
 
-static void store_updated_refs(const char *url, struct ref *ref_map)
+static int store_updated_refs(const char *url, struct ref *ref_map)
 {
 	FILE *fp;
 	struct commit *commit;
 	int url_len, i, note_len, shown_url = 0;
 	char note[1024];
 	const char *what, *kind;
 	struct ref *rm;
+	char *filename = git_path("FETCH_HEAD");
 
-	fp = fopen(git_path("FETCH_HEAD"), "a");
+	fp = fopen(filename, "a");
+	if (!fp)
+		return error("cannot open %s: %s\n", filename, strerror(errno));
 	for (rm = ref_map; rm; rm = rm->next) {
 		struct ref *ref = NULL;
 
