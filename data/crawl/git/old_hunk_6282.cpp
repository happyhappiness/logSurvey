			}
		} else {
			if (buf.len)
				printf("%s%c", buf.buf, hdr_termination);
		}
		strbuf_release(&buf);
	} else {
