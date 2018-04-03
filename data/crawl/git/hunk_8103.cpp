 	size += header_len;
 
 	if (sign) {
-		size = do_sign(buffer, size, max_size);
-		if (size < 0)
+		ssize_t r = do_sign(buffer, size, max_size);
+		if (r < 0)
 			die("unable to sign the tag");
+		size = r;
 	}
 
 	if (write_sha1_file(buffer, size, tag_type, result) < 0)
