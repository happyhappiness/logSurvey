    else
        caps = cap_init();
    if (!caps) {
        IpInterceptor.StopTransparency("Can't get current capabilities");
    } else {
        int ncaps = 0;
        int rc = 0;
        cap_value_t cap_list[10];
        cap_list[ncaps++] = CAP_NET_BIND_SERVICE;

        if (IpInterceptor.TransparentActive()) {
            cap_list[ncaps++] = CAP_NET_ADMIN;
#if LINUX_TPROXY2
            cap_list[ncaps++] = CAP_NET_BROADCAST;
