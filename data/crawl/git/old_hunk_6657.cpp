		utb.actime = sb.st_atime;
		utb.modtime = set_eq ? set_time : sb.st_mtime + set_time;

		if (utime(argv[i], &utb) < 0) {
			fprintf(stderr, "Failed to modify time on %s: %s\n",
			        argv[i], strerror(errno));
			return -1;