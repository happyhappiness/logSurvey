		argv_array_push(&args, "--no-autostash");
	else if (opt_autostash == 1)
		argv_array_push(&args, "--autostash");

	argv_array_push(&args, "--onto");
	argv_array_push(&args, sha1_to_hex(merge_head));
