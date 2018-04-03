"    --bisect-all"
;

static void finish_commit(struct commit *commit, void *data);
static void show_commit(struct commit *commit, void *data)
{
	struct rev_list_info *info = data;
	struct rev_info *revs = info->revs;

	graph_show_commit(revs->graph);

	if (info->show_timestamp)
		printf("%lu ", commit->date);
	if (info->header_prefix)
		fputs(info->header_prefix, stdout);

	if (!revs->graph) {
		if (commit->object.flags & BOUNDARY)
