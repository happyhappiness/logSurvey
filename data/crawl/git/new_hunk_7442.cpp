	return 0;
}

void log_write_email_headers(struct rev_info *opt, const char *name,
			     const char **subject_p, const char **extra_headers_p)
{
	const char *subject = NULL;
	const char *extra_headers = opt->extra_headers;
	if (opt->total > 0) {
		static char buffer[64];
		snprintf(buffer, sizeof(buffer),
			 "Subject: [%s %0*d/%d] ",
			 opt->subject_prefix,
			 digits_in_number(opt->total),
			 opt->nr, opt->total);
		subject = buffer;
	} else if (opt->total == 0 && opt->subject_prefix && *opt->subject_prefix) {
		static char buffer[256];
		snprintf(buffer, sizeof(buffer),
			 "Subject: [%s] ",
			 opt->subject_prefix);
		subject = buffer;
	} else {
		subject = "Subject: ";
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
		snprintf(subject_buffer, sizeof(subject_buffer) - 1,
			 "%s"
			 "MIME-Version: 1.0\n"
			 "Content-Type: multipart/mixed;"
			 " boundary=\"%s%s\"\n"
			 "\n"
			 "This is a multi-part message in MIME "
			 "format.\n"
			 "--%s%s\n"
			 "Content-Type: text/plain; "
			 "charset=UTF-8; format=fixed\n"
			 "Content-Transfer-Encoding: 8bit\n\n",
			 extra_headers ? extra_headers : "",
			 mime_boundary_leader, opt->mime_boundary,
			 mime_boundary_leader, opt->mime_boundary);
		extra_headers = subject_buffer;

		snprintf(buffer, sizeof(buffer) - 1,
			 "--%s%s\n"
			 "Content-Type: text/x-patch;"
			 " name=\"%s.diff\"\n"
			 "Content-Transfer-Encoding: 8bit\n"
			 "Content-Disposition: %s;"
			 " filename=\"%s.diff\"\n\n",
			 mime_boundary_leader, opt->mime_boundary,
			 name,
			 opt->no_inline ? "attachment" : "inline",
			 name);
		opt->diffopt.stat_sep = buffer;
	}
	*subject_p = subject;
	*extra_headers_p = extra_headers;
}

void show_log(struct rev_info *opt, const char *sep)
{
	struct strbuf msgbuf;
