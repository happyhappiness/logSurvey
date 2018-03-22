	  ino_t ino;
	  bool nfs = buf[0] == '+';
	  char *strp = buf + nfs;

	  lineno++;

	  if (buf[n - 1] == '\n')
	    buf[n - 1] = '\0';

	  errno = 0;
	  dev = u = strtoumax (strp, &ebuf, 10);
	  if (!isspace (*ebuf))
