 			if (*arg == '=')
 				name_width = strtoul(arg + 1, &end, 10);
 			else if (!*arg && !av[1])
-				die("Option '--stat-name-width' requires a value");
+				die_want_option("--stat-name-width");
 			else if (!*arg) {
 				name_width = strtoul(av[1], &end, 10);
 				argcount = 2;
