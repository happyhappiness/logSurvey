
            case S_HELPER_RELEASE:	/* helper finished with */

                if (!srv->deferred_requests && !srv->queue.head) {
                    srv->flags.reserved = S_HELPER_FREE;

                    if ((srv->parent->OnEmptyQueue != NULL) && (srv->data))
                        srv->parent->OnEmptyQueue(srv->data);

                    debugs(84, 5, "StatefulHandleRead: releasing " << hlp->id_name << " #" << srv->index + 1);
                } else {
                    srv->flags.reserved = S_HELPER_DEFERRED;
                    debugs(84, 5, "StatefulHandleRead: outstanding deferred requests on " <<
                           hlp->id_name << " #" << srv->index + 1 <<
                           ". reserving for deferred requests.");
                }

                break;

            case S_HELPER_RESERVE:	/* 'pin' this helper for the caller */

                if (!srv->queue.head) {
                    assert(srv->deferred_requests == 0);
                    srv->flags.reserved = S_HELPER_RESERVED;
                    debugs(84, 5, "StatefulHandleRead: reserving " << hlp->id_name << " #" << srv->index + 1);
                } else {
                    fatal("StatefulHandleRead: Callback routine attempted to reserve a stateful helper with deferred requests. This can lead to deadlock.\n");
                }

                break;

            case S_HELPER_DEFER:
                /* the helper is still needed, but can
                 * be used for other requests in the meantime.
                 */
                srv->flags.reserved = S_HELPER_DEFERRED;
                srv->deferred_requests++;
                srv->stats.deferbycb++;
                debugs(84, 5, "StatefulHandleRead: reserving " << hlp->id_name << " #" << srv->index + 1 << " for deferred requests.");
                break;

            default:
