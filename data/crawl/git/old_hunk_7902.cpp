	fprintf(pack_pipe, "-%s\n", sha1_to_hex(commit->object.sha1));
}

static void do_rev_list(int create_full_pack)
{
	int i;
	struct rev_info revs;

	if (create_full_pack)
		use_thin_pack = 0; /* no point doing it */
	init_revisions(&revs, NULL);
