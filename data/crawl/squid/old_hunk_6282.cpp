    }
    dlinkDelete(&r->link, &redirectors);
    cbdataFree(r);
}

void
