static void finish_commit(struct commit *commit);
static void show_commit(struct commit *commit)
{
	if (show_timestamp)
		printf("%lu ", commit->date);
	if (header_prefix)
