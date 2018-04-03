		if (formatp) {
			formatp++;
			if (!strcmp(formatp, "short"))
				refname = shorten_unambiguous_ref(refname);
			else
				die("unknown %.*s format %s",
				    (int)(formatp - name), name, formatp);
