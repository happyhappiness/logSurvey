	free(head_name_to_free);
	head_name = head_name_to_free = resolve_refdup("HEAD", sha1, 0, NULL);

	for (cmd = commands; cmd; cmd = cmd->next) {
		if (cmd->error_string)
			continue;

		if (cmd->skip_update)
			continue;

		cmd->error_string = update(cmd);
	}
}

