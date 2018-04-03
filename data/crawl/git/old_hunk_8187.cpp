			continue;

		if (!memcmp(header[i], "Subject", 7)) {
			sub = cleanup_subject(hdr);
			cleanup_space(sub);
			fprintf(fout, "Subject: %s\n", sub);
		} else if (!memcmp(header[i], "From", 4)) {
			handle_from(hdr);
			fprintf(fout, "Author: %s\n", name);
