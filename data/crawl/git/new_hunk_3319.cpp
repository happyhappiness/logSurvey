			unkv[(*unkc)++] = arg;
		return opts;
	}
	if (revs->graph && revs->track_linear)
		die("--show-linear-break and --graph are incompatible");

	return 1;
}
