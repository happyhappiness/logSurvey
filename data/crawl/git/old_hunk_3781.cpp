static const char *junk_work_tree;
static const char *junk_git_dir;
static pid_t junk_pid;

static void remove_junk(void)
{
	struct strbuf sb = STRBUF_INIT;
	if (getpid() != junk_pid)
		return;
	if (junk_git_dir) {
