		lst = &((*lst)->next);
	*lst = (*lst)->next;

	if (!strip_suffix(preq->tmpfile, ".pack.temp", &len))
		die("BUG: pack tmpfile does not end in .pack.temp?");
	tmp_idx = xstrfmt("%.*s.idx.temp", (int)len, preq->tmpfile);

	ip_argv[0] = "index-pack";
	ip_argv[1] = "-o";
