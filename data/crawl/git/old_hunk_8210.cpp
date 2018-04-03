			i++;
			if (i == argc)
				die("option -F needs an argument.");

			if (!strcmp(argv[i], "-"))
				fd = 0;
