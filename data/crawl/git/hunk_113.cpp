 	index_base = p->index_data;
 
 	/* Verify SHA1 sum of the index file */
-	git_SHA1_Init(&ctx);
-	git_SHA1_Update(&ctx, index_base, (unsigned int)(index_size - 20));
-	git_SHA1_Final(sha1, &ctx);
-	if (hashcmp(sha1, index_base + index_size - 20))
-		err = error("Packfile index for %s SHA1 mismatch",
+	the_hash_algo->init_fn(&ctx);
+	the_hash_algo->update_fn(&ctx, index_base, (unsigned int)(index_size - the_hash_algo->rawsz));
+	the_hash_algo->final_fn(hash, &ctx);
+	if (hashcmp(hash, index_base + index_size - the_hash_algo->rawsz))
+		err = error("Packfile index for %s hash mismatch",
 			    p->pack_name);
 	return err;
 }