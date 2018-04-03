 fail:
	if (pack_objects.pid)
		kill(pack_objects.pid, SIGKILL);
	if (pid_rev_list)
		kill(pid_rev_list, SIGKILL);
	send_client_data(3, abort_msg, sizeof(abort_msg));
	die("git-upload-pack: %s", abort_msg);
}