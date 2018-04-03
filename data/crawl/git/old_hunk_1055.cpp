		oidcpy(&patch->threeway_stage[2], &post_oid);
		if (state->apply_verbosity > verbosity_silent)
			fprintf(stderr,
				"Applied patch to '%s' with conflicts.\n",
				patch->new_name);
	} else {
		if (state->apply_verbosity > verbosity_silent)
			fprintf(stderr,
				"Applied patch to '%s' cleanly.\n",
				patch->new_name);
	}
	return 0;