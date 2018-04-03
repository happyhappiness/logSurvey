			else
				pos += fprintf(stderr, " <n>");
			break;
		case OPTION_STRING:
		case OPTION_CALLBACK:
			if (opts->argh) {
				if (opts->flags & PARSE_OPT_OPTARG)
					pos += fprintf(stderr, " [<%s>]", opts->argh);
