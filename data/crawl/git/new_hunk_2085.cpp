		}

		if (stat(arg, &argstat) == -1) {
			error_errno("cannot stat %s", arg);
			return 1;
		}
