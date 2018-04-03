	ret = transport_get_remote_refs(transport);
	transport_disconnect(transport);
	if (0 <= option_verbosity)
		printf(_("done.\n"));
	return ret;
}

