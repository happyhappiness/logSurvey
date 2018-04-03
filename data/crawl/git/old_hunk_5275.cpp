					die ("Invalid regular expression: %s",
							o->word_regex);
			}
		}
		xdi_diff_outf(&mf1, &mf2, fn_out_consume, &ecbdata,
			      &xpp, &xecfg, &ecb);
		if (DIFF_OPT_TST(o, COLOR_DIFF_WORDS))
			free_diff_words_data(&ecbdata);
		if (textconv_one)
			free(mf1.ptr);
