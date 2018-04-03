	case RESUME_SKIP:
		am_skip(&state);
		break;
	default:
		die("BUG: invalid resume value");
	}