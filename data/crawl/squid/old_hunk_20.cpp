        status = Http::scNoContent;
    }

    // fill newEntry with a canned 2xx response object
    RequestFlags flags;
    flags.cachable = true;
