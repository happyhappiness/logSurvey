 		offset = write_pack_header(f, nr_remaining);
 		if (!offset)
 			die_errno("unable to write pack header");
+
+		if (reuse_packfile) {
+			off_t packfile_size;
+			assert(pack_to_stdout);
+
+			packfile_size = write_reused_pack(f);
+			offset += packfile_size;
+		}
+
 		nr_written = 0;
 		for (; i < to_pack.nr_objects; i++) {
 			struct object_entry *e = write_order[i];
