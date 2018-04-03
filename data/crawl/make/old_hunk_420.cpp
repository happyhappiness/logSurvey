      else
        fatal (NILF, _("unknown output-sync type '%s'"), p);
    }
}

#ifdef WINDOWS32
/*
 * HANDLE runtime exceptions by avoiding a requestor on the GUI. Capture
 * exception and print it to stderr instead.
