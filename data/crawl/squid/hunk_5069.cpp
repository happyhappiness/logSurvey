 		if (version == -1) {
 		    version = LDAP_VERSION2;
 		}
-		if (ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &version)
-		    != LDAP_OPT_SUCCESS) {
+		if (ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &version) != LDAP_SUCCESS) {
 		    fprintf(stderr, "Could not set LDAP_OPT_PROTOCOL_VERSION %d\n",
 			version);
 		    ldap_unbind(ld);
 		    ld = NULL;
 		    break;
 		}
-		if (use_tls && (version == LDAP_VERSION3) && (ldap_start_tls_s(ld, NULL, NULL) != LDAP_SUCCESS)) {
-		    fprintf(stderr, "Could not Activate TLS connection\n");
-		    ldap_unbind(ld);
-		    ld = NULL;
-		    break;
+		if (use_tls) {
+#ifdef LDAP_OPT_X_TLS
+		    if (version == LDAP_VERSION3 && ldap_start_tls_s(ld, NULL, NULL) != LDAP_SUCCESS) {
+			fprintf(stderr, "Could not Activate TLS connection\n");
+			ldap_unbind(ld);
+			ld = NULL;
+			break;
+		    } else {
+			fprintf(stderr, "TLS requires LDAP version 3\n");
+			exit(1);
+		    }
+#else
+		    fprintf(stderr, "TLS not supported with your LDAP library\n");
+		    exit(1);
+#endif
 		}
 #endif
 		squid_ldap_set_timelimit(ld, timelimit);