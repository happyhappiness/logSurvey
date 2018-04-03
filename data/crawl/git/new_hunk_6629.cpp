			die("this should not happen, your snprintf is broken");
	}

	error("%s", sb.buf);
	strbuf_release(&sb);
	return 1;
}
