	return 1;
}

static int prepare_to_commit(const char *index_file, const char *prefix,
			     struct wt_status *s)
{
	struct stat statbuf;
	int commitable, saved_color_setting;
	struct strbuf sb = STRBUF_INIT;
	char *buffer;
