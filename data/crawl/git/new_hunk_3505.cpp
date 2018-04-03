		run_status(stdout, index_file, prefix, 0, s);
		if (amend)
			fputs(_(empty_amend_advice), stderr);
		else if (whence == FROM_CHERRY_PICK) {
			fputs(_(empty_cherry_pick_advice), stderr);
			if (!sequencer_in_use)
				fputs(_(empty_cherry_pick_advice_single), stderr);
			else
				fputs(_(empty_cherry_pick_advice_multi), stderr);
		}
		return 0;
	}
