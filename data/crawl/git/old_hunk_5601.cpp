		if (strbuf_getline(&buf, stdin, '\n') == EOF)
			break;
		if (!prefixcmp(buf.buf, "fetch ")) {
			char *obj = buf.buf + strlen("fetch ");
			init_walker();
			walker->get_all = 1;
			walker->get_tree = 1;
			walker->get_history = 1;
			walker->get_verbosely = 0;
			walker->get_recover = 0;
			if (walker_fetch(walker, 1, &obj, NULL, NULL))
				die("Fetch failed.");
			printf("\n");
			fflush(stdout);
		} else if (!strcmp(buf.buf, "list")) {
			struct ref *refs = get_refs();
			struct ref *posn;
