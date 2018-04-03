	close(rls.in);
	if (finish_command(&rls))
		return error ("pack-objects died");
	if (!bundle_to_stdout)
		commit_lock_file(&lock);
	return 0;
}

