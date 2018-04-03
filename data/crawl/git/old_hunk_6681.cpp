	fill_filespec(one, sha1, mode);
	diff_queue(&diff_queued_diff, one, two)->is_unmerged = 1;
}
