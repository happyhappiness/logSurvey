		die("git-fetch-pack: fetch failed.");

 all_done:
	while (ref) {
		printf("%s %s\n",
		       sha1_to_hex(ref->old_sha1), ref->name);
		ref = ref->next;
	}
	return 0;
}

static int remove_duplicates(int nr_heads, char **heads)
