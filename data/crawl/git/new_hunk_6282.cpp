			}
		} else {
			if (buf.len)
				printf("%s%c", buf.buf, info->hdr_termination);
		}
		strbuf_release(&buf);
	} else {
