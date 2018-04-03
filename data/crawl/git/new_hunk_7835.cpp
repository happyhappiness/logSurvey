				 * commits at the remote end and likely
				 * we were not up to date to begin with.
				 */
				fprintf(stderr, " ! %-*s %s -> %s (non-fast forward)\n",
						SUMMARY_WIDTH, "[rejected]",
						pretty_peer, pretty_ref);
				ret = -2;
				continue;
			}
