    if (urnState->flags.force_menu) {
        debugs(51, 3, "urnHandleReply: forcing menu");
    } else if (min_u) {
        rep->header.putStr(HDR_LOCATION, min_u->url);
    }

    rep->body.setMb(mb);