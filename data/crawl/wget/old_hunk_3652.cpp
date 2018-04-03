#
msgid ""
msgstr ""
"Project-Id-Version: GNU Wget 1.6\n"
"POT-Creation-Date: 2000-11-23 11:23+0100\n"
"PO-Revision-Date: 2001-02-05 21:53+02:00\n"
"Last-Translator: Toomas Soome <tsoome@ut.ee>\n"
"Language-Team: Estonian <linux-ee@eenet.ee>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=ISO-8859-1\n"
"Content-Transfer-Encoding: 8-bit\n"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:147 src/http.c:348
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "V�tan �hendust serveriga %s:%hu... "

#: src/ftp.c:169 src/ftp.c:411 src/http.c:365
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Ei saa �hendust serveriga %s:%hu.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:190 src/http.c:376
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
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Kataloogi `%s' pole.\n"
"\n"

#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1678
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
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"REST eba�nnestus, alustan algusest.\n"

#: src/ftp.c:586
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Faili `%s' pole.\n"
"\n"

#: src/ftp.c:634
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Faili v�i kataloogi `%s' pole.\n"
"\n"

#: src/ftp.c:710 src/ftp.c:717
#, c-format
msgid "Length: %s"
msgstr "Pikkus: %s"

#: src/ftp.c:712 src/ftp.c:719
#, c-format
msgid " [%s to go]"
msgstr " [%s on veel]"

#: src/ftp.c:721
msgid " (unauthoritative)\n"
msgstr " (autoriseerimata)\n"

#: src/ftp.c:747
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, sulgen juht�henduse.\n"

#: src/ftp.c:755
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - andme �hendus: %s; "

#: src/ftp.c:772
msgid "Control connection closed.\n"
msgstr "Juht�hendus suletud.\n"

#: src/ftp.c:790
msgid "Data transfer aborted.\n"
msgstr "Andmete �lekanne katkestatud.\n"

#: src/ftp.c:856
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Fail `%s' on juba olemas, ei t�mba.\n"

#: src/ftp.c:933 src/http.c:1032
#, c-format
msgid "(try:%2d)"
msgstr "(katse:%2d)"

#: src/ftp.c:997 src/http.c:1252
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' salvestatud [%ld]\n"
"\n"

#: src/ftp.c:1039 src/main.c:749 src/recur.c:468 src/retr.c:560
#, c-format
msgid "Removing %s.\n"
msgstr "Kustutan %s.\n"

#: src/ftp.c:1080
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Kasutan `%s' ajutise listingu failina.\n"

#: src/ftp.c:1092
#, c-format
msgid "Removed `%s'.\n"
msgstr "Kustutatud `%s'.\n"

#: src/ftp.c:1128
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Rekursiooni s�gavus %d �letab maksimum s�gavust %d.\n"

#: src/ftp.c:1180 src/http.c:1179
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr "Fail `%s' serveril ei ole uuem, kui lokaalne -- ei lae.\n\n"

#: src/ftp.c:1186 src/http.c:1187
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Suurused ei klapi (lokaalne %ld) -- uuendan.\n"

#: src/ftp.c:1203
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Vigane s�mbol viite nimi, j�tan vahele.\n"

#: src/ftp.c:1220
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"Korrektne s�mbol viide on juba olemas %s -> %s\n"
"\n"

#: src/ftp.c:1228
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Loon s�mbol viite %s -> %s\n"

#: src/ftp.c:1239
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Ei toeta s�mbol viiteid, j�tan `%s' vahele.\n"

#: src/ftp.c:1251
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "J�tan kataloogi `%s' vahele.\n"

#: src/ftp.c:1260
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tundmatu faili t��p.\n"

#: src/ftp.c:1277
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: vigane aeg.\n"

#: src/ftp.c:1298
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Ei t�mba katalooge, kuna s�gavus on %d (maks. %d).\n"

#: src/ftp.c:1337
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "J�tame `%s' vahele, ta on v�listatud v�i pole kaasatud.\n"

#: src/ftp.c:1382
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Keelame `%s'.\n"
