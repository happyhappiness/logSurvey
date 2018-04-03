 		return opterror(opt, "takes no value", flags);
 	if (unset && (opt->flags & PARSE_OPT_NONEG))
 		return opterror(opt, "isn't available", flags);
-
-	if (!(flags & OPT_SHORT) && p->opt) {
-		switch (opt->type) {
-		case OPTION_CALLBACK:
-			if (!(opt->flags & PARSE_OPT_NOARG))
-				break;
-			/* FALLTHROUGH */
-		case OPTION_BOOLEAN:
-		case OPTION_BIT:
-		case OPTION_NEGBIT:
-		case OPTION_SET_INT:
-		case OPTION_SET_PTR:
-			return opterror(opt, "takes no value", flags);
-		default:
-			break;
-		}
-	}
+	if (!(flags & OPT_SHORT) && p->opt && (opt->flags & PARSE_OPT_NOARG))
+		return opterror(opt, "takes no value", flags);
 
 	switch (opt->type) {
 	case OPTION_BIT: