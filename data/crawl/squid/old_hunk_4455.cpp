        debugs(50, 0, "ALERT: setuid: " << xstrerror());

#endif
#if LINUX_TPROXY

    if (need_linux_tproxy) {
        cap_user_header_t head = (cap_user_header_t) xcalloc(1, sizeof(cap_user_header_t));
        cap_user_data_t cap = (cap_user_data_t) xcalloc(1, sizeof(cap_user_data_t));

        head->version = _LINUX_CAPABILITY_VERSION;
        head->pid = 0;
        cap->inheritable = cap->permitted = cap->effective = (1 << CAP_NET_ADMIN) + (1 << CAP_NET_BIND_SERVICE) + (1 << CAP_NET_BROADCAST);

        if (capset(head, cap) != 0) {
            xfree(head);
            xfree(cap);
            fatal("Error giving up capabilities");
        }

        xfree(head);
        xfree(cap);
    }

#endif
#if HAVE_PRCTL && defined(PR_SET_DUMPABLE)
    /* Set Linux DUMPABLE flag */
    if (Config.coredump_dir && prctl(PR_SET_DUMPABLE, 1) != 0)
