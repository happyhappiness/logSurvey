
#define SUMMARY_WIDTH (2 * DEFAULT_ABBREV + 3)

static int do_send_pack(int in, int out, struct remote *remote, const char *dest, int nr_refspec, const char **refspec)
{
	struct ref *ref;
	int new_refs;
	int ret = 0;
	int ask_for_status_report = 0;
	int allow_deleting_refs = 0;
	int expect_status_report = 0;
	int shown_dest = 0;
	int flags = MATCH_REFS_NONE;

	if (args.send_all)
