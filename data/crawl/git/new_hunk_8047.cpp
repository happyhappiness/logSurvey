				memcpy(target + serverlen, data + i,
				       posn - i - 7);
				target[serverlen + posn - i - 7] = 0;
				if (walker->get_verbosely)
					fprintf(stderr,
						"Also look at %s\n", target);
				newalt = xmalloc(sizeof(*newalt));
