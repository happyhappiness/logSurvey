 			if (*arg == '=')
 				width = strtoul(arg + 1, &end, 10);
 			else if (!*arg && !av[1])
-				die("Option '--stat-width' requires a value");
+				die_want_option("--stat-width");
 			else if (!*arg) {
 				width = strtoul(av[1], &end, 10);
 				argcount = 2;
