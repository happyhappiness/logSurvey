        return;
    }

    srv->offset += len;
    srv->buf[srv->offset] = '\0';
    r = srv->request;

    if (r == NULL) {
        /* someone spoke without being spoken to */
        debug(84, 1) ("helperStatefulHandleRead: unexpected read from %s #%d, %d bytes\n",
                      hlp->id_name, srv->index + 1, (int)len);
        srv->offset = 0;
    } else if ((t = strchr(srv->buf, '\n'))) {
        /* end of reply found */
        debug(84, 3) ("helperStatefulHandleRead: end of reply found\n");
        *t = '\0';

        if (cbdataReferenceValid(r->data)) {
            switch ((r->callback(r->data, srv, srv->buf))) {	/*if non-zero reserve helper */

            case S_HELPER_UNKNOWN:
                    fatal("helperStatefulHandleRead: either a non-state aware callback was give to the stateful helper routines, or an uninitialised callback response was recieved.\n");
