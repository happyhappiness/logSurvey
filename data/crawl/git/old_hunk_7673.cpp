			if (!strcmp(arg, "--"))
				break;
			else if (!strcmp(arg, "--cached")) {
				add_head(&rev);
				if (!rev.pending.nr)
					die("No HEAD commit to compare with (yet)");
				break;
