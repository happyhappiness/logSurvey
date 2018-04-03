static void
sendSignal(void)
{
    debug_log = stderr;

#if USE_WIN32_SERVICE
    (void)Instance::Other();
    if (!opt_signal_service)
        throw TexcHere("missing -n command line switch");
    WIN32_sendSignal(opt_send_signal);
#else
    const auto pid = Instance::Other();
    if (kill(pid, opt_send_signal) &&
            /* ignore permissions if just running check */
            !(opt_send_signal == 0 && errno == EPERM)) {
        const auto savedErrno = errno;
        throw TexcHere(ToSBuf("failed to send signal ", opt_send_signal,
                              " to Squid instance with PID ", pid, ": ", xstrerr(savedErrno)));
    }
#endif
    /* signal successfully sent */
}

#if !_SQUID_WINDOWS_
