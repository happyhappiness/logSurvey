			/* When cloning, it is not unusual to have
			 * no common commit.
			 */
			fprintf(stderr, "warning: no common commits\n");

	if (get_pack(fd, pack_lockfile))
		die("git fetch-pack: fetch failed.");
