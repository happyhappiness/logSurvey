            return host;
    }

    fatal("Could not determine fully qualified hostname.  Please set 'visible_hostname'\n");
    return NULL;		/* keep compiler happy */
}
