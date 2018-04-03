	if (revs->reverse && revs->reflog_info)
		die("cannot combine --reverse with --walk-reflogs");

	return left;
}

