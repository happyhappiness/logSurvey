        /* There must be at least one child already, or we have no business
           waiting for a token. */
        if (!children)
          fatal (NILF, "INTERNAL: no children as we go to sleep on read\n");

#ifdef WINDOWS32
        /* On Windows we simply wait for the jobserver semaphore to become
