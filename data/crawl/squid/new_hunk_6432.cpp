    if (connect(s, (struct sockaddr *) &S, sizeof(S)) < 0) {
	close(s);
	perror("connect");
	return NULL;
    }
    strcpy(urlbuf,urlin);
    method=strtok(urlbuf," ");
    url=strtok(NULL," ");
    file=strtok(NULL," ");
    size=strtok(NULL," ");
    checksum=strtok(NULL," ");
    if (!url) {
	url=method;
	method="GET";
    }
    r=calloc(1,sizeof *r);
    assert(r!=NULL);
    strcpy(r->url, url);
    r->fd = s;
    if (size && strcmp(size,"-")!=0)
	r->validsize=atoi(size);
    else
	r->validsize=-1; /* Unknown */
    if (checksum && strcmp(checksum,"-")!=0)
	r->validsum=atoi(checksum);
    msg[0] = '\0';
    sprintf(buf,"%s %s HTTP/1.0\r\n", method, url);
    strcat(msg, buf);
    strcat(msg, "Accept: */*\r\n");
    if (opt_ims && (lrand48() & 0x03) == 0) {
	w = time(NULL) - (lrand48() & 0x3FFFF);
	sprintf(buf, "If-Modified-Since: %s\r\n", mkrfc850(&w));
	strcat(msg,buf);
    }
    if (file && strcmp(file, "-")!=0) {
	f = open(file,O_RDONLY);
	if (f < 0) {
	    perror("open file");
	    exit(1);
	}
	fstat(f, &st);
	sprintf(buf,"Content-Length: %d\r\n", st.st_size);
	strcat(msg,buf);
    }
    strcat(msg, "\r\n");
    len = strlen(msg);
    if ((len2=write(s, msg, len)) != len) {
	close(s);
	perror("write request");
	free(r);
	return NULL;
    } else
	total_bytes_written += len2;
    if (f>=0) {
	while ((len = read(f, buf, sizeof(buf)))>0) {
	    len2 = write(s, buf, len);
	    if (len2 < 0) {
		perror("write body");
		close(s);
		free(r);
	    }
	}
	if (len < 0) {
	    perror("read body");
	    exit(1);
	}
    }

/*
 * if (fcntl(s, F_SETFL, O_NDELAY) < 0)
 * perror("fcntl O_NDELAY");
 */
    return r;
}

void
read_url(int fd, void *junk)
{
    struct _request *r;
    static char buf[8192];
    char *t;
    int s;
    if (fgets(buf, 8191, stdin) == NULL) {
	printf("Done Reading URLS\n");
	fd_close(0);
	nfds++;
	return;
    }
    if ((t = strchr(buf, '\n')))
	*t = '\0';
    r = request(buf);
    if (!r) {
	max_connections = nfds - 1;
	printf("NOTE: max_connections set at %d\n", max_connections);
    } else {
	fd_open(r->fd, read_reply, r, reply_done);
    }
}

void
