	diffcore_std(&opts);
	diff_flush(&opts);

	printf("\n");
	print_signature();
}

static const char *clean_message_id(const char *msg_id)
