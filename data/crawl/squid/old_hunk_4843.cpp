    }

    HTTPMSGLOCK(urlres_r);
    httpHeaderPutStr(&urlres_r->header, HDR_ACCEPT, "text/plain");
}

void
