			die_errno("Could not write to '%s'", git_path("MERGE_HEAD"));
		close(fd);
		strbuf_addch(&merge_msg, '\n');
		write_merge_msg();
		fd = open(git_path("MERGE_MODE"), O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd < 0)
			die_errno("Could not open '%s' for writing",
