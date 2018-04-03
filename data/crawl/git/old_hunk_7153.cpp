
		if (unlink(dest) && errno != ENOENT)
			die("failed to unlink %s\n", dest);
		if (option_no_hardlinks) {
			if (copy_file(dest, src, 0666))
				die("failed to copy file to %s\n", dest);
		} else {
			if (link(src, dest))
				die("failed to create link %s\n", dest);
		}
	}
	closedir(dir);
}