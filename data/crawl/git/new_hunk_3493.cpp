	if (start_command(&pack_objects))
		die("git upload-pack: unable to fork git-pack-objects");

	pipe_fd = xfdopen(pack_objects.in, "w");

	for (i = 0; i < want_obj.nr; i++)
		fprintf(pipe_fd, "%s\n",
			sha1_to_hex(want_obj.objects[i].item->sha1));
	fprintf(pipe_fd, "--not\n");
	for (i = 0; i < have_obj.nr; i++)
		fprintf(pipe_fd, "%s\n",
			sha1_to_hex(have_obj.objects[i].item->sha1));
	for (i = 0; i < extra_edge_obj.nr; i++)
		fprintf(pipe_fd, "%s\n",
			sha1_to_hex(extra_edge_obj.objects[i].item->sha1));
	fprintf(pipe_fd, "\n");
	fflush(pipe_fd);
	fclose(pipe_fd);

	/* We read from pack_objects.err to capture stderr output for
	 * progress bar, and pack_objects.out to capture the pack data.
