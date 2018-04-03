 						pack_tmp_name, strerror(errno));
 			}
 
-			/* Enough space for "-<sha-1>.pack"? */
-			if (sizeof(tmpname) <= strlen(base_name) + 50)
-				die("pack base name '%s' too long", base_name);
-			snprintf(tmpname, sizeof(tmpname), "%s-", base_name);
+			strbuf_addf(&tmpname, "%s-", base_name);
 
 			if (write_bitmap_index) {
 				bitmap_writer_set_checksum(sha1);
 				bitmap_writer_build_type_index(written_list, nr_written);
 			}
 
-			finish_tmp_packfile(tmpname, pack_tmp_name,
+			finish_tmp_packfile(&tmpname, pack_tmp_name,
 					    written_list, nr_written,
 					    &pack_idx_opts, sha1);
 
 			if (write_bitmap_index) {
-				char *end_of_name_prefix = strrchr(tmpname, 0);
-				sprintf(end_of_name_prefix, "%s.bitmap", sha1_to_hex(sha1));
+				strbuf_addf(&tmpname, "%s.bitmap", sha1_to_hex(sha1));
 
 				stop_progress(&progress_state);
 
