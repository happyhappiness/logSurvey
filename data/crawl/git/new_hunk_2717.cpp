			xecfg.ctxlen = strtoul(v, NULL, 10);
		if (o->word_diff)
			init_diff_words_data(&ecbdata, o, one, two);
		if (xdi_diff_outf(&mf1, &mf2, fn_out_consume, &ecbdata,
				  &xpp, &xecfg))
			die("unable to generate diff for %s", one->path);
		if (o->word_diff)
			free_diff_words_data(&ecbdata);
		if (textconv_one)
