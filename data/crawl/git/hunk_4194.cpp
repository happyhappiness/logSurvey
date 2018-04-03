 	return data;
 }
 
-static void *load_sha1(const unsigned char *sha1, unsigned long *size,
-		       const char *name)
-{
-	enum object_type type;
-	void *data = lock_and_read_sha1_file(sha1, &type, size);
-
-	if (!data)
-		error(_("'%s': unable to read %s"), name, sha1_to_hex(sha1));
-
-	return data;
-}
-
 static int grep_sha1(struct grep_opt *opt, const unsigned char *sha1,
 		     const char *filename, int tree_name_len)
 {
 	struct strbuf pathbuf = STRBUF_INIT;
-	char *name;
 
 	if (opt->relative && opt->prefix_length) {
 		quote_path_relative(filename + tree_name_len, -1, &pathbuf,
