	remote = remote_get(option_origin);
	transport = transport_get(remote, remote->url[0]);

	if (!transport->get_refs_list || (!is_local && !transport->fetch))
		die(_("Don't know how to clone %s"), transport->url);

	transport_set_option(transport, TRANS_OPT_KEEP, "yes");

	if (option_depth)
		transport_set_option(transport, TRANS_OPT_DEPTH,
				     option_depth);
	if (option_single_branch)
		transport_set_option(transport, TRANS_OPT_FOLLOWTAGS, "1");

	transport_set_verbosity(transport, option_verbosity, option_progress);

	if (option_upload_pack)
		transport_set_option(transport, TRANS_OPT_UPLOADPACK,
				     option_upload_pack);

	if (transport->smart_options && !option_depth)
		transport->smart_options->check_self_contained_and_connected = 1;

	refs = transport_get_remote_refs(transport);

