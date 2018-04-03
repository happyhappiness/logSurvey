"Content-Type: text/plain; charset=iso-8859-2\n"
"Content-Transfer-Encoding: 8bit\n"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:147 src/http.c:348
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Spajam se na %s:%hu... "

#: src/ftp.c:169 src/ftp.c:411 src/http.c:365
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "%s:%hu odbija vezu.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:190 src/http.c:376
msgid "connected!\n"
msgstr "spojen!\n"

#: src/ftp.c:191
#, c-format
msgid "Logging in as %s ... "
msgstr "Logiram se kao %s ... "

#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
msgid "Error in server response, closing control connection.\n"
msgstr "Gre¹ka u odgovoru, zatvaram kontrolnu vezu.\n"

#: src/ftp.c:208
msgid "Error in server greeting.\n"
msgstr "Gre¹ka u poslu¾iteljevom pozdravu.\n"

#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
msgid "Write failed, closing control connection.\n"
msgstr "Write nije uspio, zatvaram kontrolnu vezu.\n"

#: src/ftp.c:223
msgid "The server refuses login.\n"
msgstr "Poslu¾itelj odbija prijavu.\n"

#: src/ftp.c:230
msgid "Login incorrect.\n"
msgstr "Pogre¹na prijava.\n"

#: src/ftp.c:237
msgid "Logged in!\n"
msgstr "Ulogiran!\n"

#: src/ftp.c:270
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Nepoznat tip `%c', zatvaram kontrolnu vezu.\n"

#: src/ftp.c:283
msgid "done.  "
msgstr "gotovo."

#: src/ftp.c:289
msgid "==> CWD not needed.\n"
msgstr "==> CWD ne treba.\n"

#: src/ftp.c:317
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr "Nema direktorija `%s'.\n"

#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1678
msgid "done.\n"
msgstr "gotovo.\n"

#. do not CWD
#: src/ftp.c:335
msgid "==> CWD not required.\n"
msgstr "==> CWD se ne tra¾i.\n"

#: src/ftp.c:369
msgid "Cannot initiate PASV transfer.\n"
msgstr "Ne mogu otpoèeti PASV prijenos.\n"

#: src/ftp.c:373
msgid "Cannot parse PASV response.\n"
msgstr "Ne mogu raspoznati PASV odgovor.\n"

#: src/ftp.c:387
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Poku¹at æu se spojiti na %s:%hu.\n"

#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
msgid "done.    "
msgstr "gotovo.  "

#: src/ftp.c:474
#, c-format
msgid "Bind error (%s).\n"
msgstr "Gre¹ka u bindu (%s).\n"

#: src/ftp.c:490
msgid "Invalid PORT.\n"
msgstr "Pogre¹an PORT.\n"

#: src/ftp.c:537
msgid ""
"\n"
"REST failed, starting from scratch.\n"
