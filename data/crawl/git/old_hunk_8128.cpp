	if (rev.diffopt.exit_with_status)
		result = rev.diffopt.has_changes;

	if ((rev.diffopt.output_format & DIFF_FORMAT_PATCH)
	    && (1 < rev.diffopt.skip_stat_unmatch))
		printf("Warning: %d path%s touched but unmodified. "
		       "Consider running git-status.\n",
		       rev.diffopt.skip_stat_unmatch - 1,
		       rev.diffopt.skip_stat_unmatch == 2 ? "" : "s");
	return result;
}
