
#define SUMMARY_WIDTH (2 * DEFAULT_ABBREV + 3)

static void print_ref_status(char flag, const char *summary, struct ref *to, struct ref *from, const char *msg)
{
	fprintf(stderr, " %c %-*s ", flag, SUMMARY_WIDTH, summary);
	if (from)
		fprintf(stderr, "%s -> %s", prettify_refname(from->name), prettify_refname(to->name));
	else
		fputs(prettify_refname(to->name), stderr);
	if (msg) {
		fputs(" (", stderr);
		fputs(msg, stderr);
		fputc(')', stderr);
	}
	fputc('\n', stderr);
}

static const char *status_abbrev(unsigned char sha1[20])
{
	return find_unique_abbrev(sha1, DEFAULT_ABBREV);
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
