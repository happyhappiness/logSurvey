					die("could not open '%s': %s",
						argv[i], strerror(errno));
			}
			len = 1024;
			message = xmalloc(len);
			if (read_fd(fd, &message, &len)) {
				free(message);
				die("cannot read %s", argv[i]);
			}
			continue;
		}
		if (!strcmp(arg, "-u")) {
