			write_or_die(fd, tag_template, strlen(tag_template));
		close(fd);

		launch_editor(path, buf, NULL);

		unlink(path);
		free(path);
