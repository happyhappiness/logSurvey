
		if (unlink(dest) && errno != ENOENT)
			die("failed to unlink %s\n", dest);
		if (!option_no_hardlinks) {
			if (!link(src, dest))
				continue;
			if (option_local)
				die("failed to create link %s\n", dest);
			option_no_hardlinks = 1;
		}
		if (copy_file(dest, src, 0666))
			die("failed to copy file to %s\n", dest);
	}
	closedir(dir);
}