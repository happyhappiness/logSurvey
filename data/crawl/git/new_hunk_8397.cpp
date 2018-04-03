		die("wrote %u objects while expecting %u", written, nr_result);
	sha1close(f, pack_file_sha1, 1);

	if (!pack_to_stdout) {
			unsigned char object_list_sha1[20];
			mode_t mode = umask(0);

			umask(mode);
			mode = 0444 & ~mode;

			write_index_file(last_obj_offset, object_list_sha1);
			snprintf(tmpname, sizeof(tmpname), "%s-%s.pack",
				 base_name, sha1_to_hex(object_list_sha1));
			if (adjust_perm(pack_tmp_name, mode))
				die("unable to make temporary pack file readable: %s",
				    strerror(errno));
			if (rename(pack_tmp_name, tmpname))
				die("unable to rename temporary pack file: %s",
				    strerror(errno));
			snprintf(tmpname, sizeof(tmpname), "%s-%s.idx",
				 base_name, sha1_to_hex(object_list_sha1));
			if (adjust_perm(idx_tmp_name, mode))
				die("unable to make temporary index file readable: %s",
				    strerror(errno));
			if (rename(idx_tmp_name, tmpname))
				die("unable to rename temporary index file: %s",
				    strerror(errno));
			puts(sha1_to_hex(object_list_sha1));
	}
}

static int sha1_sort(const void *_a, const void *_b)
