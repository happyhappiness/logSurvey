			 */
			fprintf(stderr, "warning: no common commits\n");

	if (get_pack(fd))
		die("git-fetch-pack: fetch failed.");

 all_done: