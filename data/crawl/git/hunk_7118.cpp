 	const unsigned char *index_base;
 	SHA_CTX ctx;
 	unsigned char sha1[20];
-	int ret;
+	int err = 0;
+	struct pack_window *w_curs = NULL;
 
 	if (open_pack_index(p))
 		return error("packfile %s index not opened", p->pack_name);
 	index_size = p->index_size;
 	index_base = p->index_data;
 
-	ret = 0;
 	/* Verify SHA1 sum of the index file */
 	SHA1_Init(&ctx);
 	SHA1_Update(&ctx, index_base, (unsigned int)(index_size - 20));
 	SHA1_Final(sha1, &ctx);
 	if (hashcmp(sha1, index_base + index_size - 20))
-		ret = error("Packfile index for %s SHA1 mismatch",
+		err = error("Packfile index for %s SHA1 mismatch",
 			    p->pack_name);
 
-	if (!ret) {
-		/* Verify pack file */
-		struct pack_window *w_curs = NULL;
-		ret = verify_packfile(p, &w_curs);
-		unuse_pack(&w_curs);
-	}
+	/* Verify pack file */
+	err |= verify_packfile(p, &w_curs);
+	unuse_pack(&w_curs);
 
 	if (verbose) {
-		if (ret)
+		if (err)
 			printf("%s: bad\n", p->pack_name);
 		else {
 			show_pack_info(p);
 			printf("%s: ok\n", p->pack_name);
 		}
 	}
 
-	return ret;
+	return err;
 }