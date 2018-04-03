	argv_verify_tag[2] = sha1_to_hex(sha1);

	if (run_command_v_opt(argv_verify_tag, RUN_GIT_CMD))
		return error("could not verify the tag '%s'", name);
	return 0;
}

