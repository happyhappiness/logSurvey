 
 int verify_pack(struct packed_git *p, int verbose)
 {
-	off_t index_size = p->index_size;
-	const unsigned char *index_base = p->index_data;
+	off_t index_size;
+	const unsigned char *index_base;
 	SHA_CTX ctx;
 	unsigned char sha1[20];
 	int ret;
 
+	if (open_pack_index(p))
+		return error("packfile %s index not opened", p->pack_name);
+	index_size = p->index_size;
+	index_base = p->index_data;
+
 	ret = 0;
 	/* Verify SHA1 sum of the index file */
 	SHA1_Init(&ctx);
