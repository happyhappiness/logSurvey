	struct git_transport_data *data;

	if (!transport->smart_options)
		die("BUG: taking over transport requires non-NULL "
		    "smart_options field.");

	data = xcalloc(1, sizeof(*data));
