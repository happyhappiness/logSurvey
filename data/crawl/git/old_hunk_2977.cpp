		argv_array_clear(&paths);
	}

	am_run(&state);

	am_state_release(&state);
