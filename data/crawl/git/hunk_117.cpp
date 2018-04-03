 
 	if (final_pack_name != curr_pack_name) {
 		if (!final_pack_name)
-			final_pack_name = odb_pack_name(&pack_name, sha1, "pack");
+			final_pack_name = odb_pack_name(&pack_name, hash, "pack");
 		if (finalize_object_file(curr_pack_name, final_pack_name))
 			die(_("cannot store pack file"));
 	} else if (from_stdin)
 		chmod(final_pack_name, 0444);
 
 	if (final_index_name != curr_index_name) {
 		if (!final_index_name)
-			final_index_name = odb_pack_name(&index_name, sha1, "idx");
+			final_index_name = odb_pack_name(&index_name, hash, "idx");
 		if (finalize_object_file(curr_index_name, final_index_name))
 			die(_("cannot store index file"));
 	} else
 		chmod(final_index_name, 0444);
 
 	if (!from_stdin) {
-		printf("%s\n", sha1_to_hex(sha1));
+		printf("%s\n", sha1_to_hex(hash));
 	} else {
 		struct strbuf buf = STRBUF_INIT;
 
-		strbuf_addf(&buf, "%s\t%s\n", report, sha1_to_hex(sha1));
+		strbuf_addf(&buf, "%s\t%s\n", report, sha1_to_hex(hash));
 		write_or_die(1, buf.buf, buf.len);
 		strbuf_release(&buf);
 
