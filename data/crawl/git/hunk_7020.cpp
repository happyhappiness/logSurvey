 			*(int *)opt->value = opt->defval;
 			return 0;
 		}
-		if (!arg)
-			return opterror(opt, "requires a value", flags);
-		*(int *)opt->value = strtol(get_arg(p), (char **)&s, 10);
+		if (get_arg(p, opt, flags, &arg))
+			return -1;
+		*(int *)opt->value = strtol(arg, (char **)&s, 10);
 		if (*s)
 			return opterror(opt, "expects a numerical value", flags);
 		return 0;
