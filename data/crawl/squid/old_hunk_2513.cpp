                fatalf("parse_peer: non-parent carp peer %s/%d\n", p->host, p->http_port);

            p->options.carp = 1;
        } else if (!strcasecmp(token, "userhash")) {
#if USE_AUTH
            if (p->type != PEER_PARENT)
