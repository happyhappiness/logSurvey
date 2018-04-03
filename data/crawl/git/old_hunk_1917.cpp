			} while (ack);
			flushes--;
			if (got_continue && MAX_IN_VAIN < in_vain) {
				if (args->verbose)
					fprintf(stderr, "giving up\n");
				break; /* give up */
			}
		}
