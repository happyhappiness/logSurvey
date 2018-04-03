	}
	if (close(fd) < 0)
		die("closing file %s: %s", path, strerror(errno));
	if (nbuf)
		free(nbuf);
	return 0;
}

