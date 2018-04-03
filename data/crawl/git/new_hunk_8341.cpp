		 * If so, rewrite it like in fast-import
		 */
		if (pack_to_stdout || nr_written == nr_remaining) {
			sha1close(f, sha1, 1);
		} else {
			sha1close(f, sha1, 0);
			fixup_pack_header_footer(f->fd, sha1, pack_tmp_name, nr_written);
			close(f->fd);
		}

		if (!pack_to_stdout) {
			mode_t mode = umask(0);

			umask(mode);
			mode = 0444 & ~mode;

			idx_tmp_name = write_idx_file(NULL,
				(struct pack_idx_entry **) written_list, nr_written, sha1);
			snprintf(tmpname, sizeof(tmpname), "%s-%s.pack",
				 base_name, sha1_to_hex(sha1));
			if (adjust_perm(pack_tmp_name, mode))
				die("unable to make temporary pack file readable: %s",
				    strerror(errno));
			if (rename(pack_tmp_name, tmpname))
				die("unable to rename temporary pack file: %s",
				    strerror(errno));
			snprintf(tmpname, sizeof(tmpname), "%s-%s.idx",
				 base_name, sha1_to_hex(sha1));
			if (adjust_perm(idx_tmp_name, mode))
				die("unable to make temporary index file readable: %s",
				    strerror(errno));
			if (rename(idx_tmp_name, tmpname))
				die("unable to rename temporary index file: %s",
				    strerror(errno));
			puts(sha1_to_hex(sha1));
		}

		/* mark written objects as written to previous pack */
		for (j = 0; j < nr_written; j++) {
			written_list[j]->idx.offset = (off_t)-1;
		}
		nr_remaining -= nr_written;
	} while (nr_remaining && i < nr_objects);
