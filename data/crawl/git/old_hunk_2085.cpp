		}

		if (stat(arg, &argstat) == -1) {
			error("cannot stat %s (%s)", arg, strerror(errno));
			return 1;
		}
