Changes to squid-1.1.alpha19:

	- Fixed stupid coredump bug in storeGetSwapSpace().
	- Cleaned up gopher.c; prototypes, make functions static, etc.
	- Added READ_DEFERRED entry flag.  Only extend lifetime when
	  first entering deferred mode.
	- Added debug_trap() to replace some fatal_dump()'s.  Now use
	  debug_trap for non-fatal errors.  If -C option is set,
	  then debug_trap is the same as fatal_dump.

Changes to squid-1.1.alpha18:

	- Fixed storeCheckPurgeMem() to both 'purge' *and* 'release'