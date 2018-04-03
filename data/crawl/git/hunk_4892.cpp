 	return 1;
 }
 
+static char *cut_ident_timestamp_part(char *string)
+{
+	char *ket = strrchr(string, '>');
+	if (!ket || ket[1] != ' ')
+		die("Malformed ident string: '%s'", string);
+	*++ket = '\0';
+	return ket;
+}
+
 static int prepare_to_commit(const char *index_file, const char *prefix,
-			     struct wt_status *s)
+			     struct wt_status *s,
+			     struct strbuf *author_ident)
 {
 	struct stat statbuf;
+	struct strbuf committer_ident = STRBUF_INIT;
 	int commitable, saved_color_setting;
 	struct strbuf sb = STRBUF_INIT;
 	char *buffer;
