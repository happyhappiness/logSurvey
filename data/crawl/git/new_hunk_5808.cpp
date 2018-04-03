	}

	if (*cwd && chdir(cwd))
		die_errno ("Could not change back to '%s'", cwd);

	return buf;
}
