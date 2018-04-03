 			break;
 		case OPTION_INTEGER:
 			if (opts->flags & PARSE_OPT_OPTARG)
-				pos += fprintf(stderr, "[<n>]");
+				if (opts->long_name)
+					pos += fprintf(stderr, "[=<n>]");
+				else
+					pos += fprintf(stderr, "[<n>]");
 			else
 				pos += fprintf(stderr, " <n>");
 			break;
