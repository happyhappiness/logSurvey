			ret = 1;
		} else {
			struct strbuf buf = STRBUF_INIT;
			printf("Deleted %sbranch %s (was %s).\n", remote,
			       bname.buf,
			       find_unique_abbrev(sha1, DEFAULT_ABBREV));
			strbuf_addf(&buf, "branch.%s", bname.buf);
