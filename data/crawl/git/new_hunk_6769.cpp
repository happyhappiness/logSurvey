		struct strbuf buf, nbuf;

		if (all)
			die("git checkout-index: don't mix '--all' and '--stdin'");

		strbuf_init(&buf, 0);
		strbuf_init(&nbuf, 0);
