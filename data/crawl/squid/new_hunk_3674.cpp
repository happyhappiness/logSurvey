        *t = '\0';

        if (r && cbdataReferenceValid(r->data)) {
            r->callback(r->data, srv, srv->rbuf);
        } else {
            debugs(84, 1, "StatefulHandleRead: no callback data registered");
	    called = 0;
        }

        srv->flags.busy = 0;
