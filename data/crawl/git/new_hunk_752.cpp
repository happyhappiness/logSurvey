		display_name(n);
		if (longformat)
			show_suffix(0, n->tag ? &n->tag->tagged->oid : &oid);
		if (suffix)
			printf("%s", suffix);
		printf("\n");
		return;
	}
