	for (i = 0;
	     i < ARRAY_SIZE(warn_unconfigured_deny_delete_current_msg);
	     i++)
		warning(warn_unconfigured_deny_delete_current_msg[i]);
}

static const char *update(struct command *cmd)