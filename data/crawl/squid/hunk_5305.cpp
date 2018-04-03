 		 * are disabled.
 		 */
 	    } else {
-		fprintf(stderr, "squid_ldap_auth: WARNING, LDAP search error '%s'\n", ldap_err2string(rc));
+		fprintf(stderr, PROGRAM_NAME ": WARNING, LDAP search error '%s'\n", ldap_err2string(rc));
+#if defined(NETSCAPE_SSL)
+		if (sslpath && ((rc == LDAP_SERVER_DOWN) || (rc == LDAP_CONNECT_ERROR))) {
+		    int sslerr = PORT_GetError();
+		    fprintf(stderr, PROGRAM_NAME ": WARNING, SSL error %d (%s)\n", sslerr, ldapssl_err2string(sslerr));
+		}
+#endif
 	    }
 	}
 	entry = ldap_first_entry(ld, res);