        if (UsingSmp())
            storeAppendPrintf(state->sentry, "} by kid%d\n\n", KidIdentifier);
        state->sentry->complete();
        state->sentry->unlock();
        cbdataFree(state);
        return;
    } else if (EBIT_TEST(state->sentry->flags, ENTRY_ABORTED)) {
        state->sentry->unlock();
        cbdataFree(state);
        return;
    } else if (state->sentry->checkDeferRead(-1)) {
