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
