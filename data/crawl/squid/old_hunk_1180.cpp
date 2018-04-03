    else if (s->flags.tproxyIntercept)
        storeAppendPrintf(e, " tproxy");

    else if (s->flags.accelSurrogate) {
        storeAppendPrintf(e, " accel");

