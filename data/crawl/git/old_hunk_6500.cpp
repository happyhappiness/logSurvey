	return !strcmp(head, ref);
}

static const char *update(struct command *cmd)
{
	const char *name = cmd->ref_name;
