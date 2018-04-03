			hashcpy(patch->threeway_stage[0].hash, pre_sha1);
		hashcpy(patch->threeway_stage[1].hash, our_sha1);
		hashcpy(patch->threeway_stage[2].hash, post_sha1);
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
}
