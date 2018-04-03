	}

	printf("From %s Mon Sep 17 00:00:00 2001\n", name);
	if (opt->message_id)
		printf("Message-Id: <%s>\n", opt->message_id);
	if (opt->ref_message_id)
		printf("In-Reply-To: <%s>\nReferences: <%s>\n",
		       opt->ref_message_id, opt->ref_message_id);
	if (opt->mime_boundary) {
		static char subject_buffer[1024];
		static char buffer[1024];
