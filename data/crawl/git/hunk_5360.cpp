 	default:
 		die("bug: unhandled diff status %c", status);
 	}
+	if (extra.len) {
+		color_fprintf(s->fp, color(WT_STATUS_HEADER, s), "%s", extra.buf);
+		strbuf_release(&extra);
+	}
 	fprintf(s->fp, "\n");
 	strbuf_release(&onebuf);
 	strbuf_release(&twobuf);
