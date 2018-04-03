
	if (type != show_type)
		putchar('^');
	if (symbolic && name)
		show(name);
	else if (abbrev)
		show(find_unique_abbrev(sha1, abbrev));
	else
