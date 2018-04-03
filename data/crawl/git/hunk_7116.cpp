 	 */
 
 	SHA1_Init(&ctx);
-	while (offset < pack_sig) {
+	while (offset < pack_sig_ofs) {
 		unsigned int remaining;
 		unsigned char *in = use_pack(p, w_curs, offset, &remaining);
 		offset += remaining;
-		if (offset > pack_sig)
-			remaining -= (unsigned int)(offset - pack_sig);
+		if (offset > pack_sig_ofs)
+			remaining -= (unsigned int)(offset - pack_sig_ofs);
 		SHA1_Update(&ctx, in, remaining);
 	}
 	SHA1_Final(sha1, &ctx);
-	if (hashcmp(sha1, use_pack(p, w_curs, pack_sig, NULL)))
-		return error("Packfile %s SHA1 mismatch with itself",
-			     p->pack_name);
-	if (hashcmp(sha1, index_base + index_size - 40))
-		return error("Packfile %s SHA1 mismatch with idx",
-			     p->pack_name);
+	pack_sig = use_pack(p, w_curs, pack_sig_ofs, NULL);
+	if (hashcmp(sha1, pack_sig))
+		err = error("%s SHA1 checksum mismatch",
+			    p->pack_name);
+	if (hashcmp(index_base + index_size - 40, pack_sig))
+		err = error("%s SHA1 does not match its inddex",
+			    p->pack_name);
 	unuse_pack(w_curs);
 
 	/* Make sure everything reachable from idx is valid.  Since we
