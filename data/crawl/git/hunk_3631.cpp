 static int get_sha1_basic(const char *str, int len, unsigned char *sha1)
 {
 	static const char *warn_msg = "refname '%.*s' is ambiguous.";
+	static const char *object_name_msg = N_(
+	"Git normally never creates a ref that ends with 40 hex characters\n"
+	"because it will be ignored when you just specify 40-hex. These refs\n"
+	"may be created by mistake. For example,\n"
+	"\n"
+	"  git checkout -b $br $(git rev-parse ...)\n"
+	"\n"
+	"where \"$br\" is somehow empty and a 40-hex ref is created. Please\n"
+	"examine these refs and maybe delete them. Turn this message off by\n"
+	"running \"git config advice.object_name_warning false\"");
+	unsigned char tmp_sha1[20];
 	char *real_ref = NULL;
 	int refs_found = 0;
 	int at, reflog_len;
 
-	if (len == 40 && !get_sha1_hex(str, sha1))
+	if (len == 40 && !get_sha1_hex(str, sha1)) {
+		refs_found = dwim_ref(str, len, tmp_sha1, &real_ref);
+		if (refs_found > 0 && warn_ambiguous_refs) {
+			warning(warn_msg, len, str);
+			if (advice_object_name_warning)
+				fprintf(stderr, "%s\n", _(object_name_msg));
+		}
+		free(real_ref);
 		return 0;
+	}
 
 	/* basic@{time or number or -number} format to query ref-log */
 	reflog_len = at = 0;
