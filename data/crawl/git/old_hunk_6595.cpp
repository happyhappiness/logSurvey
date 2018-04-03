			char *lnk = xmemdupz(buf, size);
			safe_create_leading_directories_const(path);
			unlink(path);
			symlink(lnk, path);
			free(lnk);
		} else
			die("do not know what to do with %06o %s '%s'",