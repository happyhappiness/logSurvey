# , c-format
#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:151 src/http.c:618
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Naväzujem spojenie s %s:%hu... "

# , c-format
#: src/ftp.c:173 src/ftp.c:517 src/http.c:635
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Spojenie s %s:%hu odmietnuté.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:194 src/http.c:646
msgid "connected!\n"
msgstr "spojené!\n"

# , c-format
#: src/ftp.c:195
#, c-format
msgid "Logging in as %s ... "
msgstr "Prihlasujem sa ako %s ... "

#: src/ftp.c:204 src/ftp.c:257 src/ftp.c:288 src/ftp.c:313 src/ftp.c:407
#: src/ftp.c:459 src/ftp.c:553 src/ftp.c:626 src/ftp.c:674 src/ftp.c:722
msgid "Error in server response, closing control connection.\n"
msgstr "Server odpovedal chybne, uzatváram riadiace spojenie.\n"

#: src/ftp.c:212
msgid "Error in server greeting.\n"
msgstr "Úvodná odpoveï serveru je chybná.\n"

#: src/ftp.c:220 src/ftp.c:322 src/ftp.c:416 src/ftp.c:468 src/ftp.c:563
#: src/ftp.c:636 src/ftp.c:684 src/ftp.c:732
msgid "Write failed, closing control connection.\n"
msgstr "Nemô¾em zapísa» dáta, uzatváram riadiace spojenie.\n"

#: src/ftp.c:227
msgid "The server refuses login.\n"
msgstr "Server odmieta prihlásenie.\n"

#: src/ftp.c:234
msgid "Login incorrect.\n"
msgstr "Chyba pri prihlásení.\n"

#: src/ftp.c:241
msgid "Logged in!\n"
msgstr "Prihlásený!\n"

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
msgstr "Neznámy typ `%c', uzatváram riadiace spojenie.\n"

#: src/ftp.c:343
msgid "done.  "
msgstr "hotovo."

#: src/ftp.c:349
msgid "==> CWD not needed.\n"
msgstr "==> CWD nie je potrebné.\n"

# , c-format
#: src/ftp.c:423
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Adresár `%s' neexistuje.\n"
"\n"

#. do not CWD
#: src/ftp.c:441
msgid "==> CWD not required.\n"
msgstr "==> CWD nie je potrebné.\n"

#: src/ftp.c:475
msgid "Cannot initiate PASV transfer.\n"
msgstr "Nemo¾no inicializova» prenos príkazom PASV.\n"

#: src/ftp.c:479
msgid "Cannot parse PASV response.\n"
msgstr "Odpovrï na PASV je nepochopiteµná.\n"

# , c-format
#: src/ftp.c:493
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Pokúsim sa spoji» s %s:%hu.\n"

# , c-format
#: src/ftp.c:580
#, c-format
msgid "Bind error (%s).\n"
msgstr "Chyba pri operácii \"bind\" (%s).\n"

#: src/ftp.c:596
msgid "Invalid PORT.\n"
msgstr "Neplatný PORT.\n"

#: src/ftp.c:643
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"Príkaz REST zlyhal, prená¹am súbor od zaèiatku.\n"

# , c-format
#: src/ftp.c:692
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Súbor `%s' neexistuje.\n"
"\n"

# , c-format
#: src/ftp.c:740
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Súbor alebo adresár `%s' neexistuje.\n"
"\n"

# , c-format
#: src/ftp.c:816 src/ftp.c:823
#, c-format
msgid "Length: %s"
msgstr "Då¾ka: %s"

# , c-format
#: src/ftp.c:818 src/ftp.c:825
#, c-format
msgid " [%s to go]"
msgstr " [ostáva %s]"

#: src/ftp.c:827
msgid " (unauthoritative)\n"
msgstr " (nie je smerodajné)\n"

# , c-format
#: src/ftp.c:853
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, uzatváram riadiace spojenie.\n"

# , c-format
#: src/ftp.c:861
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Dátové spojenie: %s; "

#: src/ftp.c:878
msgid "Control connection closed.\n"
msgstr "Riadiace spojenie uzatvorené.\n"

#: src/ftp.c:896
msgid "Data transfer aborted.\n"
msgstr "Prenos dát bol predèasne ukonèený.\n"

# , c-format
#: src/ftp.c:960
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Súbor `%s' je u¾ tu, nebudem ho prená¹a».\n"

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
"%s (%s) - `%s' ulo¾ený [%ld]\n"
"\n"

# , c-format
#: src/ftp.c:1127 src/main.c:789 src/recur.c:509 src/retr.c:602
#, c-format
msgid "Removing %s.\n"
msgstr "Ma¾e sa %s.\n"

# , c-format
#: src/ftp.c:1168
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Zoznam súborov bude doèasne ulo¾ený v `%s'.\n"

# , c-format
#: src/ftp.c:1180
#, c-format
msgid "Removed `%s'.\n"
msgstr "Vymazané `%s'.\n"

# , c-format
#: src/ftp.c:1216
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Håbka rekurzie %d prekroèila maximálnu povolenú håbku %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1277
#, fuzzy, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Vzdialený súbor má nov¹í dátum, prená¹am.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1284
#, fuzzy, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr "Vzdialený súbor má nov¹í dátum, prená¹am.\n"

# , c-format
#. Sizes do not match
#: src/ftp.c:1291
#, fuzzy, c-format
msgid ""
"The sizes do not match (local %ld) -- retrieving.\n"
"\n"
msgstr "Veµkosti se nezhodujú (lokálne %ld), prená¹am.\n"

#: src/ftp.c:1308
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Neplatný názov symoblického odkazu, preskakujem.\n"

# , c-format
#: src/ftp.c:1325
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"Korektný symbolický odkaz %s -> %s u¾ existuje.\n"
"\n"

# , c-format
#: src/ftp.c:1333
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Vytváram symbolický odkaz %s -> %s\n"

# , c-format
#: src/ftp.c:1344
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr ""
