		;
	else {
		err = whitespace_error_string(result);
		fprintf(stderr, "%s.\n%s:%d:%.*s\n",
		     err, patch_input_file, linenr, len - 2, line + 1);
		free(err);
	}
}