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
