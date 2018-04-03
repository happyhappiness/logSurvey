 			if (*arg == '=')
 				graph_width = strtoul(arg + 1, &end, 10);
 			else if (!*arg && !av[1])
-				die("Option '--stat-graph-width' requires a value");
+				die_want_option("--stat-graph-width");
 			else if (!*arg) {
 				graph_width = strtoul(av[1], &end, 10);
 				argcount = 2;
