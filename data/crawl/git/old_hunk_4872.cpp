			else if (!strcmp(arg, "--cached") ||
				 !strcmp(arg, "--staged")) {
				add_head_to_pending(&rev);
				if (!rev.pending.nr)
					die("No HEAD commit to compare with (yet)");
				break;
			}
		}
