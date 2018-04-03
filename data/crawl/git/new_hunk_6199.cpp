	return 0;
}

int send_pack(struct send_pack_args *args,
	      int fd[], struct child_process *conn,
	      struct ref *remote_refs,
	      struct extra_have_objects *extra_have)
{
	int in = fd[0];
	int out = fd[1];
	struct ref *ref;
	int new_refs;
	int ask_for_status_report = 0;
	int allow_deleting_refs = 0;
	int expect_status_report = 0;
	int ret;

	/* Does the other end support the reporting? */
	if (server_supports("report-status"))
		ask_for_status_report = 1;
	if (server_supports("delete-refs"))
		allow_deleting_refs = 1;

	if (!remote_refs) {
		fprintf(stderr, "No refs in common and none specified; doing nothing.\n"
			"Perhaps you should specify a branch such as 'master'.\n");
		return 0;
	}

