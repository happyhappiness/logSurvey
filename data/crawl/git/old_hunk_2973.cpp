	case RESUME_RESOLVED:
		am_resolve(&state);
		break;
	default:
		die("BUG: invalid resume value");
	}