msgid " (%s bytes)"
msgstr " (%s baiti)"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:187
#, c-format
msgid "Logging in as %s ... "
msgstr "Meldin serverisse kasutajana %s ... "

#: src/ftp.c:196 src/ftp.c:249 src/ftp.c:281 src/ftp.c:330 src/ftp.c:423
#: src/ftp.c:474 src/ftp.c:504 src/ftp.c:568 src/ftp.c:641 src/ftp.c:702
#: src/ftp.c:750
msgid "Error in server response, closing control connection.\n"
msgstr "Vigane serveri vastus, sulgen juhtühenduse.\n"

#: src/ftp.c:204
msgid "Error in server greeting.\n"
msgstr "Vigane serveri tervitus.\n"

#: src/ftp.c:212 src/ftp.c:339 src/ftp.c:432 src/ftp.c:513 src/ftp.c:578
#: src/ftp.c:651 src/ftp.c:712 src/ftp.c:760
msgid "Write failed, closing control connection.\n"
msgstr "Kirjutamine ebaõnnestus, sulgen juhtühenduse.\n"

#: src/ftp.c:219
msgid "The server refuses login.\n"
msgstr "Server ei luba meldida.\n"

#: src/ftp.c:226
msgid "Login incorrect.\n"
msgstr "Vigane meldimine.\n"

#: src/ftp.c:233
msgid "Logged in!\n"
msgstr "Melditud!\n"

#: src/ftp.c:258
msgid "Server error, can't determine system type.\n"
msgstr "Viga serveris, ei suuda tuvastada süsteemi tüüpi.\n"

#: src/ftp.c:268 src/ftp.c:553 src/ftp.c:625 src/ftp.c:682
msgid "done.    "
msgstr "tehtud.  "

#: src/ftp.c:318 src/ftp.c:453 src/ftp.c:488 src/ftp.c:733 src/ftp.c:781
#: src/host.c:263
msgid "done.\n"
msgstr "tehtud.\n"

#: src/ftp.c:347
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Tundmatu tüüp `%c', sulgen juhtühenduse.\n"

#: src/ftp.c:360
msgid "done.  "
msgstr "tehtud.  "

#: src/ftp.c:366
msgid "==> CWD not needed.\n"
msgstr "==> CWD pole vajalik.\n"

#: src/ftp.c:439
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Kataloogi `%s' pole.\n\n"

#. do not CWD
#: src/ftp.c:457
msgid "==> CWD not required.\n"
msgstr "==> CWD ei ole kohustuslik.\n"

#: src/ftp.c:520
msgid "Cannot initiate PASV transfer.\n"
msgstr "Ei saa algatada PASV ülekannet.\n"

#: src/ftp.c:524
msgid "Cannot parse PASV response.\n"
msgstr "Ei suuda analüüsida PASV vastust.\n"

#: src/ftp.c:545
#, c-format
msgid "couldn't connect to %s:%hu: %s\n"
msgstr "Ei õnnestu luua ühendust serveriga %s:%hu: %s.\n"

#: src/ftp.c:595
#, c-format
msgid "Bind error (%s).\n"
msgstr "Bind operatsiooni viga (%s).\n"

#: src/ftp.c:611
msgid "Invalid PORT.\n"
msgstr "Vale PORT.\n"

#: src/ftp.c:664
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST ebaõnnestus; ei lühenda faili `%s'.\n"

#: src/ftp.c:671
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST ebaõnnestus, alustan algusest.\n"

#: src/ftp.c:720
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Faili `%s' pole.\n\n"

#: src/ftp.c:768
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Faili või kataloogi `%s' pole.\n\n"

#: src/ftp.c:852 src/ftp.c:860
#, c-format
msgid "Length: %s"
msgstr "Pikkus: %s"

#: src/ftp.c:854 src/ftp.c:862
#, c-format
msgid " [%s to go]"
msgstr " [%s on veel]"

#: src/ftp.c:864
msgid " (unauthoritative)\n"
msgstr " (autoriseerimata)\n"

#: src/ftp.c:890
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, sulgen juhtühenduse.\n"

#: src/ftp.c:898
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - andme ühendus: %s; "

#: src/ftp.c:915
msgid "Control connection closed.\n"
msgstr "Juhtühendus suletud.\n"

#: src/ftp.c:933
msgid "Data transfer aborted.\n"
msgstr "Andmete ülekanne katkestatud.\n"

#: src/ftp.c:997
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Fail `%s' on juba olemas, ei tõmba.\n"

#: src/ftp.c:1067 src/http.c:1538
#, c-format
msgid "(try:%2d)"
msgstr "(katse:%2d)"

#: src/ftp.c:1131 src/http.c:1797
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' salvestatud [%ld]\n\n"

#: src/ftp.c:1173 src/main.c:814 src/recur.c:336 src/retr.c:587
#, c-format
msgid "Removing %s.\n"
msgstr "Kustutan %s.\n"

#: src/ftp.c:1215
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Kasutan `%s' ajutise listingu failina.\n"

#: src/ftp.c:1230
#, c-format
msgid "Removed `%s'.\n"
msgstr "Kustutatud `%s'.\n"

#: src/ftp.c:1265
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Rekursiooni sügavus %d ületab maksimum sügavust %d.\n"
