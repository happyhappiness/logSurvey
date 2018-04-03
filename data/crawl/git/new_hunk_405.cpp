		break;
	case GREP_PATTERN_TYPE_UNSPECIFIED:
		break;
	default:
		die("BUG: Added a new grep pattern type without updating switch statement");
	}

	for (pattern = opt->pattern_list; pattern != NULL;