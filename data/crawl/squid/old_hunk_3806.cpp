                      f->unlink.requests);
    storeAppendPrintf(sentry, "page_faults = %d\n",
                      f->page_faults);
    storeAppendPrintf(sentry, "select_loops = %d\n",
                      f->select_loops);
    storeAppendPrintf(sentry, "cpu_time = %f\n",
                      f->cputime);
