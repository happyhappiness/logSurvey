				mode = 0666;
			fd = open(path, O_WRONLY | O_TRUNC | O_CREAT, mode);
			if (fd < 0)
				die("failed to open %s: %s", path, strerror(errno));
			flush_buffer(fd, buf, size);
			close(fd);
		} else if (S_ISLNK(mode)) {
			char *lnk = xmemdupz(buf, size);
			safe_create_leading_directories_const(path);
			unlink(path);
			if (symlink(lnk, path))
				die("failed to symlink %s: %s", path, strerror(errno));
			free(lnk);
		} else
			die("do not know what to do with %06o %s '%s'",
