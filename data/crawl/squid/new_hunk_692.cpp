                          srv->stats.pending ? 'B' : ' ',
                          srv->flags.writing ? 'W' : ' ',
                          srv->flags.closing ? 'C' : ' ',
                          srv->flags.reserved ? 'R' : ' ',
                          srv->flags.shutdown ? 'S' : ' ',
                          request && request->placeholder ? 'P' : ' ',
                          tt < 0.0 ? 0.0 : tt,
                          (int) srv->roffset,
                          request ? Format::QuoteMimeBlob(request->buf) : "(none)");
    }

    p->append("\nFlags key:\n"
              "   B\tBUSY\n"
              "   W\tWRITING\n"
              "   C\tCLOSING\n"
              "   R\tRESERVED\n"
              "   S\tSHUTDOWN PENDING\n"
              "   P\tPLACEHOLDER\n", 101);
}

void
