{
    // decide whether to use a shared memory cache if the user did not specify
    if (!Config.memShared.configured()) {
        Config.memShared.configure(UsingSmp() && Config.memMaxSize > 0);
    }

    if (!Config.memShared)
