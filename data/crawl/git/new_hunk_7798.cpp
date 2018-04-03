	if (fill_mmfile(&mf1, one) < 0 || fill_mmfile(&mf2, two) < 0)
		die("unable to read files to diff");

	if (!DIFF_OPT_TST(o, TEXT) &&
	    (diff_filespec_is_binary(one) || diff_filespec_is_binary(two))) {
		/* Quite common confusing case */
		if (mf1.size == mf2.size &&
		    !memcmp(mf1.ptr, mf2.ptr, mf1.size))
			goto free_ab_and_return;
		if (DIFF_OPT_TST(o, BINARY))
			emit_binary_diff(&mf1, &mf2);
		else
			printf("Binary files %s and %s differ\n",
