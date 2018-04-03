	- Changed inet_addr("X") to inet_addr("255.255.255.255")
	  (Dan Riley).
	- Fixed matchInsideFirewall() bug when using 'firewall_ip' but
	  not 'inside_firewall' (Tai Jin).
	- check for text == NULL in icpSendERROR().
	- Don't make inaddr_none static in ftpget.c (Davide Migliavacca).
	- Fixed ipcache FMR bug for long-pending requests.
	- Fixes for NeXTSTEP 3.3 (Tethpub Znek).
	- add storeWriteCleanLog() call in fatal().

Changes to squid-1.1.2 (December 18, 1996):

	- Fixed (negative) caching of HTTP objects witch consist of