	  asynchronous file operations (Stewart Forster).
	- async_io.c and async_io.h are complete rewrites of the old
	  versions (Stewart Forster).
	- I have rewritten all disk file operations of squid to support
	  the idea of callbacks except where not required (Stewart
	  Forster).
	- UDP_HIT_OBJ not support removed.
	- Background validation of 'tainted' swap log entries (Stewart
	  Forster).
	- Modified storeWriteCleanLog to create the log file using the
	  open/write rather than fopen/printf (Stewart Forster).
	- Added the EINTR error response to handle badly interrupted
	  system calls (Stewart Forster).

==============================================================================

Changes to squid-1.1.8 (March 3, 1997):

	- Fixed neighborsUdpAck() coredump bug for source-ping and
