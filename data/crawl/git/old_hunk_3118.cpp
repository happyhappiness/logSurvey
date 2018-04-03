
void print_signature_buffer(const struct signature_check *sigc, unsigned flags)
{
	if (flags & GPG_VERIFY_VERBOSE && sigc->payload)
		fputs(sigc->payload, stdout);

	if (sigc->gpg_output)
		fputs(sigc->gpg_output, stderr);
}

/*
