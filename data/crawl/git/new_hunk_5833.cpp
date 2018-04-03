{
	int len = strlen(string);
	if (write_in_full(msg_fd, string, len) < 0)
		die_errno ("Could not write to MERGE_MSG");
}

static void add_message_to_msg(const char *message)
