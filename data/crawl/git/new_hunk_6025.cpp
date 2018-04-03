				break;
			/* FALLTHROUGH */
		case OPTION_STRING:
			if (opts->argh)
				pos += usage_argh(opts);
			else {
				if (opts->flags & PARSE_OPT_OPTARG)
					if (opts->long_name)
						pos += fprintf(stderr, "[=...]");
