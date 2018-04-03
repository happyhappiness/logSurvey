		while (strbuf_getline_lf(&oneline, stdin) != EOF &&
		       !oneline.len)
			; /* discard blanks */
		insert_one_record(log, v, oneline.buf);
	}
	strbuf_release(&author);
	strbuf_release(&oneline);
}

