	if (rev.diffopt.exit_with_status)
		result = rev.diffopt.has_changes;

	if (1 < rev.diffopt.skip_stat_unmatch)
		refresh_index_quietly();
	return result;
}
