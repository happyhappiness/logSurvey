			continue;
		strcpy(name, de->d_name);
		if (lstat(pathbuf, &st))
			die("cannot lstat %s (%s)", pathbuf, strerror(errno));
		if (S_ISDIR(st.st_mode))
			remove_subtree(pathbuf);
		else if (unlink(pathbuf))
			die("cannot unlink %s (%s)", pathbuf, strerror(errno));
	}
	closedir(dir);
	if (rmdir(path))
		die("cannot rmdir %s (%s)", path, strerror(errno));
}

static int create_file(const char *path, unsigned int mode)
