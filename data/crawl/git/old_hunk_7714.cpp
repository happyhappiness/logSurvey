	}

	if (fwrite(sb.buf, 1, sb.len, fp) < sb.len)
		die("could not write commit template: %s\n",
		    strerror(errno));

	strbuf_release(&sb);

