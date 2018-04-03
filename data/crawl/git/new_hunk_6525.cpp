			ecbdata.diff_words =
				xcalloc(1, sizeof(struct diff_words_data));
			ecbdata.diff_words->file = o->file;
			if (o->word_regex) {
				ecbdata.diff_words->word_regex = (regex_t *)
					xmalloc(sizeof(regex_t));
				if (regcomp(ecbdata.diff_words->word_regex,
						o->word_regex, REG_EXTENDED))
					die ("Invalid regular expression: %s",
							o->word_regex);
			}
		}
		xdi_diff_outf(&mf1, &mf2, fn_out_consume, &ecbdata,
			      &xpp, &xecfg, &ecb);
