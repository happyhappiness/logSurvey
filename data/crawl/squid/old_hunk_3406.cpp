        count++;
        hres_list = hres_list->ai_next;
    }
    rc = xgetnameinfo(hres->ai_addr, hres->ai_addrlen, hostname,
                      sizeof(hostname), NULL, 0, 0);
    if (rc != 0) {
        fprintf(stderr,
                "%s| %s: ERROR: resolving ip address with getnameinfo: %s failed\n",
                LogTime(), PROGRAM, xgai_strerror(rc));
        xfreeaddrinfo(hres);
        return NULL;
    }

    xfreeaddrinfo(hres);
    hostname[sysconf(_SC_HOST_NAME_MAX) - 1] = '\0';
    return (xstrdup(hostname));
}
