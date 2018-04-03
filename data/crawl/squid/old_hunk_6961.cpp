    t->page_faults = c->page_faults - p->page_faults;
    t->select_loops = c->select_loops - p->select_loops;
    t->cputime = c->cputime - p->cputime;
    squid_getrusage(&rusage);
    c->page_faults = rusage_pagefaults(&rusage);
    c->cputime = rusage_cputime(&rusage);
}