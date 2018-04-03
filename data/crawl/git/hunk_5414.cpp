 	memset(&s, 0, sizeof(s));
 	deflateInit(&s, pack_compression_level);
 
-	hdrlen = encode_header(OBJ_BLOB, len, out_buf);
+	hdrlen = encode_in_pack_object_header(OBJ_BLOB, len, out_buf);
 	if (out_sz <= hdrlen)
 		die("impossibly large object header");
 
