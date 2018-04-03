        } else if (!strcasecmp(token, "htcp-oldsquid")) {
            p->options.htcp = 1;
            p->options.htcp_oldsquid = 1;
#endif

        } else if (!strcasecmp(token, "no-netdb-exchange")) {
