		if (!show_file(arg))
			continue;
		if (verify)
			die_no_single_rev(quiet);
		verify_filename(prefix, arg);
	}
	show_default();
	if (verify && revs_count != 1)
		die_no_single_rev(quiet);
	return 0;
}