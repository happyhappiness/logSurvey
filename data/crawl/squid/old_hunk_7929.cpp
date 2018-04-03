	    fast_mode = (sb.st_mtime <= last_clean) ? 1 : 0;
	}
    }
    if (fast_mode)
	debug(0, 1, "Rebuilding in FAST MODE.\n");

    /* go to top of the file */
    (void) lseek(swaplog_fd, 0L, SEEK_SET);

    memset(line_in, '\0', 4096);
    while (fgets(line_in, 4096, swaplog_stream)) {

	if ((linecount++ & 0x7F) == 0)	/* update current time */
	    cached_curtime = time(NULL);

	if ((linecount & 0xFFF) == 0)
	    debug(0, 1, "  %7d Lines read so far.\n", linecount);

	debug(0, 10, "line_in: %s", line_in);
	if ((line_in[0] == '\0') || (line_in[0] == '\n') ||
	    (line_in[0] == '#'))
	    continue;		/* skip bad lines */
