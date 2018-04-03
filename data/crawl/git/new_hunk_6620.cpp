
		strcpy(hex, find_unique_abbrev(head, DEFAULT_ABBREV));

		if (verbosity >= 0)
			printf("Updating %s..%s\n",
				hex,
				find_unique_abbrev(remoteheads->item->object.sha1,
				DEFAULT_ABBREV));
		strbuf_addstr(&msg, "Fast forward");
		if (have_message)
			strbuf_addstr(&msg,
