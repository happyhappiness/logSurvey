mainInitialize(void)
{
    /* chroot if configured to run inside chroot */

    if (Config.chroot_dir && (chroot(Config.chroot_dir) != 0 || chdir("/") != 0)) {
        fatal("failed to chroot");
    }

    if (opt_catch_signals) {
        squid_signal(SIGSEGV, death, SA_NODEFER | SA_RESETHAND);
