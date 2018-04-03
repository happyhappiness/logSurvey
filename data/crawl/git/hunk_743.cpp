 	c = (type << 4) | (size & 15);
 	size >>= 4;
 	while (size) {
+		if (n == hdr_len)
+			die("object size is too enormous to format");
 		*hdr++ = c | 0x80;
 		c = size & 0x7f;
 		size >>= 7;
