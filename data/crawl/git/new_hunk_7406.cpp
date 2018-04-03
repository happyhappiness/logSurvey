
	n = cmit->util;
	if (n) {
		if (!longformat)
			printf("%s\n", n->path);
		else
			printf("%s-0-g%s\n", n->path,
				find_unique_abbrev(cmit->object.sha1, abbrev));
		return;
	}

