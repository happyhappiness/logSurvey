	} else {
		name = find_name(first, NULL, p_value, TERM_SPACE | TERM_TAB);
		name = find_name(second, name, p_value, TERM_SPACE | TERM_TAB);
		patch->old_name = patch->new_name = name;
	}
	if (!name)
		die("unable to find filename in patch at line %d", linenr);
