		 * If so, rewrite it like in fast-import
		 */
		if (pack_to_stdout) {
			sha1close(f, oid.hash, CSUM_CLOSE);
		} else if (nr_written == nr_remaining) {
			sha1close(f, oid.hash, CSUM_FSYNC);
		} else {
			int fd = sha1close(f, oid.hash, 0);
			fixup_pack_header_footer(fd, oid.hash, pack_tmp_name,
						 nr_written, oid.hash, offset);
			close(fd);
			if (write_bitmap_index) {
				warning(_(no_split_warning));
