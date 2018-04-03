			xecfg.ctxlen = strtoul(diffopts + 10, NULL, 10);
		else if (!prefixcmp(diffopts, "-u"))
			xecfg.ctxlen = strtoul(diffopts + 2, NULL, 10);
		if (o->word_diff)
			init_diff_words_data(&ecbdata, o, one, two);
		xdi_diff_outf(&mf1, &mf2, fn_out_consume, &ecbdata,
			      &xpp, &xecfg);
		if (o->word_diff)