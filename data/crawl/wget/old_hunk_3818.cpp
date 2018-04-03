"Content-Type: text/plain; charset=ISO-8859-1\n"
"Content-Transfer-Encoding: 8-bit\n"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:147 src/http.c:346
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "V�tan �hendust serveriga %s:%hu... "

#: src/ftp.c:169 src/ftp.c:411 src/http.c:363
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Ei saa �hendust serveriga %s:%hu.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:190 src/http.c:374
msgid "connected!\n"
msgstr "�hendus loodud!\n"

#: src/ftp.c:191
#, c-format
msgid "Logging in as %s ... "
msgstr "Meldin serverisse kasutajana %s ... "

#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
msgid "Error in server response, closing control connection.\n"
msgstr "Vigane serveri vastus, sulgen juht�henduse.\n"

#: src/ftp.c:208
msgid "Error in server greeting.\n"
msgstr "Vigane serveri tervitus.\n"

#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
msgid "Write failed, closing control connection.\n"
msgstr "Kirjutamine eba�nnestus, sulgen juht�henduse.\n"

#: src/ftp.c:223
msgid "The server refuses login.\n"
msgstr "Server ei luba meldida.\n"

#: src/ftp.c:230
msgid "Login incorrect.\n"
msgstr "Vigane meldimine.\n"

#: src/ftp.c:237
msgid "Logged in!\n"
msgstr "Melditud!\n"

#: src/ftp.c:270
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Tundmatu t��p `%c', sulgen juht�henduse.\n"

#: src/ftp.c:283
msgid "done.  "
msgstr "tehtud.  "

#: src/ftp.c:289
msgid "==> CWD not needed.\n"
msgstr "==> CWD pole vajalik.\n"

#: src/ftp.c:317
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Kataloogi `%s' pole.\n\n"

#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1431
msgid "done.\n"
msgstr "tehtud.\n"

#. do not CWD
#: src/ftp.c:335
msgid "==> CWD not required.\n"
msgstr "==> CWD ei ole kohustuslik.\n"

#: src/ftp.c:369
msgid "Cannot initiate PASV transfer.\n"
msgstr "Ei saa algatada PASV �lekannet.\n"

#: src/ftp.c:373
msgid "Cannot parse PASV response.\n"
msgstr "Ei suuda anal��sida PASV vastust.\n"

#: src/ftp.c:387
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "�ritan �henduda serveriga %s:%hu.\n"

#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
msgid "done.    "
msgstr "tehtud.  "

#: src/ftp.c:474
#, c-format
msgid "Bind error (%s).\n"
msgstr "Bind operatsiooni viga (%s).\n"

#: src/ftp.c:490
msgid "Invalid PORT.\n"
msgstr "Vale PORT.\n"

#: src/ftp.c:537
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST eba�nnestus, alustan algusest.\n"

#: src/ftp.c:586
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Faili `%s' pole.\n\n"

#: src/ftp.c:634
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Faili v�i kataloogi `%s' pole.\n\n"

#: src/ftp.c:692 src/ftp.c:699
#, c-format
msgid "Length: %s"
msgstr "Pikkus: %s"

#: src/ftp.c:694 src/ftp.c:701
#, c-format
msgid " [%s to go]"
msgstr " [%s on veel]"

#: src/ftp.c:703
msgid " (unauthoritative)\n"
msgstr " (autoriseerimata)\n"

#: src/ftp.c:721
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, sulgen juht�henduse.\n"

#: src/ftp.c:729
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - andme �hendus: %s; "

#: src/ftp.c:746
msgid "Control connection closed.\n"
msgstr "Juht�hendus suletud.\n"

#: src/ftp.c:764
msgid "Data transfer aborted.\n"
msgstr "Andmete �lekanne katkestatud.\n"

#: src/ftp.c:830
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Fail `%s' on juba olemas, ei t�mba.\n"

#: src/ftp.c:896 src/http.c:922
#, c-format
msgid "(try:%2d)"
msgstr "(katse:%2d)"

#: src/ftp.c:955 src/http.c:1116
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' salvestatud [%ld]\n\n"

#: src/ftp.c:1001
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Kasutan `%s' ajutise listingu failina.\n"

#: src/ftp.c:1013
#, c-format
msgid "Removed `%s'.\n"
msgstr "Kustutatud `%s'.\n"

#: src/ftp.c:1049
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Rekursiooni s�gavus %d �letab maksimum s�gavust %d.\n"

#: src/ftp.c:1096 src/http.c:1054
#, c-format
msgid "Local file `%s' is more recent, not retrieving.\n\n"
msgstr "Lokaalne fail `%s' on uuem, ei t�mba.\n\n"

#: src/ftp.c:1102 src/http.c:1060
#, c-format
msgid "The sizes do not match (local %ld), retrieving.\n"
msgstr "Suurused ei klapi (lokaalne %ld), uuendan.\n"

#: src/ftp.c:1119
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Vigane s�mbol viite nimi, j�tan vahele.\n"

#: src/ftp.c:1136
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Korrektne s�mbol viide on juba olemas %s -> %s\n\n"

#: src/ftp.c:1144
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Loon s�mbol viite %s -> %s\n"

#: src/ftp.c:1155
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Ei toeta s�mbol viiteid, j�tan `%s' vahele.\n"

#: src/ftp.c:1167
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "J�tan kataloogi `%s' vahele.\n"

#: src/ftp.c:1176
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tundmatu faili t��p.\n"

#: src/ftp.c:1193
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: vigane aeg.\n"

#: src/ftp.c:1213
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Ei t�mba katalooge, kuna s�gavus on %d (maks. %d).\n"

#: src/ftp.c:1252
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "J�tame `%s' vahele, ta on v�listatud v�i pole kaasatud.\n"

#: src/ftp.c:1297
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Keelame `%s'.\n"
