		case OPTION_STRING:
			if (opts->argh) {
				if (opts->flags & PARSE_OPT_OPTARG)
					pos += fprintf(stderr, " [<%s>]", opts->argh);
				else
					pos += fprintf(stderr, " <%s>", opts->argh);
			} else {
				if (opts->flags & PARSE_OPT_OPTARG)
					pos += fprintf(stderr, " [...]");
				else
					pos += fprintf(stderr, " ...");
			}
