			  regexec(regexp, (value_?value_:""), 0, NULL, 0)))
		return 0;

	if (show_keys) {
		if (value_)
			printf("%s ", key_);
		else
			printf("%s", key_);
	}
	if (seen && !do_all)
		dup_error = 1;
	if (type == T_INT)
