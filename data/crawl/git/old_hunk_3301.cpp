
	if (finish_command(&exporter))
		die("Error while running fast-export");
	push_update_refs_status(data, remote_refs, flags);
	return 0;
}

