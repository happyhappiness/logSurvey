			strbuf_addch(&buf, '\n');
		}

		if (fwrite(buf.buf, 1, buf.len, output) != buf.len)
			die_errno("cannot write output");

