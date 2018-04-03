        rc |= cap_set_flag(caps, CAP_PERMITTED, ncaps, cap_list, CAP_SET);

        if (rc || cap_set_proc(caps) != 0) {
            IpInterceptor.StopTransparency("Error enabling needed capabilities.");
        }
        cap_free(caps);
    }
#elif defined(_SQUID_LINUX_)
    IpInterceptor.StopTransparency("Missing needed capability support.");
#endif /* HAVE_SYS_CAPABILITY_H */
}

