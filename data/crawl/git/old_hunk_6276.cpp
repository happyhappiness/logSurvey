		if (formatp) {
			formatp++;
			if (!strcmp(formatp, "short"))
				refname = get_short_ref(refname);
			else
				die("unknown %.*s format %s",
				    (int)(formatp - name), name, formatp);