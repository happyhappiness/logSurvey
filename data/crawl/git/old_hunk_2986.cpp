		die("BUG: state file 'last' does not exist");
	state->last = strtol(sb.buf, NULL, 10);

	strbuf_release(&sb);
}

