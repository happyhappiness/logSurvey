        if (comm_iocallbackpending())
            comm_calliocallback();

        mainLoop.runOnce();
    }

    /* NOTREACHED */
