			error("Error deleting %sbranch '%s'", remote,
			       argv[i]);
			ret = 1;
		} else
			printf("Deleted %sbranch %s.\n", remote, argv[i]);

	}

	if (name)
