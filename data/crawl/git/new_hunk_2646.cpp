			output_header_lines(fout, "Subject", hdr);
		} else if (!strcmp(header[i], "From")) {
			cleanup_space(hdr);
			handle_from(mi, hdr);
			fprintf(fout, "Author: %s\n", mi->name.buf);
			fprintf(fout, "Email: %s\n", mi->email.buf);
		} else {
			cleanup_space(hdr);
			fprintf(fout, "%s: %s\n", header[i], hdr->buf);
