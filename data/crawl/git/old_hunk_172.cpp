		 * If so, rewrite it like in fast-import
		 */
		if (pack_to_stdout) {
			sha1close(f, sha1, CSUM_CLOSE);
		} else if (nr_written == nr_remaining) {
			sha1close(f, sha1, CSUM_FSYNC);
		} else {
			int fd = sha1close(f, sha1, 0);
			fixup_pack_header_footer(fd, sha1, pack_tmp_name,
						 nr_written, sha1, offset);
			close(fd);
			if (write_bitmap_index) {
				warning(_(no_split_warning));
