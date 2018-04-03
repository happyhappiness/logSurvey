        cap->permitted &= cap->effective;

    if (capset(head, cap) != 0) {
        /* Silent failure unless transparency is required */
        if(IPInterceptor.TransparentActive()) {
            IPInterceptor.StopTransparency("Error enabling needed capabilities.");
        }
    }

nocap:
    xfree(head);
    xfree(cap);
#else /* not defined(_SQUID_LINUX_) && HAVE_SYS_CAPABILITY_H */

    if (IPInterceptor.TransparentActive()) {
        IPInterceptor.StopTransparency("Missing needed capability support.");
    }

#endif
}
