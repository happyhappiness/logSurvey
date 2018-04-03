	return !strcmp(head, ref);
}

static char *warn_unconfigured_deny_msg[] = {
	"Updating the currently checked out branch may cause confusion,",
	"as the index and work tree do not reflect changes that are in HEAD.",
	"As a result, you may see the changes you just pushed into it",
	"reverted when you run 'git diff' over there, and you may want",
	"to run 'git reset --hard' before starting to work to recover.",
	"",
	"You can set 'receive.denyCurrentBranch' configuration variable to",
	"'refuse' in the remote repository to forbid pushing into its",
	"current branch."
	"",
	"To allow pushing into the current branch, you can set it to 'ignore';",
	"but this is not recommended unless you arranged to update its work",
	"tree to match what you pushed in some other way.",
	"",
	"To squelch this message, you can set it to 'warn'.",
	"",
	"Note that the default will change in a future version of git",
	"to refuse updating the current branch unless you have the",
	"configuration variable set to either 'ignore' or 'warn'."
};

static void warn_unconfigured_deny(void)
{
	int i;
	for (i = 0; i < ARRAY_SIZE(warn_unconfigured_deny_msg); i++)
		warning(warn_unconfigured_deny_msg[i]);
}

static const char *update(struct command *cmd)
{
	const char *name = cmd->ref_name;
