	default:
		die("bug: unhandled diff status %c", status);
	}
	fprintf(s->fp, "\n");
	strbuf_release(&onebuf);
	strbuf_release(&twobuf);
