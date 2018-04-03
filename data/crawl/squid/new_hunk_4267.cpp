             * 401 to .cgi because web server filters out all auth info. Thus we
             * disable authentication headers for now.
             */
            if (!strncasecmp(buf, "WWW-Authenticate:", 17) || !strncasecmp(buf, "Proxy-Authenticate:", 19));	/* skip */
            else
                fputs(buf, stdout);
