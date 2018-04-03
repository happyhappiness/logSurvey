	add_refspec(refspec.buf);
}

static void setup_default_push_refspecs(void)
{
	git_config(git_default_config, NULL);
	switch (push_default) {
	case PUSH_DEFAULT_UNSPECIFIED:
		/* fallthrough */

	case PUSH_DEFAULT_MATCHING: