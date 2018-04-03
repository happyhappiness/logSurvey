			ecbdata.diff_words =
				xcalloc(1, sizeof(struct diff_words_data));
			ecbdata.diff_words->file = o->file;
		}
		xdi_diff_outf(&mf1, &mf2, fn_out_consume, &ecbdata,
			      &xpp, &xecfg, &ecb);
