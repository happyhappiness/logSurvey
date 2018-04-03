			/* FALLTHROUGH */
		case OPTION_BOOLEAN:
		case OPTION_BIT:
		case OPTION_NEGBIT:
		case OPTION_SET_INT:
		case OPTION_SET_PTR:
			return opterror(opt, "takes no value", flags);
