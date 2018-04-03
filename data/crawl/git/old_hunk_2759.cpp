		lst = &((*lst)->next);
	*lst = (*lst)->next;

	tmp_idx = xstrdup(preq->tmpfile);
	strcpy(tmp_idx + strlen(tmp_idx) - strlen(".pack.temp"),
	       ".idx.temp");

	ip_argv[0] = "index-pack";
	ip_argv[1] = "-o";
