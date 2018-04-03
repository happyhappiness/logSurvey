		printf("Message-Id: <%s>\n", opt->message_id);
		graph_show_oneline(opt->graph);
	}
	if (opt->ref_message_id) {
		printf("In-Reply-To: <%s>\nReferences: <%s>\n",
		       opt->ref_message_id, opt->ref_message_id);
		graph_show_oneline(opt->graph);
	}
	if (opt->mime_boundary) {
		static char subject_buffer[1024];
		static char buffer[1024];
		*need_8bit_cte_p = -1; /* NEVER */
		snprintf(subject_buffer, sizeof(subject_buffer) - 1,
			 "%s"
