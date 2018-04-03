 	for (; options->type != OPTION_END; options++) {
 		if (!(options->flags & PARSE_OPT_NODASH))
 			continue;
-		if ((options->flags & PARSE_OPT_OPTARG) ||
-		    !(options->flags & PARSE_OPT_NOARG))
-			die("BUG: dashless options don't support arguments");
-		if (!(options->flags & PARSE_OPT_NONEG))
-			die("BUG: dashless options don't support negation");
-		if (options->long_name)
-			die("BUG: dashless options can't be long");
 		if (options->short_name == arg[0] && arg[1] == '\0')
 			return get_value(p, options, OPT_SHORT);
 	}
