		if (skip_prefix(sb.buf, "# User ", &str))
			fprintf(out, "From: %s\n", str);
		else if (skip_prefix(sb.buf, "# Date ", &str)) {
			unsigned long timestamp;
			long tz, tz2;
			char *end;

