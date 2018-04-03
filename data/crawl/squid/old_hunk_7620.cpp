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
static int ipcache_parsebuffer(buf, offset, dnsData)
     char *buf;
     unsigned int offset;
     dnsserver_t *dnsData;
{
    char *pos = NULL;
    char *tpos = NULL;
    char *endpos = NULL;
    char *token = NULL;
    line_entry *line_head = NULL;
    line_entry *line_tail = NULL;
    line_entry *line_cur = NULL;
    int ipcount;
    int aliascount;
    ipcache_entry *i = NULL;


    pos = buf;
    while (pos < (buf + offset)) {

	/* no complete record here */
	if ((endpos = strstr(pos, "$end\n")) == NULL) {
	    debug(14, 2, "ipcache_parsebuffer: DNS response incomplete.\n");
	    break;
	}
	line_head = line_tail = NULL;

	while (pos < endpos) {
	    /* add the next line to the end of the list */
	    line_cur = xcalloc(1, sizeof(line_entry));

	    if ((tpos = memchr(pos, '\n', 4096)) == NULL) {
		debug(14, 2, "ipcache_parsebuffer: DNS response incomplete.\n");
		return -1;
	    }
	    *tpos = '\0';
	    line_cur->line = xstrdup(pos);
	    debug(14, 7, "ipcache_parsebuffer: %s\n", line_cur->line);
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
	    debug(14, 10, "ipcache_parsebuffer: $alive succeeded.\n");
	} else if (strstr(line_head->line, "$fail")) {
	    /*
	     *  The $fail messages look like:
	     *      $fail host\n$message msg\n$end\n
	     */
	    token = strtok(line_head->line, w_space);	/* skip first token */
	    if ((token = strtok(NULL, w_space)) == NULL) {
		debug(14, 1, "ipcache_parsebuffer: Invalid $fail?\n");
	    } else {
		line_cur = line_head->next;
		i = dnsData->data;
		i->expires = squid_curtime + Config.negativeDnsTtl;
		i->status = IP_NEGATIVE_CACHED;
		if (line_cur && !strncmp(line_cur->line, "$message", 8))
		    i->error_message = xstrdup(line_cur->line + 8);
		dns_error_message = i->error_message;
		ipcache_call_pending(i);
	    }
	    free_lines(line_head);
	} else if (strstr(line_head->line, "$name")) {
	    token = strtok(line_head->line, w_space);
	    if ((token = strtok(NULL, w_space)) == NULL) {
		debug(14, 0, "ipcache_parsebuffer: Invalid OPCODE?\n");
	    } else {
		i = dnsData->data;
		if (i->status != IP_DISPATCHED) {
		    debug(14, 0, "ipcache_parsebuffer: DNS record already resolved.\n");
		} else {
		    i->expires = squid_curtime + Config.positiveDnsTtl;
		    i->status = IP_CACHED;

		    line_cur = line_head->next;

		    /* get $h_name */
		    if (line_cur == NULL ||
			!strstr(line_cur->line, "$h_name")) {
			debug(14, 1, "ipcache_parsebuffer: DNS record in invalid format? No $h_name.\n");
			/* abandon this record */
			break;
		    }
		    token = strtok(line_cur->line, w_space);
		    token = strtok(NULL, w_space);
		    i->entry.h_name = xstrdup(token);

		    line_cur = line_cur->next;

		    /* get $h_length */
		    if (line_cur == NULL ||
			!strstr(line_cur->line, "$h_len")) {
			debug(14, 1, "ipcache_parsebuffer: DNS record in invalid format? No $h_len.\n");
			/* abandon this record */
			break;
		    }
		    token = strtok(line_cur->line, w_space);
		    token = strtok(NULL, w_space);
		    i->entry.h_length = atoi(token);

		    line_cur = line_cur->next;

		    /* get $ipcount */
		    if (line_cur == NULL ||
			!strstr(line_cur->line, "$ipcount")) {
			debug(14, 1, "ipcache_parsebuffer: DNS record in invalid format? No $ipcount.\n");
			/* abandon this record */
			break;
		    }
		    token = strtok(line_cur->line, w_space);
		    token = strtok(NULL, w_space);
		    ipcount = atoi(token);
		    i->addr_count = (unsigned char) ipcount;

		    if (ipcount == 0) {
			i->entry.h_addr_list = NULL;
		    } else {
			i->entry.h_addr_list = xcalloc(ipcount + 1, sizeof(char *));
		    }

		    /* get ip addresses */
		    {
			int k = 0;
			line_cur = line_cur->next;
			while (k < ipcount) {
			    if (line_cur == NULL) {
				debug(14, 1, "ipcache_parsebuffer: DNS record in invalid format? No $ipcount data.\n");
				break;
			    }
			    *(i->entry.h_addr_list + k) = xcalloc(1, i->entry.h_length);
			    *((u_num32 *) (void *) *(i->entry.h_addr_list + k)) = inet_addr(line_cur->line);
			    line_cur = line_cur->next;
			    k++;
			}
		    }

		    /* get $aliascount */
		    if (line_cur == NULL ||
			!strstr(line_cur->line, "$aliascount")) {
			debug(14, 1, "ipcache_parsebuffer: DNS record in invalid format? No $aliascount.\n");
			/* abandon this record */
			break;
		    }
		    token = strtok(line_cur->line, w_space);
		    token = strtok(NULL, w_space);
		    aliascount = atoi(token);
		    i->alias_count = (unsigned char) aliascount;

		    if (aliascount == 0) {
			i->entry.h_aliases = NULL;
		    } else {
			i->entry.h_aliases = xcalloc(aliascount, sizeof(char *));
		    }

		    /* get aliases */
		    {
			int k = 0;
			line_cur = line_cur->next;
			while (k < aliascount) {
			    if (line_cur == NULL) {
				debug(14, 1, "ipcache_parsebuffer: DNS record in invalid format? No $aliascount data.\n");
				break;
			    }
			    i->entry.h_aliases[k] = xstrdup(line_cur->line);
			    line_cur = line_cur->next;
			    k++;
			}
		    }
		    /* DNS TTL - bne@CareNet.hu */
		    /* next line is either a $ttl ttl\n or a $end\n */
		    if (strstr(line_cur->line, "$ttl")) {
			token = strtok(line_cur->line, w_space);
			token = strtok(NULL, w_space);
			i->expires = squid_curtime + atoi(token);
		    }
		    ipcache_call_pending(i);
		    debug(14, 10, "ipcache_parsebuffer: $name succeeded.\n");
		}
	    }
	    free_lines(line_head);
	} else {
	    free_lines(line_head);
	    debug(14, 1, "ipcache_parsebuffer: Invalid OPCODE for DNS table?\n");
	    return -1;
	}
    }
    return (int) (pos - buf);
}


static int ipcache_dnsHandleRead(fd, dnsData)
     int fd;
     dnsserver_t *dnsData;
{
    int char_scanned;
    int len;
    int svc_time;
    int n;
    ipcache_entry *i = NULL;

    len = read(fd,
	dnsData->ip_inbuf + dnsData->offset,
