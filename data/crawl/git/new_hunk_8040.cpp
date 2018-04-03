		die("git-fetch-pack: fetch failed.");

 all_done:
	return ref;
}

static int remove_duplicates(int nr_heads, char **heads)
