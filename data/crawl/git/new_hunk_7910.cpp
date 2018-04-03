
static void create_pack_file(void)
{
	/* Pipe from rev-list to pack-objects
	 */
	int lp_pipe[2];
	pid_t pid_rev_list;
	struct child_process pack_objects;
	int create_full_pack = (nr_our_refs == want_obj.nr && !have_obj.nr);
	char data[8193], progress[128];
	char abort_msg[] = "aborting due to possible repository "
		"corruption on the remote side.";
	int buffered = -1;
	const char *argv[10];
	int arg = 0;

	if (pipe(lp_pipe) < 0)
		die("git-upload-pack: unable to create pipe");
