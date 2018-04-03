        } else if (!strcasecmp(token, "htcp-oldsquid")) {
            p->options.htcp = 1;
            p->options.htcp_oldsquid = 1;
        } else if (!strcasecmp(token, "htcp-no-clr")) {
            if (p->options.htcp_only_clr)
        	fatalf("parse_peer: can't set htcp-no-clr and htcp-only-clr simultaneously");
            p->options.htcp = 1;
            p->options.htcp_no_clr = 1;
        } else if (!strcasecmp(token, "htcp-no-purge-clr")) {
            p->options.htcp = 1;
            p->options.htcp_no_purge_clr = 1;
        } else if (!strcasecmp(token, "htcp-only-clr")) {
            if (p->options.htcp_no_clr)
        	fatalf("parse_peer: can't set htcp-no-clr and htcp-only-clr simultaneously");
            p->options.htcp = 1;
            p->options.htcp_only_clr = 1;
        } else if (!strcasecmp(token, "htcp-forward-clr")) {
            p->options.htcp = 1;
            p->options.htcp_forward_clr = 1;
#endif

        } else if (!strcasecmp(token, "no-netdb-exchange")) {
