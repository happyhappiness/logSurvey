	if (!msg)
		strbuf_addstr(&reflog_message, getenv("GIT_REFLOG_ACTION"));
	else {
		printf("%s\n", msg);
		strbuf_addf(&reflog_message, "%s: %s",
			getenv("GIT_REFLOG_ACTION"), msg);
	}
	if (squash) {
		squash_message();
	} else {
		if (!merge_msg.len)
			printf("No merge message -- not updating HEAD\n");
		else {
			const char *argv_gc_auto[] = { "gc", "--auto", NULL };
