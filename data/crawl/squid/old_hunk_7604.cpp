    handler(fd, NULL, data);
}

/* free all lines in the list */
static void free_lines(line)
     line_entry *line;
{
    line_entry *tmp;

    while (line) {
	tmp = line;
	line = line->next;
	safe_free(tmp->line);
	safe_free(tmp);
    }
}

/* scan through buffer and do a conversion if possible 
 * return number of char used */
static int fqdncache_parsebuffer(buf, offset, dnsData)
     char *buf;
     unsigned int offset;
     dnsserver_t *dnsData;
{
    char *pos = NULL;
    char *tpos = NULL;
    char *endpos = NULL;
    char *token = NULL;
    char *tmp_ptr = NULL;
    line_entry *line_head = NULL;
    line_entry *line_tail = NULL;
    line_entry *line_cur = NULL;
    int ipcount;
    int aliascount;
    fqdncache_entry *f = NULL;


    pos = buf;
    while (pos < (buf + offset)) {

	/* no complete record here */
	if ((endpos = strstr(pos, "$end\n")) == NULL) {
	    debug(35, 2, "fqdncache_parsebuffer: DNS response incomplete.\n");
	    break;
	}
	line_head = line_tail = NULL;

	while (pos < endpos) {
	    /* add the next line to the end of the list */
	    line_cur = xcalloc(1, sizeof(line_entry));

	    if ((tpos = memchr(pos, '\n', 4096)) == NULL) {
		debug(35, 2, "fqdncache_parsebuffer: DNS response incomplete.\n");
		return -1;
	    }
	    *tpos = '\0';
	    line_cur->line = xstrdup(pos);
	    debug(35, 7, "fqdncache_parsebuffer: %s\n", line_cur->line);
	    *tpos = '\n';

	    if (line_tail)
		line_tail->next = line_cur;
	    if (line_head == NULL)
		line_head = line_cur;
	    line_tail = line_cur;
	    line_cur = NULL;

	    /* update pointer */
	    pos = tpos + 1;
	}
	pos = endpos + 5;	/* strlen("$end\n") */

	/* 
	 *  At this point, the line_head is a linked list with each
	 *  link node containing another line of the DNS response.
	 *  Start parsing...
	 */
	if (strstr(line_head->line, "$alive")) {
	    dnsData->answer = squid_curtime;
	    free_lines(line_head);
	    debug(35, 10, "fqdncache_parsebuffer: $alive succeeded.\n");
	} else if (strstr(line_head->line, "$fail")) {
	    /*
	     *  The $fail messages look like:
	     *      $fail host\n$message msg\n$end\n
	     */
	    token = strtok(line_head->line, w_space);	/* skip first token */
	    if ((token = strtok(NULL, w_space)) == NULL) {
		debug(35, 1, "fqdncache_parsebuffer: Invalid $fail?\n");
	    } else {
		line_cur = line_head->next;
		f = dnsData->data;
		f->lastref = f->timestamp = squid_curtime;
		f->ttl = Config.negativeDnsTtl;
		f->status = FQDN_NEGATIVE_CACHED;
		if (line_cur && !strncmp(line_cur->line, "$message", 8))
		    f->error_message = xstrdup(line_cur->line + 8);
		dns_error_message = f->error_message;
		fqdncache_call_pending(f);
	    }
	    free_lines(line_head);
	} else if (strstr(line_head->line, "$name")) {
	    tmp_ptr = line_head->line;
	    /* skip the first token */
	    token = strtok(tmp_ptr, w_space);
	    if ((token = strtok(NULL, w_space)) == NULL) {
		debug(35, 0, "fqdncache_parsebuffer: Invalid OPCODE?\n");
	    } else {
		f = dnsData->data;
		if (f->status != FQDN_DISPATCHED) {
		    debug(35, 0, "fqdncache_parsebuffer: DNS record already resolved.\n");
		} else {
		    f->lastref = f->timestamp = squid_curtime;
		    f->ttl = Config.positiveDnsTtl;
		    f->status = FQDN_CACHED;

		    line_cur = line_head->next;

		    /* get $h_name */
		    if (line_cur == NULL ||
			!strstr(line_cur->line, "$h_name")) {
			debug(35, 1, "fqdncache_parsebuffer: DNS record in invalid format? No $h_name.\n");
			/* abandon this record */
			break;
		    }
		    tmp_ptr = line_cur->line;
		    /* skip the first token */
		    token = strtok(tmp_ptr, w_space);
		    tmp_ptr = NULL;
		    token = strtok(tmp_ptr, w_space);
		    f->names[0] = xstrdup(token);
		    f->name_count = 1;

		    line_cur = line_cur->next;

		    /* get $h_length */
		    if (line_cur == NULL ||
			!strstr(line_cur->line, "$h_len")) {
			debug(35, 1, "fqdncache_parsebuffer: DNS record in invalid format? No $h_len.\n");
			/* abandon this record */
			break;
		    }
		    tmp_ptr = line_cur->line;
		    /* skip the first token */
		    token = strtok(tmp_ptr, w_space);
		    tmp_ptr = NULL;
		    token = strtok(tmp_ptr, w_space);

		    line_cur = line_cur->next;

		    /* get $ipcount */
		    if (line_cur == NULL ||
			!strstr(line_cur->line, "$ipcount")) {
			debug(35, 1, "fqdncache_parsebuffer: DNS record in invalid format? No $ipcount.\n");
			/* abandon this record */
			break;
		    }
		    tmp_ptr = line_cur->line;
		    /* skip the first token */
		    token = strtok(tmp_ptr, w_space);
		    tmp_ptr = NULL;
		    token = strtok(tmp_ptr, w_space);
		    ipcount = atoi(token);

		    /* get ip addresses */
		    {
			int k = 0;
			line_cur = line_cur->next;
			while (k < ipcount) {
			    if (line_cur == NULL) {
				debug(35, 1, "fqdncache_parsebuffer: DNS record in invalid format? No $ipcount data.\n");
				break;
			    }
			    line_cur = line_cur->next;
			    k++;
			}
		    }

		    /* get $aliascount */
		    if (line_cur == NULL ||
			!strstr(line_cur->line, "$aliascount")) {
			debug(35, 1, "fqdncache_parsebuffer: DNS record in invalid format? No $aliascount.\n");
			/* abandon this record */
			break;
		    }
		    tmp_ptr = line_cur->line;
		    /* skip the first token */
		    token = strtok(tmp_ptr, w_space);
		    tmp_ptr = NULL;
		    token = strtok(tmp_ptr, w_space);
		    aliascount = atoi(token);

		    /* get aliases */
		    {
			int k = 0;
			line_cur = line_cur->next;
			while (k < aliascount) {
			    if (line_cur == NULL) {
				debug(35, 1, "fqdncache_parsebuffer: DNS record in invalid format? No $aliascount data.\n");
				break;
			    }
			    if (f->name_count < FQDN_MAX_NAMES)
				f->names[f->name_count++] = xstrdup(line_cur->line);
			    line_cur = line_cur->next;
			    k++;
			}
		    }
		    fqdncache_call_pending(f);
		    debug(35, 10, "fqdncache_parsebuffer: $name succeeded.\n");
		}
	    }
	    free_lines(line_head);
	} else {
	    free_lines(line_head);
	    debug(35, 1, "fqdncache_parsebuffer: Invalid OPCODE for DNS table?\n");
	    return -1;
	}
    }
    return (int) (pos - buf);
}


static int fqdncache_dnsHandleRead(fd, dnsData)
     int fd;
     dnsserver_t *dnsData;
{
    int char_scanned;
    int len;
    int svc_time;
    int n;
    fqdncache_entry *f = NULL;

    len = read(fd,
	dnsData->ip_inbuf + dnsData->offset,
