			/* Ignore epipe */
			if (errno == EPIPE)
				break;
			die("merge-recursive: %s", strerror(errno));
		} else if (!ret) {
			die("merge-recursive: disk full?");
		}
