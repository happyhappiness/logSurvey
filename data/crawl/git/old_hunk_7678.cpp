	"# Write a tag message\n"
	"#\n";

static int git_tag_config(const char *var, const char *value)
{
	if (!strcmp(var, "user.signingkey")) {
		if (!value)
			die("user.signingkey without value");
		if (strlcpy(signingkey, value, sizeof(signingkey))
						>= sizeof(signingkey))
			die("user.signingkey value too long");
		return 0;
	}

