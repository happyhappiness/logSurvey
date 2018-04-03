			else if (ATTR_UNSET(value))
				value = "unspecified";

			write_name_quoted("", 0, argv[i], 1, stdout);
			printf(": %s: %s\n", argv[j+1], value);
		}
	}
