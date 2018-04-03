		return;

	err = whitespace_error_string(result);
	fprintf(stderr, "%s:%d: %s.\n%.*s\n",
		state->patch_input_file, linenr, err, len, line);
	free(err);
}

