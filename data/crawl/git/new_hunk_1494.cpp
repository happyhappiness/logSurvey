		return;

	err = whitespace_error_string(result);
	if (state->apply_verbosity > verbosity_silent)
		fprintf(stderr, "%s:%d: %s.\n%.*s\n",
			state->patch_input_file, linenr, err, len, line);
	free(err);
}

