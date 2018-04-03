 	} else {
 	    printf("OK\n");
 	}
-	if (!persistent || (squid_ldap_errno(ld) != LDAP_SUCCESS && squid_ldap_errno(ld) != LDAP_INVALID_CREDENTIALS)) {
+	if (ld && (squid_ldap_errno(ld) != LDAP_SUCCESS && squid_ldap_errno(ld) != LDAP_INVALID_CREDENTIALS)) {
 	    ldap_unbind(ld);
 	    ld = NULL;
 	}
