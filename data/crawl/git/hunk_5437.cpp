 		free(term);
 	}
 	else {
-		size_t n = 0, length;
+		uintmax_t len = strtoumax(command_buf.buf + 5, NULL, 10);
+		size_t n = 0, length = (size_t)len;
 
-		length = strtoul(command_buf.buf + 5, NULL, 10);
+		if (limit && limit < len) {
+			*len_res = len;
+			return 0;
+		}
+		if (length < len)
+			die("data is too large to use in this context");
 
 		while (n < length) {
 			size_t s = strbuf_fread(sb, length - n, stdin);
