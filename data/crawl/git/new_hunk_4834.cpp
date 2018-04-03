		data->is_unmerged = 1;
		return;
	}

	if (diff_filespec_is_binary(one) || diff_filespec_is_binary(two)) {
		if (fill_mmfile(&mf1, one) < 0 || fill_mmfile(&mf2, two) < 0)
			die("unable to read files to diff");
		data->is_binary = 1;
		data->added = mf2.size;
		data->deleted = mf1.size;
	}

	else if (complete_rewrite) {
		diff_populate_filespec(one, 0);
		diff_populate_filespec(two, 0);
		data->deleted = count_lines(one->data, one->size);
		data->added = count_lines(two->data, two->size);
	}

	else {
		/* Crazy xdl interfaces.. */
		xpparam_t xpp;
		xdemitconf_t xecfg;
		xdemitcb_t ecb;

		if (fill_mmfile(&mf1, one) < 0 || fill_mmfile(&mf2, two) < 0)
			die("unable to read files to diff");

		memset(&xpp, 0, sizeof(xpp));
		memset(&xecfg, 0, sizeof(xecfg));
		xpp.flags = XDF_NEED_MINIMAL | o->xdl_opts;
		xdi_diff_outf(&mf1, &mf2, diffstat_consume, diffstat,
			      &xpp, &xecfg, &ecb);
	}

	diff_free_filespec_data(one);
	diff_free_filespec_data(two);
}
