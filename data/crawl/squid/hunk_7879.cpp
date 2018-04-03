 	    break;
 
 	default:
-	    fprintf(stderr,
-		"cached.conf error in IP acl line %s (ignored)\n", ip_str);
+	    debug(3, 0, "addToIPACL: Ignoring invalid IP acl line '%s'\n",
+		ip_str);
 	    return;
 	}
     }
