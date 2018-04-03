		printf("------\n");
	}

	stringed = flags & BISECT_SHOW_STRINGED;

	if (flags & BISECT_SHOW_TRIED)
		show_tried_revs(tried, stringed);

	print_var_str("bisect_rev", hex, stringed);
	print_var_int("bisect_nr", cnt - 1, stringed);
	print_var_int("bisect_good", all - reaches - 1, stringed);
	print_var_int("bisect_bad", reaches - 1, stringed);
	print_var_int("bisect_all", all, stringed);
	print_var_int("bisect_steps", estimate_bisect_steps(all), 0);

	return 0;
}