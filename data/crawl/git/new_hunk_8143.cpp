static uintmax_t next_mark;
static struct dbuf new_data;

static void write_branch_report(FILE *rpt, struct branch *b)
{
	fprintf(rpt, "%s:\n", b->name);

	fprintf(rpt, "  status      :");
	if (b->active)
		fputs(" active", rpt);
	if (b->branch_tree.tree)
		fputs(" loaded", rpt);
	if (is_null_sha1(b->branch_tree.versions[1].sha1))
		fputs(" dirty", rpt);
	fputc('\n', rpt);

	fprintf(rpt, "  tip commit  : %s\n", sha1_to_hex(b->sha1));
	fprintf(rpt, "  old tree    : %s\n", sha1_to_hex(b->branch_tree.versions[0].sha1));
	fprintf(rpt, "  cur tree    : %s\n", sha1_to_hex(b->branch_tree.versions[1].sha1));
	fprintf(rpt, "  commit clock: %" PRIuMAX "\n", b->last_commit);

	fputs("  last pack   : ", rpt);
	if (b->pack_id < MAX_PACK_ID)
		fprintf(rpt, "%u", b->pack_id);
	fputc('\n', rpt);

	fputc('\n', rpt);
}

static void write_crash_report(const char *err, va_list params)
{
	char *loc = git_path("fast_import_crash_%d", getpid());
	FILE *rpt = fopen(loc, "w");
	struct branch *b;
	unsigned long lu;

	if (!rpt) {
		error("can't write crash report %s: %s", loc, strerror(errno));
		return;
	}

	fprintf(stderr, "fast-import: dumping crash report to %s\n", loc);

	fprintf(rpt, "fast-import crash report:\n");
	fprintf(rpt, "    fast-import process: %d\n", getpid());
	fprintf(rpt, "    parent process     : %d\n", getppid());
	fprintf(rpt, "    at %s\n", show_date(time(NULL), 0, DATE_LOCAL));
	fputc('\n', rpt);

	fputs("fatal: ", rpt);
	vfprintf(rpt, err, params);
	fputc('\n', rpt);

	fputc('\n', rpt);
	fputs("Active Branch LRU\n", rpt);
	fputs("-----------------\n", rpt);
	fprintf(rpt, "    active_branches = %lu cur, %lu max\n",
		cur_active_branches,
		max_active_branches);
	fputc('\n', rpt);
	fputs("  pos  clock name\n", rpt);
	fputs("  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", rpt);
	for (b = active_branches, lu = 0; b; b = b->active_next_branch)
		fprintf(rpt, "  %2lu) %6" PRIuMAX" %s\n",
			++lu, b->last_commit, b->name);

	fputc('\n', rpt);
	fputs("Inactive Branches\n", rpt);
	fputs("-----------------\n", rpt);
	for (lu = 0; lu < branch_table_sz; lu++) {
		for (b = branch_table[lu]; b; b = b->table_next_branch)
			write_branch_report(rpt, b);
	}

	fputc('\n', rpt);
	fputs("-------------------\n", rpt);
	fputs("END OF CRASH REPORT\n", rpt);
	fclose(rpt);
}

static NORETURN void die_nicely(const char *err, va_list params)
{
	static int zombie;

	fputs("fatal: ", stderr);
	vfprintf(stderr, err, params);
	fputc('\n', stderr);

	if (!zombie) {
		zombie = 1;
		write_crash_report(err, params);
	}

	exit(128);
}

static void alloc_objects(unsigned int cnt)
{
