    StoreEntry *e;

    if (state->theSearch->isDone()) {
        state->sentry->complete();
        state->sentry->unlock();
        cbdataFree(state);
