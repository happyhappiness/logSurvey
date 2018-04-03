 		unsigned long maxsize;
 		void *out;
 		if (!usable_delta) {
-			buf = read_sha1_file(entry->sha1, &obj_type, &size);
+			buf = read_sha1_file(entry->idx.sha1, &obj_type, &size);
 			if (!buf)
-				die("unable to read %s", sha1_to_hex(entry->sha1));
+				die("unable to read %s", sha1_to_hex(entry->idx.sha1));
 		} else if (entry->delta_data) {
 			size = entry->delta_size;
 			buf = entry->delta_data;
 			entry->delta_data = NULL;
-			obj_type = (allow_ofs_delta && entry->delta->offset) ?
+			obj_type = (allow_ofs_delta && entry->delta->idx.offset) ?
 				OBJ_OFS_DELTA : OBJ_REF_DELTA;
 		} else {
-			buf = read_sha1_file(entry->sha1, &type, &size);
+			buf = read_sha1_file(entry->idx.sha1, &type, &size);
 			if (!buf)
-				die("unable to read %s", sha1_to_hex(entry->sha1));
+				die("unable to read %s", sha1_to_hex(entry->idx.sha1));
 			buf = delta_against(buf, size, entry);
 			size = entry->delta_size;
-			obj_type = (allow_ofs_delta && entry->delta->offset) ?
+			obj_type = (allow_ofs_delta && entry->delta->idx.offset) ?
 				OBJ_OFS_DELTA : OBJ_REF_DELTA;
 		}
 		/* compress the data to store and put compressed length in datalen */