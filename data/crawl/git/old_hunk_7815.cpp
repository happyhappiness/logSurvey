	if (!dest || i != argc - 1)
		usage(ls_remote_usage);

	transport = transport_get(NULL, dest);
	if (uploadpack != NULL)
		transport_set_option(transport, TRANS_OPT_UPLOADPACK, uploadpack);

