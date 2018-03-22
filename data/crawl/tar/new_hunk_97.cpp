2006-12-12  Paul Eggert  <eggert@cs.ucla.edu>

	Port to Forte Developer 7 C 5.4 and C99.
	* src/common.h (add_exclude_tag): Add decl; C99 requires this
	and Forte warns about it.
	* src/incremen.c: Include <mkdtemp.h> for mkdtemp prototype,
	for same reason.
	* src/misc.c (get_max_open_files): Rewrite to avoid code that
	Forte C complains about as being unreachable.
	* src/xheader.c (mtime_code): Rewrite to avoid Forte error
	reported by Trond Hasle Amundsen.

	* src/incremen.c (compare_dirnames): Rewrite to avoid casts.
	* src/utf8.c (string_ascii_p): Likewise.
	* src/xheader.c (mtime_coder, volume_size_coder, volume_offset_coder):
	Likewise.

2006-12-08  Sergey Poznyakoff  <gray@gnu.org.ua>

	* bootstrap: Add paxutils files to dot_ignore.
