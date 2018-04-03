     int k, ti;
 
     switch (aclType()) {
+
     case ACL_MAXCONN:
-	k = clientdbEstablished(checklist->src_addr, 0);
-	return ((k > ((intlist *) data)->i) ? 1 : 0);
-	/* NOTREACHED */
+        k = clientdbEstablished(checklist->src_addr, 0);
+        return ((k > ((intlist *) data)->i) ? 1 : 0);
+        /* NOTREACHED */
+
     case ACL_URL_PORT:
-	return aclMatchIntegerRange((intrange *)data, (int) r->port);
-	/* NOTREACHED */
+        return aclMatchIntegerRange((intrange *)data, (int) r->port);
+        /* NOTREACHED */
+
     case ACL_MY_PORT:
-	return aclMatchIntegerRange((intrange *)data, (int) checklist->my_port);
-	/* NOTREACHED */
+        return aclMatchIntegerRange((intrange *)data, (int) checklist->my_port);
+        /* NOTREACHED */
+
     case ACL_PROTO:
-	return aclMatchInteger((intlist *)data, r->protocol);
-	/* NOTREACHED */
+        return aclMatchInteger((intlist *)data, r->protocol);
+        /* NOTREACHED */
+
     case ACL_METHOD:
-	return aclMatchInteger((intlist *)data, r->method);
-	/* NOTREACHED */
+        return aclMatchInteger((intlist *)data, r->method);
+        /* NOTREACHED */
+
     case ACL_MAX_USER_IP:
-	if ((ti = checklist->authenticated()) != 1)
-	    return ti;
-	ti = aclMatchUserMaxIP(data, checklist->auth_user_request,
-	    checklist->src_addr);
-	checklist->auth_user_request = NULL;
-	return ti;
-	/* NOTREACHED */
+
+        if ((ti = checklist->authenticated()) != 1)
+            return ti;
+
+        ti = aclMatchUserMaxIP(data, checklist->auth_user_request,
+                               checklist->src_addr);
+
+        checklist->auth_user_request = NULL;
+
+        return ti;
+
+        /* NOTREACHED */
 #if SQUID_SNMP
+
     case ACL_SNMP_COMMUNITY:
-	return aclMatchWordList((wordlist *)data, checklist->snmp_community);
-	/* NOTREACHED */
+        return aclMatchWordList((wordlist *)data, checklist->snmp_community);
+
+        /* NOTREACHED */
 #endif
+
     case ACL_SRC_ASN:
-	return asnMatchIp(data, checklist->src_addr);
-	/* NOTREACHED */
+        return asnMatchIp(data, checklist->src_addr);
+
+        /* NOTREACHED */
+
     case ACL_DST_ASN:
-	ia = ipcache_gethostbyname(r->host, IP_LOOKUP_IF_MISS);
-	if (ia) {
-	    for (k = 0; k < (int) ia->count; k++) {
-		if (asnMatchIp(data, ia->in_addrs[k]))
-		    return 1;
-	    }
-	    return 0;
-	} else if (checklist->state[ACL_DST_ASN] == ACL_LOOKUP_NONE) {
-	    debug(28, 3) ("asnMatchAcl: Can't yet compare '%s' ACL for '%s'\n",
-		name, r->host);
-	    checklist->changeState (DestinationIPLookup::Instance());
-	} else {
-	    return asnMatchIp(data, no_addr);
-	}
-	return 0;
-	/* NOTREACHED */
+        ia = ipcache_gethostbyname(r->host, IP_LOOKUP_IF_MISS);
+
+        if (ia) {
+            for (k = 0; k < (int) ia->count; k++) {
+                if (asnMatchIp(data, ia->in_addrs[k]))
+                    return 1;
+            }
+
+            return 0;
+        } else if (checklist->state[ACL_DST_ASN] == ACL_LOOKUP_NONE) {
+            debug(28, 3) ("asnMatchAcl: Can't yet compare '%s' ACL for '%s'\n",
+                          name, r->host);
+            checklist->changeState (DestinationIPLookup::Instance());
+        } else {
+            return asnMatchIp(data, no_addr);
+        }
+
+        return 0;
+        /* NOTREACHED */
 #if USE_ARP_ACL
+
     case ACL_SRC_ARP:
-	return aclMatchArp(&data, checklist->src_addr);
-	/* NOTREACHED */
+        return aclMatchArp(&data, checklist->src_addr);
+        /* NOTREACHED */
 #endif
+
     case ACL_REP_MIME_TYPE:
-	if (!checklist->reply)
-	    return 0;
-	header = httpHeaderGetStr(&checklist->reply->header, HDR_CONTENT_TYPE);
-	if (NULL == header)
-	    header = "";
-	return aclMatchRegex((relist *)data, header);
-	/* NOTREACHED */
+
+        if (!checklist->reply)
+            return 0;
+
+        header = httpHeaderGetStr(&checklist->reply->header, HDR_CONTENT_TYPE);
+
+        if (NULL == header)
+            header = "";
+
+        return aclMatchRegex((relist *)data, header);
+
+        /* NOTREACHED */
+
     case ACL_EXTERNAL:
-	return aclMatchExternal(data, checklist);
-	/* NOTREACHED */
+        return aclMatchExternal(data, checklist);
+
+        /* NOTREACHED */
+
     case ACL_NONE:
+
     case ACL_ENUM_MAX:
-	break;
+        break;
+
     case ACL_DERIVED:
-	fatal ("overridden");
+        fatal ("overridden");
     }
+
     debug(28, 0) ("aclMatchAcl: '%s' has bad type %d\n",
-	name, aclType());
+                  name, aclType());
     return 0;
 }
 
