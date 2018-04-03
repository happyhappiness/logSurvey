    else
	ld->ld_options &= ~LDAP_OPT_REFERRALS;
}
static void 
squid_ldap_memfree(char *p)
{
