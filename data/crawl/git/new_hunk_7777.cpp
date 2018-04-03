
#define SUMMARY_WIDTH (2 * DEFAULT_ABBREV + 3)

static void print_ref_status(char flag, const char *summary, struct ref *to, struct ref *from, const char *msg)
{
	fprintf(stderr, " %c %-*s ", flag, SUMMARY_WIDTH, summary);
	if (from)
		fprintf(stderr, "%s -> %s", prettify_ref(from), prettify_ref(to));
	else
		fputs(prettify_ref(to), stderr);
	if (msg) {
		fputs(" (", stderr);
		fputs(msg, stderr);
		fputc(')', stderr);
	}
	fputc('\n', stderr);
}

static const char *status_abbrev(unsigned char sha1[20])
{
	const char *abbrev;
	abbrev = find_unique_abbrev(sha1, DEFAULT_ABBREV);
	return abbrev ? abbrev : sha1_to_hex(sha1);
}

static void print_ok_ref_status(struct ref *ref)
{
	if (ref->deletion)
		print_ref_status('-', "[deleted]", ref, NULL, NULL);
	else if (is_null_sha1(ref->old_sha1))
		print_ref_status('*',
			(!prefixcmp(ref->name, "refs/tags/") ? "[new tag]" :
			  "[new branch]"),
			ref, ref->peer_ref, NULL);
	else {
		char quickref[84];
		char type;
		const char *msg;

		strcpy(quickref, status_abbrev(ref->old_sha1));
		if (ref->nonfastforward) {
			strcat(quickref, "...");
			type = '+';
			msg = "forced update";
		} else {
			strcat(quickref, "..");
			type = ' ';
			msg = NULL;
		}
		strcat(quickref, status_abbrev(ref->new_sha1));

		print_ref_status(type, quickref, ref, ref->peer_ref, msg);
	}
}

static void print_push_status(const char *dest, struct ref *refs)
{
	struct ref *ref;
	int shown_dest = 0;

	for (ref = refs; ref; ref = ref->next) {
		if (!ref->status)
			continue;
		if (ref->status == REF_STATUS_UPTODATE && !args.verbose)
			continue;

		if (!shown_dest) {
			fprintf(stderr, "To %s\n", dest);
			shown_dest = 1;
		}

		switch(ref->status) {
		case REF_STATUS_NONE:
			print_ref_status('X', "[no match]", ref, NULL, NULL);
			break;
		case REF_STATUS_REJECT_NODELETE:
			print_ref_status('!', "[rejected]", ref, NULL,
					"remote does not support deleting refs");
			break;
		case REF_STATUS_UPTODATE:
			print_ref_status('=', "[up to date]", ref,
					ref->peer_ref, NULL);
			break;
		case REF_STATUS_REJECT_NONFASTFORWARD:
			print_ref_status('!', "[rejected]", ref, ref->peer_ref,
					"non-fast forward");
			break;
		case REF_STATUS_OK:
			print_ok_ref_status(ref);
			break;
		}
	}
}

static int do_send_pack(int in, int out, struct remote *remote, const char *dest, int nr_refspec, const char **refspec)
{
	struct ref *ref;
	int new_refs;
	int ask_for_status_report = 0;
	int allow_deleting_refs = 0;
	int expect_status_report = 0;
	int flags = MATCH_REFS_NONE;

	if (args.send_all)
