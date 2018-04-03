			error("Error deleting %sbranch '%s'", remote,
			       argv[i]);
			ret = 1;
		} else {
			printf("Deleted %sbranch %s.\n", remote, argv[i]);
			snprintf(section, sizeof(section), "branch.%s",
				 argv[i]);
			if (git_config_rename_section(section, NULL) < 0)
				warning("Update of config-file failed");
		}
	}

	if (name)
