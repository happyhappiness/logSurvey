			else if (ATTR_UNSET(value))
				value = "unspecified";

			quote_c_style(argv[i], NULL, stdout, 0);
			printf(": %s: %s\n", argv[j+1], value);
		}
	}
