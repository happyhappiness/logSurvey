
/* Legacy parser interface */
#define parse_HelperChildConfig(c)     (c)->parseConfig()
#define dump_HelperChildConfig(e,n,c)  storeAppendPrintf((e), "\n%s %d startup=%d idle=%d\n", (n), (c).n_max, (c).n_startup, (c).n_idle)
#define free_HelperChildConfig(dummy)  // NO.

#endif /* _SQUID_SRC_HELPERCHILDCONFIG_H */
