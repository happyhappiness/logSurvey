		struct string_list_item *item;

		string_list_sort(&cpath);
		if (state->apply_verbosity > verbosity_silent) {
			for_each_string_list_item(item, &cpath)
				fprintf(stderr, "U %s\n", item->string);
		}
		string_list_clear(&cpath, 0);

		rerere(0);
