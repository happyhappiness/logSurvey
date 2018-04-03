	}

	if (!getcwd(cwd, sizeof(cwd)-1))
		die_errno("Unable to read current working directory");

	ceil_offset = longest_ancestor_length(cwd, env_ceiling_dirs);
	if (ceil_offset < 0 && has_dos_drive_prefix(cwd))
