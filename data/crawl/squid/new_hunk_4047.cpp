    head->version = _LINUX_CAPABILITY_VERSION_1;

    if (capget(head, cap) != 0) {
        debugs(50, DBG_IMPORTANT, "Can't get current capabilities");
    }
    else if (head->version != _LINUX_CAPABILITY_VERSION_1) {
        debugs(50, DBG_IMPORTANT, "Invalid capability version " << head->version << " (expected " << _LINUX_CAPABILITY_VERSION_1 << ")");
    }
    else {

        head->pid = 0;

        cap->inheritable = 0;
        cap->effective = (1 << CAP_NET_BIND_SERVICE);

        if (IPInterceptor.TransparentActive()) {
            cap->effective |= (1 << CAP_NET_ADMIN);
#if LINUX_TPROXY2
            cap->effective |= (1 << CAP_NET_BROADCAST);
#endif
        }

        if (!keep)
            cap->permitted &= cap->effective;

        if (capset(head, cap) != 0) {
            IPInterceptor.StopTransparency("Error enabling needed capabilities.");
        }
    }

    xfree(head);
    xfree(cap);

#else
    IPInterceptor.StopTransparency("Missing needed capability support.");
#endif /* HAVE_SYS_CAPABILITY_H */

#endif /* !defined(_SQUID_LINUX_) */
}

void *