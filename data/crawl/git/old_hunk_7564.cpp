				lock_flags = 0;
			}
			XML_ParserFree(parser);
		}
	} else {
		fprintf(stderr, "Unable to start PROPFIND request\n");
	}

	strbuf_release(&out_buffer.buf);
