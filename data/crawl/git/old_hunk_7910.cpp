
static void create_pack_file(void)
{
	/* Pipes between rev-list to pack-objects, pack-objects to us
	 * and pack-objects error stream for progress bar.
	 */
	int lp_pipe[2], pu_pipe[2], pe_pipe[2];
	pid_t pid_rev_list, pid_pack_objects;
	int create_full_pack = (nr_our_refs == want_obj.nr && !have_obj.nr);
	char data[8193], progress[128];
	char abort_msg[] = "aborting due to possible repository "
		"corruption on the remote side.";
	int buffered = -1;

	if (pipe(lp_pipe) < 0)
		die("git-upload-pack: unable to create pipe");
