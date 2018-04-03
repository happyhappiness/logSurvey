	*t = '\0';
	if (strncmp(buf, "http://", 7))
	    continue;
	n = get_url(buf);
	printf ("%d\n", n);
    }
}

