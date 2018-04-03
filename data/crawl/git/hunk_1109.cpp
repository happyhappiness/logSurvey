 			if (*arg == '=')
 				count = strtoul(arg + 1, &end, 10);
 			else if (!*arg && !av[1])
-				die("Option '--stat-count' requires a value");
+				die_want_option("--stat-count");
 			else if (!*arg) {
 				count = strtoul(av[1], &end, 10);
 				argcount = 2;