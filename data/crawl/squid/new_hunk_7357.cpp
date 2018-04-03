    return 1;
}

#if HAVE_RANDOM
#define squid_random random
#elif HAVE_LRAND48
