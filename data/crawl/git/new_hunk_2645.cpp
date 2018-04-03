				cleanup_subject(mi, hdr);
				cleanup_space(hdr);
			}
			output_header_lines(mi->output, "Subject", hdr);
		} else if (!strcmp(header[i], "From")) {
			cleanup_space(hdr);
			handle_from(mi, hdr);
			fprintf(mi->output, "Author: %s\n", mi->name.buf);
			fprintf(mi->output, "Email: %s\n", mi->email.buf);
		} else {
			cleanup_space(hdr);
			fprintf(mi->output, "%s: %s\n", header[i], hdr->buf);
		}
	}
	fprintf(mi->output, "\n");
}

static int mailinfo(struct mailinfo *mi, const char *msg, const char *patch)
{
	int peek;
	struct strbuf line = STRBUF_INIT;

	cmitmsg = fopen(msg, "w");
	if (!cmitmsg) {
		perror(msg);
