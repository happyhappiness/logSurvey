	case RESUME_ABORT:
		am_abort(&state);
		break;
	default:
		die("BUG: invalid resume value");
	}

	am_state_release(&state);

	return 0;
}
