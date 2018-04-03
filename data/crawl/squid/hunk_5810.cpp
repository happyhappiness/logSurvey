 	    /* Authenticated and Authorised for this ACL */
 	    return 1;
 	case -2:
-	    debug(28, 4) ("aclMatchAcl: returning 0 sending authentication challenge.\n");
-	    /* Authentication credentials invalid or missing. */
-	    /* Or partway through NTLM handshake. A proxy_Authenticate header
-	     * gets sent to the client. */
-	    checklist->state[ACL_PROXY_AUTH] = ACL_PROXY_AUTH_NEEDED;
-	    return 0;
 	case -1:
-	    debug(28, 4) ("aclMatchAcl: returning 0 sending credentials to helper.\n");
-	    /*
-	     * we need to validate the password
-	     */
-	    checklist->state[ACL_PROXY_AUTH] = ACL_LOOKUP_NEEDED;
-	    return 0;
+	    fatal("Invalid response from match routine\n");
+	    break;
 	}
+
 	/* NOTREACHED */
 #if SQUID_SNMP
     case ACL_SNMP_COMMUNITY:
