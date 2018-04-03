    int rc;

/* On Windows ldap_start_tls_s is available starting from Windows XP, 
   so we need to bind at run-time with the function entry point
 */
#ifdef _SQUID_MSWIN_
    if (use_tls) {

    	HMODULE WLDAP32Handle;

    	WLDAP32Handle = GetModuleHandle("wldap32");
        if ((Win32_ldap_start_tls_s = (PFldap_start_tls_s) GetProcAddress(WLDAP32Handle, LDAP_START_TLS_S)) == NULL) {
            fprintf( stderr, PROGRAM_NAME ": ERROR: TLS (-Z) not supported on this platform.\n");
	    exit(1);
        }
    }
#endif

