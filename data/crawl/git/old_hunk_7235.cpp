		if (!show_file(arg))
			continue;
		if (verify)
			die("Needed a single revision");
		verify_filename(prefix, arg);
	}
	show_default();
	if (verify && revs_count != 1)
		die("Needed a single revision");
	return 0;
}