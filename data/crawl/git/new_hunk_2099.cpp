		size_t i;
		if (!fgets(buffer, MAXCOMMAND - 1, stdin)) {
			if (ferror(stdin))
				die("Command input error");
			exit(0);
		}
		/* Strip end of line characters. */
