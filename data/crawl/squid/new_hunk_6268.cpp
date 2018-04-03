	*t = '\0';
	if (strncmp(buf, "http://", 7))
	    continue;
	gettimeofday(&t1, NULL);
	n = get_url(buf);
	gettimeofday(&t2, NULL);
	printf("%d %d\n", n, tvSubMsec(t1, t2));
    }
}

