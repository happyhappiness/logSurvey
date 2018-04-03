	add_refspec(refspec.buf);
}

static void setup_default_push_refspecs(void)
{
	git_config(git_default_config, NULL);
	switch (push_default) {
	default:
	case PUSH_DEFAULT_MATCHING:
		add_refspec(":");
		break;
