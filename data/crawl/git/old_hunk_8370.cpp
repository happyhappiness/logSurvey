
static struct lock_file packed;

int cmd_pack_refs(int argc, const char **argv, const char *prefix)
{
	int fd, i;
	struct pack_refs_cb_data cbdata;

	memset(&cbdata, 0, sizeof(cbdata));

	cbdata.prune = 1;
	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];
		if (!strcmp(arg, "--prune")) {
			cbdata.prune = 1; /* now the default */
			continue;
		}
		if (!strcmp(arg, "--no-prune")) {
			cbdata.prune = 0;
			continue;
		}
		if (!strcmp(arg, "--all")) {
			cbdata.all = 1;
			continue;
		}
		/* perhaps other parameters later... */
