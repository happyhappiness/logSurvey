	if (start_command(&pack_objects))
		die("git upload-pack: unable to fork git-pack-objects");

	if (shallow_nr) {
		memset(&rev_list, 0, sizeof(rev_list));
		rev_list.proc = do_rev_list;
		rev_list.out = pack_objects.in;
		if (start_async(&rev_list))
			die("git upload-pack: unable to fork git-rev-list");
	}
	else {
		FILE *pipe_fd = xfdopen(pack_objects.in, "w");
		int i;

		for (i = 0; i < want_obj.nr; i++)
			fprintf(pipe_fd, "%s\n",
				sha1_to_hex(want_obj.objects[i].item->sha1));
		fprintf(pipe_fd, "--not\n");
		for (i = 0; i < have_obj.nr; i++)
			fprintf(pipe_fd, "%s\n",
				sha1_to_hex(have_obj.objects[i].item->sha1));
		fprintf(pipe_fd, "\n");
		fflush(pipe_fd);
		fclose(pipe_fd);
	}


	/* We read from pack_objects.err to capture stderr output for
	 * progress bar, and pack_objects.out to capture the pack data.
