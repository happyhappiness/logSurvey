			} while (ack);
			flushes--;
			if (got_continue && MAX_IN_VAIN < in_vain) {
				if (args.verbose)
					fprintf(stderr, "giving up\n");
				break; /* give up */
			}
		}
	}
done:
	packet_write(fd[1], "done\n");
	if (args.verbose)
		fprintf(stderr, "done\n");
	if (retval != 0) {
		multi_ack = 0;
