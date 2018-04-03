
static const char *read_commit_message(const char *name)
{
	const char *out_enc;
	struct commit *commit;

	commit = lookup_commit_reference_by_name(name);
	if (!commit)
		die(_("could not lookup commit %s"), name);
	out_enc = get_commit_output_encoding();
	return logmsg_reencode(commit, out_enc);
}

static int parse_and_validate_options(int argc, const char *argv[],
