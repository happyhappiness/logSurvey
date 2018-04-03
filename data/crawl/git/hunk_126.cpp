 	if (verify_tag(buf.buf, buf.len) < 0)
 		die("invalid tag signature file");
 
-	if (write_sha1_file(buf.buf, buf.len, tag_type, result_sha1) < 0)
+	if (write_object_file(buf.buf, buf.len, tag_type, &result) < 0)
 		die("unable to write tag file");
 
 	strbuf_release(&buf);
-	printf("%s\n", sha1_to_hex(result_sha1));
+	printf("%s\n", oid_to_hex(&result));
 	return 0;
 }
