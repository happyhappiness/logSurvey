		goto found_result;
	}

	/* TODO: */
	result = error("notes_merge() cannot yet handle real merges.");

found_result:
	free_commit_list(bases);
