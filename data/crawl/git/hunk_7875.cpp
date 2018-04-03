 			*(const char **)opt->value = (const char *)NULL;
 			return 0;
 		}
-		if (!p->opt && p->argc <= 1)
+		if (opt->flags & PARSE_OPT_OPTARG && (!arg || *arg == '-')) {
+			*(const char **)opt->value = (const char *)opt->defval;
+			return 0;
+		}
+		if (!arg)
 			return opterror(opt, "requires a value", flags);
 		*(const char **)opt->value = get_arg(p);
 		return 0;
 
+	case OPTION_CALLBACK:
+		if (flags & OPT_UNSET)
+			return (*opt->callback)(opt, NULL, 1);
+		if (opt->flags & PARSE_OPT_OPTARG && (!arg || *arg == '-'))
+			return (*opt->callback)(opt, NULL, 0);
+		if (!arg)
+			return opterror(opt, "requires a value", flags);
+		return (*opt->callback)(opt, get_arg(p), 0);
+
 	case OPTION_INTEGER:
 		if (flags & OPT_UNSET) {
 			*(int *)opt->value = 0;
 			return 0;
 		}
-		if (!p->opt && p->argc <= 1)
+		if (opt->flags & PARSE_OPT_OPTARG && (!arg || !isdigit(*arg))) {
+			*(int *)opt->value = opt->defval;
+			return 0;
+		}
+		if (!arg)
 			return opterror(opt, "requires a value", flags);
 		*(int *)opt->value = strtol(get_arg(p), (char **)&s, 10);
 		if (*s)
