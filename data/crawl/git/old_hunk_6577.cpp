		if (S_ISLNK(st.st_mode)) {
			int ret;
			char buf[PATH_MAX + 1]; /* ought to be SYMLINK_MAX */
			size_t sz = xsize_t(st.st_size);
			if (sizeof(buf) <= st.st_size)
				die("symlink too long: %s", name);
			ret = readlink(name, buf, sz);
			if (ret < 0)
				die("readlink(%s)", name);
			prep_temp_blob(temp, buf, sz,
				       (one->sha1_valid ?
					one->sha1 : null_sha1),
				       (one->sha1_valid ?