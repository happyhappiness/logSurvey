		die("Invalid ref name or SHA1 expression: %s", from);

	read_next_command();
}

static struct hash_list *cmd_merge(unsigned int *count)
