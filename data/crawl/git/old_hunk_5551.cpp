				case ACK_continue: {
					struct commit *commit =
						lookup_commit(result_sha1);
					mark_common(commit, 0, 1);
					retval = 0;
					in_vain = 0;
