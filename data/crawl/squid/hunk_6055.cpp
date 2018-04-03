 	Config.Announce.period = 86400 * 365;	/* one year */
 	Config.onoff.announce = 0;
     }
-#if USE_DNSSERVER
+#if USE_DNSSERVERS
     if (Config.dnsChildren < 1)
 	fatal("No dnsservers allocated");
     if (Config.dnsChildren > DefaultDnsChildrenMax) {
