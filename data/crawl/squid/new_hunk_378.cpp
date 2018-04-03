
    // TODO: bypass if possible
    if (!handledEarlyAdaptationAbort())
        abortAll("adaptation failure with a filled entry");
}

/// If the store entry is still empty, fully handles adaptation abort, returning
