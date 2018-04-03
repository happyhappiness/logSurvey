						pack_tmp_name, strerror(errno));
			}

			strbuf_addf(&tmpname, "%s-", base_name);

			if (write_bitmap_index) {
				bitmap_writer_set_checksum(sha1);
				bitmap_writer_build_type_index(written_list, nr_written);
			}

			finish_tmp_packfile(&tmpname, pack_tmp_name,
					    written_list, nr_written,
					    &pack_idx_opts, sha1);

			if (write_bitmap_index) {
				strbuf_addf(&tmpname, "%s.bitmap", sha1_to_hex(sha1));

				stop_progress(&progress_state);

