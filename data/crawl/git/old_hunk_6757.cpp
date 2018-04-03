		 * Since stderr is set to linebuffered mode, the
		 * logging of different processes will not overlap
		 */
		fprintf(stderr, "[%d] ", (int)getpid());
		vfprintf(stderr, err, params);
		fputc('\n', stderr);
	}
