msgid "Invalid IPv6 numeric address"
msgstr "IPv6 位址無效"

#: src/utils.c:327
#, c-format
msgid "Continuing in background, pid %d.\n"
msgstr "繼續在背景中執行，pid 為 %d。\n"

#: src/utils.c:375
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr "無法刪除符號鏈結 '%s': %s\n"
Steven M. Schweda.
ChangeLog          |  3 +++
lib/Makefile.am    |  2 +-
m4/gnulib-cache.m4 |  2 +-
m4/longlong.m4     | 13 ++++++++-----
m4/ulonglong.m4    | 13 ++++++++-----
maint.mk           |  2 +-
6 files changed, 22 insertions(+), 13 deletions(-)
