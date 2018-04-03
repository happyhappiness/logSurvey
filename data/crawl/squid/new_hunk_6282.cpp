    }
    dlinkDelete(&r->link, &redirectors);
    cbdataFree(r);
    NRedirectorsOpen--;
    if (NRedirectorsOpen == 0 && !shutting_down)
	fatal_dump("All redirectors have exited!");
}

void
