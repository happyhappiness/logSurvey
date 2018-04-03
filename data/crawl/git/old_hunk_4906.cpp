		     opts->long_name))
			err |= optbug(opts, "uses feature "
					"not supported for dashless options");
	}
	if (err)
		exit(128);