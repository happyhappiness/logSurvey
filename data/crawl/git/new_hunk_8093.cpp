
int main(int argc, char **argv)
{
	struct strbuf buf;
	unsigned char result_sha1[20];

	if (argc != 1)
		usage("git-mktag < signaturefile");

	setup_git_directory();

	strbuf_init(&buf, 0);
	if (strbuf_read(&buf, 0, 4096) < 0) {
		die("could not read from stdin");
	}

	/* Verify it for some basic sanity: it needs to start with
	   "object <sha1>\ntype\ntagger " */
	if (verify_tag(buf.buf, buf.len) < 0)
		die("invalid tag signature file");

	if (write_sha1_file(buf.buf, buf.len, tag_type, result_sha1) < 0)
		die("unable to write tag file");

	strbuf_release(&buf);
	printf("%s\n", sha1_to_hex(result_sha1));
	return 0;
}
