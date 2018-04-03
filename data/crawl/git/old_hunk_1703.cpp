
	use_atomic = atomic_supported && args->atomic;

	if (status_report)
		strbuf_addstr(&cap_buf, " report-status");
	if (use_sideband)
