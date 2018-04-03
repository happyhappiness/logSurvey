"Downloaded: %s bytes in %d files\n"
msgstr ""

#: src/main.c:976
#, c-format
msgid "Download quota (%s bytes) EXCEEDED!\n"
msgstr ""

#: src/mswindows.c:235
#, c-format
msgid "Continuing in background.\n"
msgstr ""

#: src/mswindows.c:427
#, c-format
msgid "Continuing in background, pid %lu.\n"
msgstr ""

#: src/mswindows.c:429 src/utils.c:348
#, c-format
msgid "Output will be written to `%s'.\n"
msgstr ""

#: src/mswindows.c:597 src/mswindows.c:604
#, c-format
msgid "%s: Couldn't find usable socket driver.\n"
msgstr ""

#: src/netrc.c:385
#, c-format
msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
msgstr ""

#: src/netrc.c:416
#, c-format
msgid "%s: %s:%d: unknown token \"%s\"\n"
msgstr ""

#: src/netrc.c:480
#, c-format
msgid "Usage: %s NETRC [HOSTNAME]\n"
msgstr ""

#: src/netrc.c:490
#, c-format
msgid "%s: cannot stat %s: %s\n"
msgstr ""

#. Still not random enough, presumably because neither /dev/random
#. nor EGD were available.  Try to seed OpenSSL's PRNG with libc
#. PRNG.  This is cryptographically weak and defeats the purpose
#. of using OpenSSL, which is why it is highly discouraged.
#: src/openssl.c:124
msgid "WARNING: using a weak random seed.\n"
msgstr ""

#: src/openssl.c:211
msgid "Could not seed PRNG; consider using --random-file.\n"
msgstr ""

#. Align the [ skipping ... ] line with the dots.  To do
#. that, insert the number of spaces equal to the number of
#. digits in the skipped amount in K.
#: src/progress.c:243
#, c-format
msgid ""
"\n"
"%*s[ skipping %dK ]"
msgstr ""

#: src/progress.c:410
#, c-format
msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
msgstr ""

#: src/recur.c:377
#, c-format
msgid "Removing %s since it should be rejected.\n"
msgstr ""

#: src/res.c:548
msgid "Loading robots.txt; please ignore errors.\n"
msgstr ""

#: src/retr.c:638
#, c-format
msgid "Error parsing proxy URL %s: %s.\n"
msgstr ""

#: src/retr.c:646
#, c-format
msgid "Error in proxy URL %s: Must be HTTP.\n"
msgstr ""

#: src/retr.c:731
#, c-format
msgid "%d redirections exceeded.\n"
msgstr ""

#: src/retr.c:856
msgid ""
"Giving up.\n"
"\n"
msgstr ""

#: src/retr.c:856
msgid ""
"Retrying.\n"
"\n"
msgstr ""

#: src/url.c:642
msgid "No error"
msgstr ""

#: src/url.c:644
msgid "Unsupported scheme"
msgstr ""

#: src/url.c:646
msgid "Empty host"
msgstr ""

#: src/url.c:648
msgid "Bad port number"
msgstr ""

#: src/url.c:650
msgid "Invalid user name"
msgstr ""

#: src/url.c:652
msgid "Unterminated IPv6 numeric address"
msgstr ""

#: src/url.c:654
msgid "IPv6 addresses not supported"
msgstr ""

#: src/url.c:656
msgid "Invalid IPv6 numeric address"
msgstr ""

#. parent, no error
#: src/utils.c:346
#, c-format
msgid "Continuing in background, pid %d.\n"
msgstr ""

#: src/utils.c:390
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr ""

#: src/xmalloc.c:72
#, c-format
msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
msgstr ""

#~ msgid "Unable to convert `%s' to a bind address.  Reverting to ANY.\n"
#~ msgstr "Ne eblis konverti `%s' al adreso. Ŝanĝante al ANY.\n"
