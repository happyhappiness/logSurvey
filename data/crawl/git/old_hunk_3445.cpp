		rp_error("%s", refuse_unconfigured_deny_delete_current_msg[i]);
}

static const char *update(struct command *cmd)
{
	const char *name = cmd->ref_name;
	struct strbuf namespaced_name_buf = STRBUF_INIT;