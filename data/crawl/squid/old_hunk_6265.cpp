	- Added configure check for libbind.a.  If found, it will be
	  used instead of libresolv.a.
	- Changed fwdStart() to always allow internally generated
	  requests, such as for peer digests.
	- Completed initial HTCP implementation.  It works, but is not
	  tested much.
	- Added counters for I/O syscalls.
	- Fixed httpMaybeRemovePublic.  With broken ICP neighbors
	  (netapp) Squid doesn't use private keys.  This caused us
	  to remove almost every object from the cache.
	- Added 'asndb' cachemgr stats to show AS Number tree.
	- Fixed comm_incoming calling rate for high loads (Stewart
	  Forster).
	- Give always_direct higher precedence than never_direct
	  (Henrik Nordstrom).
	- experimental attempt to fix "peer disappeared" coredumps

Changes to squid-1.2.beta24 (August 21, 1998):
