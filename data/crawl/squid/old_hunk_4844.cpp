    if (urnState->flags.force_menu) {
        debug(51, 3) ("urnHandleReply: forcing menu\n");
    } else if (min_u) {
        httpHeaderPutStr(&rep->header, HDR_LOCATION, min_u->url);
    }

    httpBodySet(&rep->body, mb);
