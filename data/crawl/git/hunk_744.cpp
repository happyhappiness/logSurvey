 	sha1file_checkpoint(pack_file, &checkpoint);
 	offset = checkpoint.offset;
 
-	hdrlen = snprintf((char *)out_buf, out_sz, "blob %" PRIuMAX, len) + 1;
-	if (out_sz <= hdrlen)
-		die("impossibly large object header");
+	hdrlen = xsnprintf((char *)out_buf, out_sz, "blob %" PRIuMAX, len) + 1;
 
 	git_SHA1_Init(&c);
 	git_SHA1_Update(&c, out_buf, hdrlen);