msgid "ignored"
msgstr ""

#: src/http.c:858
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr ""

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:873
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr ""

#: src/http.c:1015
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr ""

#: src/http.c:1025
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr ""

#: src/http.c:1048
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr ""

#: src/http.c:1060
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""

#: src/http.c:1068
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""

#. We can't collapse this down into just one logprintf()
#. call with a variable set to u->local or the .orig
#. filename because we have to malloc() space for the
#. latter, and because there are multiple returns above (a
#. coding style no-no by many measures, for reasons such as
#. this) we'd have to remember to free() the string at each
#. one to avoid a memory leak.
#: src/http.c:1099
#, c-format
msgid ""
"Server file no newer than local file `%s.orig' -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:1113
msgid "Remote file is newer, retrieving.\n"
msgstr ""

#: src/http.c:1147
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""

#: src/http.c:1181
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr ""

#: src/http.c:1189
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""

#: src/http.c:1202
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr ""

#: src/http.c:1213
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr ""

#: src/http.c:1221
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr ""

#: src/init.c:313 src/netrc.c:250
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr ""

#: src/init.c:334 src/init.c:340
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr ""

#: src/init.c:371
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""

#: src/init.c:459
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr ""

#: src/init.c:486
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr ""

#: src/init.c:504 src/init.c:761 src/init.c:783 src/init.c:856
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr ""

#: src/init.c:617 src/init.c:639 src/init.c:661 src/init.c:687
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr ""
