				break;
			/* FALLTHROUGH */
		case OPTION_STRING:
			if (opts->argh) {
				if (opts->flags & PARSE_OPT_OPTARG)
					if (opts->long_name)
						pos += fprintf(stderr, "[=<%s>]", opts->argh);
					else
						pos += fprintf(stderr, "[<%s>]", opts->argh);
				else
					pos += fprintf(stderr, " <%s>", opts->argh);
			} else {
				if (opts->flags & PARSE_OPT_OPTARG)
					if (opts->long_name)
						pos += fprintf(stderr, "[=...]");
