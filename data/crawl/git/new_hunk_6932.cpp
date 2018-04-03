			write_or_die(fd, tag_template, strlen(tag_template));
		close(fd);

		if (launch_editor(path, buf, NULL)) {
			fprintf(stderr,
			"Please supply the message using either -m or -F option.\n");
			exit(1);
		}

		unlink(path);
		free(path);
