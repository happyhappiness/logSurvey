    if (opt_send_signal != -1) {
        /* chroot if configured to run inside chroot */

        if (Config.chroot_dir && chroot(Config.chroot_dir)) {
            fatal("failed to chroot");
        }

        sendSignal();
