	}
	if (finish_command(&rls))
		return error ("pack-objects died");
	return 0;
}
