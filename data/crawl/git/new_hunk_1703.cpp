
	use_atomic = atomic_supported && args->atomic;

	if (args->push_options && !push_options_supported)
		die(_("the receiving end does not support push options"));

	use_push_options = push_options_supported && args->push_options;

	if (status_report)
		strbuf_addstr(&cap_buf, " report-status");
	if (use_sideband)
