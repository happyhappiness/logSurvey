		fatal("helperStatefulHandleRead: either a non-state aware callback was give to the stateful helper routines, or an uninitialised callback response was recieved.\n");
		break;
	    case S_HELPER_RELEASE:	/* helper finished with */
		if (!srv->deferred_requests && !srv->queue.head) {
		    srv->flags.reserved = S_HELPER_FREE;
		    if ((srv->parent->OnEmptyQueue != NULL) && (srv->data))
			srv->parent->OnEmptyQueue(srv->data);
