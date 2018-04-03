 		return 0;
 
 	case OPTION_CALLBACK:
-		if (flags & OPT_UNSET)
+		if (unset)
 			return (*opt->callback)(opt, NULL, 1);
-		if (opt->flags & PARSE_OPT_NOARG) {
-			if (p->opt && !(flags & OPT_SHORT))
-				return opterror(opt, "takes no value", flags);
+		if (opt->flags & PARSE_OPT_NOARG)
 			return (*opt->callback)(opt, NULL, 0);
-		}
 		if (opt->flags & PARSE_OPT_OPTARG && (!arg || *arg == '-'))
 			return (*opt->callback)(opt, NULL, 0);
 		if (!arg)
 			return opterror(opt, "requires a value", flags);
 		return (*opt->callback)(opt, get_arg(p), 0);
 
 	case OPTION_INTEGER:
-		if (flags & OPT_UNSET) {
+		if (unset) {
 			*(int *)opt->value = 0;
 			return 0;
 		}
