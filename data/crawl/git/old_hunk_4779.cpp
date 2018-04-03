		strbuf_release(&sob);
	}

	if (fwrite(sb.buf, 1, sb.len, fp) < sb.len)
		die_errno("could not write commit template");

	strbuf_release(&sb);
