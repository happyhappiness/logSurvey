	if (!data->refspecs)
		die("remote-helper doesn't support push; refspec needed");

	set_common_push_options(transport, data->name, flags);
	if (flags & TRANSPORT_PUSH_FORCE) {
		if (set_helper_option(transport, "force", "true") != 0)
			warning("helper %s does not support 'force'", data->name);
