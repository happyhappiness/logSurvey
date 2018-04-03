	} else {
		switch (opts->variant) {
		default:
			warning("Cannot merge binary files: %s (%s vs. %s)\n",
				path, name1, name2);
			/* fallthru */
		case XDL_MERGE_FAVOR_OURS:
			stolen = src1;
			break;
