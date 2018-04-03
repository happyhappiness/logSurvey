 		die("shallow file was changed during fetch");
 }
 
+#define SEEN_ONLY 1
+#define VERBOSE   2
+
 struct write_shallow_data {
 	struct strbuf *out;
 	int use_pack_protocol;
 	int count;
+	unsigned flags;
 };
 
 static int write_one_shallow(const struct commit_graft *graft, void *cb_data)
