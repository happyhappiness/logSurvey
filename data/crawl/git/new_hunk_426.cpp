	int blamed_lines;
};

static int compare_commits_by_reverse_commit_date(const void *a,
						  const void *b,
						  void *c)
{
	return -compare_commits_by_commit_date(a, b, c);
}

/*
 * Fill the blob_sha1 field of an origin if it hasn't, so that later
 * call to fill_origin_blob() can use it to locate the data.  blob_sha1
