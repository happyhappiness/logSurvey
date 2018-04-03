"    --bisect-all"
;

static int show_timestamp;
static int hdr_termination;
static const char *header_prefix;

static void finish_commit(struct commit *commit, void *data);
static void show_commit(struct commit *commit, void *data)
{
	struct rev_info *revs = data;

	graph_show_commit(revs->graph);

	if (show_timestamp)
		printf("%lu ", commit->date);
	if (header_prefix)
		fputs(header_prefix, stdout);

	if (!revs->graph) {
		if (commit->object.flags & BOUNDARY)
