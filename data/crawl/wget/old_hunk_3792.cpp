"Content-Type: text/plain; charset=CHARSET\n"
"Content-Transfer-Encoding: ENCODING\n"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:147 src/http.c:348
#, c-format
msgid "Connecting to %s:%hu... "
msgstr ""

#: src/ftp.c:169 src/ftp.c:411 src/http.c:365
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr ""

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:190 src/http.c:376
msgid "connected!\n"
msgstr ""

#: src/ftp.c:191
#, c-format
msgid "Logging in as %s ... "
msgstr ""

#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
msgid "Error in server response, closing control connection.\n"
msgstr ""

#: src/ftp.c:208
msgid "Error in server greeting.\n"
msgstr ""

#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
msgid "Write failed, closing control connection.\n"
msgstr ""

#: src/ftp.c:223
msgid "The server refuses login.\n"
msgstr ""

#: src/ftp.c:230
msgid "Login incorrect.\n"
msgstr ""

#: src/ftp.c:237
msgid "Logged in!\n"
msgstr ""

#: src/ftp.c:270
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr ""

#: src/ftp.c:283
msgid "done.  "
msgstr ""

#: src/ftp.c:289
msgid "==> CWD not needed.\n"
msgstr ""

#: src/ftp.c:317
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""

#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1671
msgid "done.\n"
msgstr ""

#. do not CWD
#: src/ftp.c:335
msgid "==> CWD not required.\n"
msgstr ""

#: src/ftp.c:369
msgid "Cannot initiate PASV transfer.\n"
msgstr ""

#: src/ftp.c:373
msgid "Cannot parse PASV response.\n"
msgstr ""

#: src/ftp.c:387
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr ""

#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
msgid "done.    "
msgstr ""

#: src/ftp.c:474
#, c-format
msgid "Bind error (%s).\n"
msgstr ""

#: src/ftp.c:490
msgid "Invalid PORT.\n"
msgstr ""

#: src/ftp.c:537
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""

#: src/ftp.c:586
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""

#: src/ftp.c:634
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""

#: src/ftp.c:710 src/ftp.c:717
#, c-format
msgid "Length: %s"
msgstr ""

#: src/ftp.c:712 src/ftp.c:719
#, c-format
msgid " [%s to go]"
msgstr ""

#: src/ftp.c:721
msgid " (unauthoritative)\n"
msgstr ""

#: src/ftp.c:747
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr ""

#: src/ftp.c:755
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr ""

#: src/ftp.c:772
msgid "Control connection closed.\n"
msgstr ""

#: src/ftp.c:790
msgid "Data transfer aborted.\n"
msgstr ""

#: src/ftp.c:856
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr ""

#: src/ftp.c:933 src/http.c:1032
#, c-format, ycp-format
msgid "(try:%2d)"
msgstr ""

#: src/ftp.c:997 src/http.c:1252
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
"\n"
msgstr ""

#: src/ftp.c:1039 src/main.c:749 src/recur.c:468 src/retr.c:560
#, c-format
msgid "Removing %s.\n"
msgstr ""

#: src/ftp.c:1080
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr ""

#: src/ftp.c:1092
#, c-format
msgid "Removed `%s'.\n"
msgstr ""

#: src/ftp.c:1128
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr ""

#: src/ftp.c:1180 src/http.c:1179
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""

#: src/ftp.c:1186 src/http.c:1187
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr ""

#: src/ftp.c:1203
msgid "Invalid name of the symlink, skipping.\n"
msgstr ""

#: src/ftp.c:1220
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""

#: src/ftp.c:1228
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr ""

#: src/ftp.c:1239
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr ""

#: src/ftp.c:1251
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr ""

#: src/ftp.c:1260
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr ""

#: src/ftp.c:1277
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr ""

#: src/ftp.c:1298
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ""

#: src/ftp.c:1337
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr ""

#: src/ftp.c:1382
#, c-format
msgid "Rejecting `%s'.\n"
msgstr ""
