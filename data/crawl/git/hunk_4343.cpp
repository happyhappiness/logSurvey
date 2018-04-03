 {
 	static const char *capabilities = "multi_ack thin-pack side-band"
 		" side-band-64k ofs-delta shallow no-progress"
-		" include-tag multi_ack_detailed no-done";
+		" include-tag multi_ack_detailed";
 	struct object *o = parse_object(sha1);
 
 	if (!o)
 		die("git upload-pack: cannot find object %s:", sha1_to_hex(sha1));
 
 	if (capabilities)
-		packet_write(1, "%s %s%c%s\n", sha1_to_hex(sha1), refname,
-			0, capabilities);
+		packet_write(1, "%s %s%c%s%s\n", sha1_to_hex(sha1), refname,
+			     0, capabilities,
+			     stateless_rpc ? " no-done" : "");
 	else
 		packet_write(1, "%s %s\n", sha1_to_hex(sha1), refname);
 	capabilities = NULL;