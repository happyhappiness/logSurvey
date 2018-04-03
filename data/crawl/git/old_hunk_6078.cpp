		memcpy(pathname + len, de->d_name, 38);
		if (opts & DRY_RUN)
			printf("rm -f %s\n", pathname);
		else if (unlink(pathname) < 0)
			error("unable to unlink %s", pathname);
		display_progress(progress, i + 1);
	}
	pathname[len] = 0;
