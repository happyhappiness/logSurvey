 		case OPTION_STRING:
 			if (opts->argh) {
 				if (opts->flags & PARSE_OPT_OPTARG)
-					pos += fprintf(stderr, " [<%s>]", opts->argh);
+					if (opts->long_name)
+						pos += fprintf(stderr, "[=<%s>]", opts->argh);
+					else
+						pos += fprintf(stderr, "[<%s>]", opts->argh);
 				else
 					pos += fprintf(stderr, " <%s>", opts->argh);
 			} else {
 				if (opts->flags & PARSE_OPT_OPTARG)
-					pos += fprintf(stderr, " [...]");
+					if (opts->long_name)
+						pos += fprintf(stderr, "[=...]");
+					else
+						pos += fprintf(stderr, "[...]");
 				else
 					pos += fprintf(stderr, " ...");
 			}
