		if (!lstat(buf, &st) && S_ISLNK(st.st_mode)) {
			len = readlink(buf, next_buf, PATH_MAX);
			if (len < 0)
				die ("Invalid symlink: %s", buf);
			if (PATH_MAX <= len)
				die("symbolic link too long: %s", buf);
			next_buf[len] = '\0';
