 		return error("Unable to start request");
 	}
 
-	if (buffer.posn != 41)
+	strbuf_rtrim(&buffer);
+	if (buffer.len != 40)
 		return 1;
-        hex[40] = '\0';
-	return get_sha1_hex(hex, sha1);
+	return get_sha1_hex(buffer.buf, sha1);
 }
 
 static void cleanup(struct walker *walker)
