			die_errno("Cannot read '%s'", p);
		if (!n)
			break;
		write_or_die(1, buf, n);
	}
	close(fd);
	free(buf);
