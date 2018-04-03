	return NULL;
}

static struct lock_file msg_file;
static int msg_fd;

static void add_to_msg(const char *string)
{
	int len = strlen(string);
	if (write_in_full(msg_fd, string, len) < 0)
		die_errno ("Could not write to MERGE_MSG");
}

static void add_message_to_msg(const char *message)
{
	const char *p = message;
	while (*p && (*p != '\n' || p[1] != '\n'))
		p++;

	if (!*p)
		add_to_msg(sha1_to_hex(commit->object.sha1));

	p += 2;
	add_to_msg(p);
	return;
}

static void set_author_ident_env(const char *message)
