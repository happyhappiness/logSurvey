			if (sizeof(tmpname) <= strlen(base_name) + 50)
				die("pack base name '%s' too long", base_name);
			snprintf(tmpname, sizeof(tmpname), "%s-", base_name);

			if (write_bitmap_index) {
				bitmap_writer_set_checksum(sha1);
				bitmap_writer_build_type_index(written_list, nr_written);
			}

			finish_tmp_packfile(tmpname, pack_tmp_name,
					    written_list, nr_written,
					    &pack_idx_opts, sha1);

			if (write_bitmap_index) {
				char *end_of_name_prefix = strrchr(tmpname, 0);
				sprintf(end_of_name_prefix, "%s.bitmap", sha1_to_hex(sha1));

				stop_progress(&progress_state);

				bitmap_writer_show_progress(progress);
				bitmap_writer_reuse_bitmaps(&to_pack);
				bitmap_writer_select_commits(indexed_commits, indexed_commits_nr, -1);
				bitmap_writer_build(&to_pack);
				bitmap_writer_finish(written_list, nr_written, tmpname);
				write_bitmap_index = 0;
			}

			free(pack_tmp_name);
			puts(sha1_to_hex(sha1));
		}
