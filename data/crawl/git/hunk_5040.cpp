 		err = error("%s SHA1 checksum mismatch",
 			    p->pack_name);
 	if (hashcmp(index_base + index_size - 40, pack_sig))
-		err = error("%s SHA1 does not match its inddex",
+		err = error("%s SHA1 does not match its index",
 			    p->pack_name);
 	unuse_pack(w_curs);
 