	return run_command(&hook);
}

static const char sign_off_header[] = "Signed-off-by: ";

static int prepare_log_message(const char *index_file, const char *prefix)
{
	struct stat statbuf;
	int commitable, saved_color_setting;
	struct strbuf sb;
	char *buffer;
	FILE *fp;

	strbuf_init(&sb, 0);
	if (message.len) {
		strbuf_addbuf(&sb, &message);
