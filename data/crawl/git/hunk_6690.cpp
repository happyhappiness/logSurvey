 
 	if (hdr->hdr_signature != htonl(CACHE_SIGNATURE))
 		return error("bad signature");
-	if (hdr->hdr_version != htonl(2))
+	if (hdr->hdr_version != htonl(2) && hdr->hdr_version != htonl(3))
 		return error("bad index version");
 	git_SHA1_Init(&c);
 	git_SHA1_Update(&c, hdr, size - 20);