		}
		strbuf_trim(&line);
		rawargs = strbuf_detach(&line, NULL);
		if (split_cmdline(rawargs, &argv) == -1) {
			free(rawargs);
			continue;
		}
