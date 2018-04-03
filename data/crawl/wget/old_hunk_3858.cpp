"Content-Transfer-Encoding: 8-bit\n"

# , c-format
#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:147 src/http.c:346
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Nav�zujem spojenie s %s:%hu... "

# , c-format
#: src/ftp.c:169 src/ftp.c:411 src/http.c:363
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Spojenie s %s:%hu odmietnut�.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:190 src/http.c:374
msgid "connected!\n"
msgstr "spojen�!\n"

# , c-format
#: src/ftp.c:191
#, c-format
msgid "Logging in as %s ... "
msgstr "Prihlasujem sa ako %s ... "

#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
msgid "Error in server response, closing control connection.\n"
msgstr "Server odpovedal chybne, uzatv�ram riadiace spojenie.\n"

#: src/ftp.c:208
msgid "Error in server greeting.\n"
msgstr "�vodn� odpove� serveru je chybn�.\n"

#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
msgid "Write failed, closing control connection.\n"
msgstr "Nem��em zap�sa� d�ta, uzatv�ram riadiace spojenie.\n"

#: src/ftp.c:223
msgid "The server refuses login.\n"
msgstr "Server odmieta prihl�senie.\n"

#: src/ftp.c:230
msgid "Login incorrect.\n"
msgstr "Chyba pri prihl�sen�.\n"

#: src/ftp.c:237
msgid "Logged in!\n"
msgstr "Prihl�sen�!\n"

# , c-format
#: src/ftp.c:270
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Nezn�my typ `%c', uzatv�ram riadiace spojenie.\n"

#: src/ftp.c:283
msgid "done.  "
msgstr "hotovo."

#: src/ftp.c:289
msgid "==> CWD not needed.\n"
msgstr "==> CWD nie je potrebn�.\n"

# , c-format
#: src/ftp.c:317
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Adres�r `%s' neexistuje.\n\n"

#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1431
msgid "done.\n"
msgstr "hotovo.\n"

#. do not CWD
#: src/ftp.c:335
msgid "==> CWD not required.\n"
msgstr "==> CWD nie je potrebn�.\n"

#: src/ftp.c:369
msgid "Cannot initiate PASV transfer.\n"
msgstr "Nemo�no inicializova� prenos pr�kazom PASV.\n"

#: src/ftp.c:373
msgid "Cannot parse PASV response.\n"
msgstr "Odpovr� na PASV je nepochopite�n�.\n"

# , c-format
#: src/ftp.c:387
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Pok�sim sa spoji� s %s:%hu.\n"

#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
msgid "done.    "
msgstr "hotovo.  "

# , c-format
#: src/ftp.c:474
#, c-format
msgid "Bind error (%s).\n"
msgstr "Chyba pri oper�cii \"bind\" (%s).\n"

#: src/ftp.c:490
msgid "Invalid PORT.\n"
msgstr "Neplatn� PORT.\n"

#: src/ftp.c:537
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nPr�kaz REST zlyhal, pren�am s�bor od za�iatku.\n"

# , c-format
#: src/ftp.c:586
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "S�bor `%s' neexistuje.\n\n"

# , c-format
#: src/ftp.c:634
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "S�bor alebo adres�r `%s' neexistuje.\n\n"

# , c-format
#: src/ftp.c:692 src/ftp.c:699
#, c-format
msgid "Length: %s"
msgstr "D�ka: %s"

# , c-format
#: src/ftp.c:694 src/ftp.c:701
#, c-format
msgid " [%s to go]"
msgstr " [ost�va %s]"

#: src/ftp.c:703
msgid " (unauthoritative)\n"
msgstr " (nie je smerodajn�)\n"

# , c-format
#: src/ftp.c:721
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, uzatv�ram riadiace spojenie.\n"

# , c-format
#: src/ftp.c:729
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - D�tov� spojenie: %s; "

#: src/ftp.c:746
msgid "Control connection closed.\n"
msgstr "Riadiace spojenie uzatvoren�.\n"

#: src/ftp.c:764
msgid "Data transfer aborted.\n"
msgstr "Prenos d�t bol pred�asne ukon�en�.\n"

# , c-format
#: src/ftp.c:830
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "S�bor `%s' je u� tu, nebudem ho pren�a�.\n"

# , c-format
#: src/ftp.c:896 src/http.c:922
#, c-format
msgid "(try:%2d)"
msgstr "(pokus:%2d)"

# , c-format
#: src/ftp.c:955 src/http.c:1116
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' ulo�en� [%ld]\n\n"

# , c-format
#: src/ftp.c:1001
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Zoznam s�borov bude do�asne ulo�en� v `%s'.\n"

# , c-format
#: src/ftp.c:1013
#, c-format
msgid "Removed `%s'.\n"
msgstr "Vymazan� `%s'.\n"

# , c-format
#: src/ftp.c:1049
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "H�bka rekurzie %d prekro�ila maxim�lnu povolen� h�bku %d.\n"

# , c-format
#: src/ftp.c:1096 src/http.c:1054
#, c-format
msgid "Local file `%s' is more recent, not retrieving.\n\n"
msgstr "S�bor `%s' nebudem pren�a�, preto�e je lok�lna verzia nov�ia.\n\n"

# , c-format
#: src/ftp.c:1102 src/http.c:1060
#, c-format
msgid "The sizes do not match (local %ld), retrieving.\n"
msgstr "Ve�kosti se nezhoduj� (lok�lne %ld), pren�am.\n"

#: src/ftp.c:1119
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Neplatn� n�zov symoblick�ho odkazu, preskakujem.\n"

# , c-format
#: src/ftp.c:1136
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Korektn� symbolick� odkaz %s -> %s u� existuje.\n\n"

# , c-format
#: src/ftp.c:1144
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Vytv�ram symbolick� odkaz %s -> %s\n"

# , c-format
#: src/ftp.c:1155
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr ""
