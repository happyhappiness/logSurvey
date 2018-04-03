
static int run_gpg_verify(const char *buf, unsigned long size, int verbose)
{
	struct signature_check sigc;
	int len;

	memset(&sigc, 0, sizeof(sigc));

	len = parse_signature(buf, size);
	if (verbose)
		write_in_full(1, buf, len);

	if (size == len)
		return error("no signature found");

	check_signature(buf, len, buf + len, size - len, &sigc);
	fputs(sigc.gpg_output, stderr);

	signature_check_clear(&sigc);
	return sigc.result != 'G' && sigc.result != 'U';
}

static int verify_tag(const char *name, int verbose)
