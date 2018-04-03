				if (!c) {
					free(*argv);
					*argv = NULL;
					return -SPLIT_CMDLINE_BAD_ENDING;
				}
			}
			cmdline[dst++] = c;
