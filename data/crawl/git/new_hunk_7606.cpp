
	if (type != show_type)
		putchar('^');
	if (symbolic && name) {
		if (symbolic == SHOW_SYMBOLIC_FULL) {
			unsigned char discard[20];
			char *full;

			switch (dwim_ref(name, strlen(name), discard, &full)) {
			case 0:
				/*
				 * Not found -- not a ref.  We could
				 * emit "name" here, but symbolic-full
				 * users are interested in finding the
				 * refs spelled in full, and they would
				 * need to filter non-refs if we did so.
				 */
				break;
			case 1: /* happy */
				show(full);
				break;
			default: /* ambiguous */
				error("refname '%s' is ambiguous", name);
				break;
			}
		} else {
			show(name);
		}
	}
	else if (abbrev)
		show(find_unique_abbrev(sha1, abbrev));
	else
