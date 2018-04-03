		argv_array_clear(&paths);
	}

	switch (resume) {
	case RESUME_FALSE:
		am_run(&state);
		break;
	case RESUME_RESOLVED:
		am_resolve(&state);
		break;
	default:
		die("BUG: invalid resume value");
	}

	am_state_release(&state);
