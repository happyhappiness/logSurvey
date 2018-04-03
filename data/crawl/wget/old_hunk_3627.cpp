# , c-format
#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:151 src/http.c:618
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Nav�zujem spojenie s %s:%hu... "

# , c-format
#: src/ftp.c:173 src/ftp.c:517 src/http.c:635
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Spojenie s %s:%hu odmietnut�.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:194 src/http.c:646
msgid "connected!\n"
msgstr "spojen�!\n"

# , c-format
#: src/ftp.c:195
#, c-format
msgid "Logging in as %s ... "
msgstr "Prihlasujem sa ako %s ... "

#: src/ftp.c:204 src/ftp.c:257 src/ftp.c:288 src/ftp.c:313 src/ftp.c:407
#: src/ftp.c:459 src/ftp.c:553 src/ftp.c:626 src/ftp.c:674 src/ftp.c:722
msgid "Error in server response, closing control connection.\n"
msgstr "Server odpovedal chybne, uzatv�ram riadiace spojenie.\n"

#: src/ftp.c:212
msgid "Error in server greeting.\n"
msgstr "�vodn� odpove� serveru je chybn�.\n"

#: src/ftp.c:220 src/ftp.c:322 src/ftp.c:416 src/ftp.c:468 src/ftp.c:563
#: src/ftp.c:636 src/ftp.c:684 src/ftp.c:732
msgid "Write failed, closing control connection.\n"
msgstr "Nem��em zap�sa� d�ta, uzatv�ram riadiace spojenie.\n"

#: src/ftp.c:227
msgid "The server refuses login.\n"
msgstr "Server odmieta prihl�senie.\n"

#: src/ftp.c:234
msgid "Login incorrect.\n"
msgstr "Chyba pri prihl�sen�.\n"

#: src/ftp.c:241
msgid "Logged in!\n"
msgstr "Prihl�sen�!\n"

#: src/ftp.c:266
msgid "Server error, can't determine system type.\n"
msgstr ""

#: src/ftp.c:276 src/ftp.c:538 src/ftp.c:610 src/ftp.c:654
msgid "done.    "
msgstr "hotovo.  "

#: src/ftp.c:302 src/ftp.c:437 src/ftp.c:705 src/ftp.c:753 src/url.c:1432
msgid "done.\n"
msgstr "hotovo.\n"

# , c-format
#: src/ftp.c:330
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Nezn�my typ `%c', uzatv�ram riadiace spojenie.\n"

#: src/ftp.c:343
msgid "done.  "
msgstr "hotovo."

#: src/ftp.c:349
msgid "==> CWD not needed.\n"
msgstr "==> CWD nie je potrebn�.\n"

# , c-format
#: src/ftp.c:423
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Adres�r `%s' neexistuje.\n"
"\n"

#. do not CWD
#: src/ftp.c:441
msgid "==> CWD not required.\n"
msgstr "==> CWD nie je potrebn�.\n"

#: src/ftp.c:475
msgid "Cannot initiate PASV transfer.\n"
msgstr "Nemo�no inicializova� prenos pr�kazom PASV.\n"

#: src/ftp.c:479
msgid "Cannot parse PASV response.\n"
msgstr "Odpovr� na PASV je nepochopite�n�.\n"

# , c-format
#: src/ftp.c:493
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Pok�sim sa spoji� s %s:%hu.\n"

# , c-format
#: src/ftp.c:580
#, c-format
msgid "Bind error (%s).\n"
msgstr "Chyba pri oper�cii \"bind\" (%s).\n"

#: src/ftp.c:596
msgid "Invalid PORT.\n"
msgstr "Neplatn� PORT.\n"

#: src/ftp.c:643
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"Pr�kaz REST zlyhal, pren�am s�bor od za�iatku.\n"

# , c-format
#: src/ftp.c:692
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"S�bor `%s' neexistuje.\n"
"\n"

# , c-format
#: src/ftp.c:740
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"S�bor alebo adres�r `%s' neexistuje.\n"
"\n"

# , c-format
#: src/ftp.c:816 src/ftp.c:823
#, c-format
msgid "Length: %s"
msgstr "D�ka: %s"

# , c-format
#: src/ftp.c:818 src/ftp.c:825
#, c-format
msgid " [%s to go]"
msgstr " [ost�va %s]"

#: src/ftp.c:827
msgid " (unauthoritative)\n"
msgstr " (nie je smerodajn�)\n"

# , c-format
#: src/ftp.c:853
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, uzatv�ram riadiace spojenie.\n"

# , c-format
#: src/ftp.c:861
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - D�tov� spojenie: %s; "

#: src/ftp.c:878
msgid "Control connection closed.\n"
msgstr "Riadiace spojenie uzatvoren�.\n"

#: src/ftp.c:896
msgid "Data transfer aborted.\n"
msgstr "Prenos d�t bol pred�asne ukon�en�.\n"

# , c-format
#: src/ftp.c:960
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "S�bor `%s' je u� tu, nebudem ho pren�a�.\n"

# , c-format
#: src/ftp.c:1021 src/http.c:1394
#, c-format
msgid "(try:%2d)"
msgstr "(pokus:%2d)"

# , c-format
#: src/ftp.c:1085 src/http.c:1632
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' ulo�en� [%ld]\n"
"\n"

# , c-format
#: src/ftp.c:1127 src/main.c:789 src/recur.c:509 src/retr.c:602
#, c-format
msgid "Removing %s.\n"
msgstr "Ma�e sa %s.\n"

# , c-format
#: src/ftp.c:1168
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Zoznam s�borov bude do�asne ulo�en� v `%s'.\n"

# , c-format
#: src/ftp.c:1180
#, c-format
msgid "Removed `%s'.\n"
msgstr "Vymazan� `%s'.\n"

# , c-format
#: src/ftp.c:1216
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "H�bka rekurzie %d prekro�ila maxim�lnu povolen� h�bku %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1277
#, fuzzy, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Vzdialen� s�bor m� nov�� d�tum, pren�am.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1284
#, fuzzy, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr "Vzdialen� s�bor m� nov�� d�tum, pren�am.\n"

# , c-format
#. Sizes do not match
#: src/ftp.c:1291
#, fuzzy, c-format
msgid ""
"The sizes do not match (local %ld) -- retrieving.\n"
"\n"
msgstr "Ve�kosti se nezhoduj� (lok�lne %ld), pren�am.\n"

#: src/ftp.c:1308
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Neplatn� n�zov symoblick�ho odkazu, preskakujem.\n"

# , c-format
#: src/ftp.c:1325
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"Korektn� symbolick� odkaz %s -> %s u� existuje.\n"
"\n"

# , c-format
#: src/ftp.c:1333
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Vytv�ram symbolick� odkaz %s -> %s\n"

# , c-format
#: src/ftp.c:1344
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr ""
