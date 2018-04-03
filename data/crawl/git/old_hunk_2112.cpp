			fixup_pack_header_footer(fd, sha1, pack_tmp_name,
						 nr_written, sha1, offset);
			close(fd);
			write_bitmap_index = 0;
		}

		if (!pack_to_stdout) {