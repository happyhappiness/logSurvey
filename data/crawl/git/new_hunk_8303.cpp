int get_recover = 0;
static unsigned char current_commit_sha1[20];

void pull_say(const char *fmt, const char *hex)
{
	if (get_verbosely)
		fprintf(stderr, fmt, hex);
