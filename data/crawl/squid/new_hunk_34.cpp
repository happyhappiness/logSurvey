    return roles;
}

/* A little piece of glue for odd systems */
#ifndef RLIMIT_NOFILE
#ifdef RLIMIT_OFILE
