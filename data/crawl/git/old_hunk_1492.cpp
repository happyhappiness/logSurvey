		}
	}

	hold_lock_file_for_update(&lock, filename, LOCK_DIE_ON_ERROR);
	res = write_locked_index(&result, &lock, COMMIT_LOCK);
	discard_index(&result);

	if (res)
		return error("Could not write temporary index to %s", filename);

	return 0;
}
