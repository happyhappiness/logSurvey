        status = Http::scNoContent;
    }

    const MasterXaction::Pointer mx = new MasterXaction(XactionInitiator::initIcon);
    HttpRequestPointer r(HttpRequest::FromUrl(url_, mx));
    if (!r)
        fatalf("mimeLoadIcon: cannot parse internal URL: %s", url_);

    // fill newEntry with a canned 2xx response object
    RequestFlags flags;
    flags.cachable = true;
