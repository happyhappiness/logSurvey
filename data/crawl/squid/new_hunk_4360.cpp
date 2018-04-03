	ld->ld_options &= ~LDAP_OPT_REFERRALS;
}
static void
squid_ldap_set_timelimit(LDAP * ld, int timelimit)
{
    ld->ld_timelimit = timelimit;
}
static void
squid_ldap_set_connect_timeout(LDAP * ld, int timelimit)
{
    fprintf(stderr, "Connect timeouts not supported in your LDAP library\n");
}
static void
squid_ldap_memfree(char *p)
{
    free(p);
}

#endif

#ifdef LDAP_API_FEATURE_X_OPENLDAP
#if LDAP_VENDOR_VERSION > 194
#define HAS_URI_SUPPORT 1
#endif
#endif

int
