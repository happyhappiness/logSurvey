		 (int)(email_end - email_start - 1), email_start + 1);
}

int cmd_format_patch(int argc, const char **argv, const char *prefix)
{
	struct commit *commit;
