				if (args.verbose && ack)
					fprintf(stderr, "got ack %d %s\n", ack,
							sha1_to_hex(result_sha1));
				if (ack == 1) {
					flushes = 0;
					multi_ack = 0;
					retval = 0;
					goto done;
				} else if (ack == 2) {
					struct commit *commit =
						lookup_commit(result_sha1);
					mark_common(commit, 0, 1);
					retval = 0;
					in_vain = 0;
					got_continue = 1;
				}
			} while (ack);
			flushes--;
