		uint32_t mode;
		if (!have_text)
			mark = repo_read_path(node_ctx.dst);
		mode = repo_read_mode(node_ctx.dst);
		if (mode == REPO_MODE_DIR && type != REPO_MODE_DIR)
			die("invalid dump: cannot modify a directory into a file");
		if (mode != REPO_MODE_DIR && type == REPO_MODE_DIR)