restoreCapabilities(int keep)
{
    /* NP: keep these two if-endif separate. Non-Linux work perfectly well without Linux syscap support. */
#if defined(_SQUID_LINUX_)

#if HAVE_SYS_CAPABILITY_H
#ifndef _LINUX_CAPABILITY_VERSION_1
#define _LINUX_CAPABILITY_VERSION_1 _LINUX_CAPABILITY_VERSION
#endif
    cap_user_header_t head = (cap_user_header_t) xcalloc(1, sizeof(*head));
    cap_user_data_t cap = (cap_user_data_t) xcalloc(1, sizeof(*cap));

    head->version = _LINUX_CAPABILITY_VERSION_1;

    if (capget(head, cap) != 0) {
        debugs(50, DBG_IMPORTANT, "Can't get current capabilities");
    } else if (head->version != _LINUX_CAPABILITY_VERSION_1) {
        debugs(50, DBG_IMPORTANT, "Invalid capability version " << head->version << " (expected " << _LINUX_CAPABILITY_VERSION_1 << ")");
    } else {

        head->pid = 0;

        cap->inheritable = 0;
        cap->effective = (1 << CAP_NET_BIND_SERVICE);

        if (IpInterceptor.TransparentActive()) {
            cap->effective |= (1 << CAP_NET_ADMIN);
#if LINUX_TPROXY2
            cap->effective |= (1 << CAP_NET_BROADCAST);
#endif
        }

        if (!keep)
            cap->permitted &= cap->effective;

        if (capset(head, cap) != 0) {
            IpInterceptor.StopTransparency("Error enabling needed capabilities.");
        }
    }

    xfree(head);
    xfree(cap);

#else
    IpInterceptor.StopTransparency("Missing needed capability support.");
#endif /* HAVE_SYS_CAPABILITY_H */

#endif /* !defined(_SQUID_LINUX_) */
}

void *