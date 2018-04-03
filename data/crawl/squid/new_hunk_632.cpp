    if (urnState->flags.force_menu) {
        debugs(51, 3, "urnHandleReply: forcing menu");
    } else if (min_u) {
        rep->header.putStr(Http::HdrType::LOCATION, min_u->url);
    }

    rep->body.setMb(mb);