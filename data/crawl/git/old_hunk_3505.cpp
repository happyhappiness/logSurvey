		run_status(stdout, index_file, prefix, 0, s);
		if (amend)
			fputs(_(empty_amend_advice), stderr);
		else if (whence == FROM_CHERRY_PICK)
			fputs(_(empty_cherry_pick_advice), stderr);
		return 0;
	}
