			if (*arg == '=')
				graph_width = strtoul(arg + 1, &end, 10);
			else if (!*arg && !av[1])
				die("Option '--stat-graph-width' requires a value");
			else if (!*arg) {
				graph_width = strtoul(av[1], &end, 10);
				argcount = 2;
