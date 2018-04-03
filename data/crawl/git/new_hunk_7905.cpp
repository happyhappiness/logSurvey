 fail:
	if (pack_objects.pid)
		kill(pack_objects.pid, SIGKILL);
	if (rev_list.pid)
		kill(rev_list.pid, SIGKILL);
	send_client_data(3, abort_msg, sizeof(abort_msg));
	die("git-upload-pack: %s", abort_msg);
}