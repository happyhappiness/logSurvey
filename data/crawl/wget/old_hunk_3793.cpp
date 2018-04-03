#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:516
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""

#: src/host.c:544
msgid "Host not found"
msgstr ""

#: src/host.c:546
msgid "Unknown error"
msgstr ""

#: src/html.c:615 src/html.c:617
#, c-format
msgid "Index of /%s on %s:%d"
msgstr ""

#: src/html.c:639
msgid "time unknown       "
msgstr ""

#: src/html.c:643
msgid "File        "
msgstr ""

#: src/html.c:646
msgid "Directory   "
msgstr ""

#: src/html.c:649
msgid "Link        "
msgstr ""

#: src/html.c:652
msgid "Not sure    "
msgstr ""

#: src/html.c:670
#, c-format
msgid " (%s bytes)"
msgstr ""

#: src/http.c:508
msgid "Failed writing HTTP request.\n"
msgstr ""

#: src/http.c:512
#, c-format
msgid "%s request sent, awaiting response... "
msgstr ""

#: src/http.c:551
msgid "End of file while parsing headers.\n"
msgstr ""

#: src/http.c:562
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr ""

#: src/http.c:602
msgid "No data received"
msgstr ""

#: src/http.c:604
msgid "Malformed status line"
msgstr ""

#: src/http.c:609
msgid "(no description)"
msgstr ""

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:693
msgid "Authorization failed.\n"
msgstr ""

#: src/http.c:700
msgid "Unknown authentication scheme.\n"
msgstr ""

#: src/http.c:783
#, c-format
msgid "Location: %s%s\n"
msgstr ""

#: src/http.c:784 src/http.c:809
msgid "unspecified"
msgstr ""

#: src/http.c:785
msgid " [following]"
msgstr ""

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:799
msgid "Length: "
msgstr ""

#: src/http.c:804
#, c-format
msgid " (%s to go)"
msgstr ""

#: src/http.c:809
msgid "ignored"
msgstr ""

#: src/http.c:912
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr ""

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:933
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr ""

#: src/http.c:1099
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr ""

#: src/http.c:1110
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr ""

#: src/http.c:1135
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr ""

#: src/http.c:1148
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""

#: src/http.c:1156
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""

#: src/http.c:1191
msgid "Remote file is newer, retrieving.\n"
msgstr ""

#: src/http.c:1226
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""

#: src/http.c:1274
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr ""

#: src/http.c:1282
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""

#: src/http.c:1302
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr ""

#: src/http.c:1313
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr ""

#: src/http.c:1321
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr ""

#: src/init.c:329 src/netrc.c:260
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr ""
