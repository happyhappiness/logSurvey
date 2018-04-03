			/* Ignore epipe */
			if (errno == EPIPE)
				break;
			die_errno("merge-recursive");
		} else if (!ret) {
			die("merge-recursive: disk full?");
		}
