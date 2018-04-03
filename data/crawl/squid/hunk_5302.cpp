 	fprintf(stderr, "\t-h server\t\tLDAP server (defaults to localhost)\n");
 	fprintf(stderr, "\t-p port\t\t\tLDAP server port\n");
 	fprintf(stderr, "\t-P\t\t\tpersistent LDAP connection\n");
+#if defined(NETSCAPE_SSL)
+	fprintf(stderr, "\t-E sslcertpath\t\tenable LDAP over SSL\n");
+#endif
+	fprintf(stderr, "\t-c timeout\t\tconnect timeout\n");
+	fprintf(stderr, "\t-t timelimit\t\tsearch time limit\n");
 	fprintf(stderr, "\t-R\t\t\tdo not follow referrals\n");
 	fprintf(stderr, "\t-a never|always|search|find\n\t\t\t\twhen to dereference aliases\n");
 #ifdef LDAP_VERSION3
