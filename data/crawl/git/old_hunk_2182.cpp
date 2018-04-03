		revs->pretty_given = 1;
		get_commit_format(arg+9, revs);
	} else if (!strcmp(arg, "--expand-tabs")) {
		revs->expand_tabs_in_log = 1;
	} else if (!strcmp(arg, "--no-expand-tabs")) {
		revs->expand_tabs_in_log = 0;
	} else if (!strcmp(arg, "--show-notes") || !strcmp(arg, "--notes")) {
		revs->show_notes = 1;
		revs->show_notes_given = 1;