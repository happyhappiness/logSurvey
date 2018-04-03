	if (s.relative_paths)
		s.prefix = prefix;

	switch (status_format) {
	case STATUS_FORMAT_SHORT:
		wt_shortstatus_print(&s);
		break;
	case STATUS_FORMAT_PORCELAIN:
		wt_porcelain_print(&s);
		break;
	case STATUS_FORMAT_UNSPECIFIED:
		die("BUG: finalize_deferred_config() should have been called");
		break;
	case STATUS_FORMAT_NONE:
	case STATUS_FORMAT_LONG:
		s.verbose = verbose;
		s.ignore_submodule_arg = ignore_submodule_arg;
		wt_longstatus_print(&s);
		break;
	}
	return 0;
}

