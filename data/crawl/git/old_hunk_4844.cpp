		else
			die("You have not concluded your merge (MERGE_HEAD exists).");
	}
	resolve_undo_clear();

	if (verbosity < 0)
