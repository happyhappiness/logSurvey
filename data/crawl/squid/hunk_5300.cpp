 	    version = LDAP_VERSION3;
 	    use_tls = 1;
 	    break;
+#endif
 	default:
-	    fprintf(stderr, "squid_ldap_auth: ERROR: Unknown command line option '%c'\n", option);
+	    fprintf(stderr, PROGRAM_NAME ": ERROR: Unknown command line option '%c'\n", option);
 	    exit(1);
 	}
     }
