				handle_refs(revs, flags, for_each_remote_ref);
				continue;
			}
			if (!strcmp(arg, "--reflog")) {
				handle_reflog(revs, flags);
				continue;
			}
			if (!strcmp(arg, "--not")) {
				flags ^= UNINTERESTING;
				continue;
			}
			if (!strcmp(arg, "--no-walk")) {
				revs->no_walk = 1;
				continue;
