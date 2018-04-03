	}
}

static void check_aliased_update(struct command *cmd, struct string_list *list)
{
	struct string_list_item *item;
	struct command *dst_cmd;
	unsigned char sha1[20];
	char cmd_oldh[41], cmd_newh[41], dst_oldh[41], dst_newh[41];
	int flag;

	const char *dst_name = resolve_ref(cmd->ref_name, sha1, 0, &flag);

	if (!(flag & REF_ISSYMREF))
		return;

	if ((item = string_list_lookup(dst_name, list)) == NULL)
		return;

	cmd->skip_update = 1;

	dst_cmd = (struct command *) item->util;

	if (!hashcmp(cmd->old_sha1, dst_cmd->old_sha1) &&
	    !hashcmp(cmd->new_sha1, dst_cmd->new_sha1))
		return;

	dst_cmd->skip_update = 1;

	strcpy(cmd_oldh, find_unique_abbrev(cmd->old_sha1, DEFAULT_ABBREV));
	strcat(cmd_newh, find_unique_abbrev(cmd->new_sha1, DEFAULT_ABBREV));
	strcpy(dst_oldh, find_unique_abbrev(dst_cmd->old_sha1, DEFAULT_ABBREV));
	strcat(dst_newh, find_unique_abbrev(dst_cmd->new_sha1, DEFAULT_ABBREV));
	rp_error("refusing inconsistent update between symref '%s' (%s..%s) and"
		 " its target '%s' (%s..%s)",
		 cmd->ref_name, cmd_oldh, cmd_newh,
		 dst_cmd->ref_name, dst_oldh, dst_newh);

	cmd->error_string = dst_cmd->error_string =
		"inconsistent aliased update";
}

static void check_aliased_updates(struct command *commands)
{
	struct command *cmd;
	struct string_list ref_list = { NULL, 0, 0, 0 };

	for (cmd = commands; cmd; cmd = cmd->next) {
		struct string_list_item *item =
			string_list_append(cmd->ref_name, &ref_list);
		item->util = (void *)cmd;
	}
	sort_string_list(&ref_list);

	for (cmd = commands; cmd; cmd = cmd->next)
		check_aliased_update(cmd, &ref_list);

	string_list_clear(&ref_list, 0);
}

static void execute_commands(struct command *commands, const char *unpacker_error)
{
	struct command *cmd;
