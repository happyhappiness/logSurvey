		memcpy(pathname + len, de->d_name, 38);
		if (opts & DRY_RUN)
			printf("rm -f %s\n", pathname);
		else
			unlink_or_warn(pathname);
		display_progress(progress, i + 1);
	}
	pathname[len] = 0;
