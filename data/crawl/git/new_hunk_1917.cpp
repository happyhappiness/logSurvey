			} while (ack);
			flushes--;
			if (got_continue && MAX_IN_VAIN < in_vain) {
				print_verbose(args, "giving up");
				break; /* give up */
			}
		}
