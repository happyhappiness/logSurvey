
    if (opt_create_swap_dirs) {
        /* chroot if configured to run inside chroot */

        if (Config.chroot_dir && chroot(Config.chroot_dir)) {
            fatal("failed to chroot");
        }

        setEffectiveUser();
        debugs(0, DBG_CRITICAL, "Creating missing swap directories");