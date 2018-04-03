error_out:
	free(last_elem);
	if (*cwd && chdir(cwd))
		die_errno ("Could not change back to '%s'", cwd);

	return retval;
}