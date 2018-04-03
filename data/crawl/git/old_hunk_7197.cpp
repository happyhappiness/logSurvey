
static const char sign_off_header[] = "Signed-off-by: ";

static int prepare_to_commit(const char *index_file, const char *prefix)
{
	struct stat statbuf;
