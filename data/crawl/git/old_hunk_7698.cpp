	data.filename = name_b ? name_b : name_a;
	data.lineno = 0;
	data.color_diff = o->color_diff;

	if (fill_mmfile(&mf1, one) < 0 || fill_mmfile(&mf2, two) < 0)
		die("unable to read files to diff");
