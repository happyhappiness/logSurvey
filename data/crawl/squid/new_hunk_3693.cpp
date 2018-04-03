
            case S_HELPER_RELEASE:	/* helper finished with */

                srv->flags.reserved = S_HELPER_FREE;

                if ((srv->parent->OnEmptyQueue != NULL) && (srv->data))
                    srv->parent->OnEmptyQueue(srv->data);

                debugs(84, 5, "StatefulHandleRead: releasing " << hlp->id_name << " #" << srv->index + 1);

                break;

            case S_HELPER_RESERVE:	/* 'pin' this helper for the caller */

		srv->flags.reserved = S_HELPER_RESERVED;
		debugs(84, 5, "StatefulHandleRead: reserving " << hlp->id_name << " #" << srv->index + 1);

                break;

            default:
