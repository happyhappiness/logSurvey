"Content-Transfer-Encoding: 8-bit\n"

# , c-format
#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:147 src/http.c:346
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Naväzujem spojenie s %s:%hu... "

# , c-format
#: src/ftp.c:169 src/ftp.c:411 src/http.c:363
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Spojenie s %s:%hu odmietnuté.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:190 src/http.c:374
msgid "connected!\n"
msgstr "spojené!\n"

# , c-format
#: src/ftp.c:191
#, c-format
msgid "Logging in as %s ... "
msgstr "Prihlasujem sa ako %s ... "

#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
msgid "Error in server response, closing control connection.\n"
msgstr "Server odpovedal chybne, uzatváram riadiace spojenie.\n"

#: src/ftp.c:208
msgid "Error in server greeting.\n"
msgstr "Úvodná odpoveï serveru je chybná.\n"

#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
msgid "Write failed, closing control connection.\n"
msgstr "Nemô¾em zapísa» dáta, uzatváram riadiace spojenie.\n"

#: src/ftp.c:223
msgid "The server refuses login.\n"
msgstr "Server odmieta prihlásenie.\n"

#: src/ftp.c:230
msgid "Login incorrect.\n"
msgstr "Chyba pri prihlásení.\n"

#: src/ftp.c:237
msgid "Logged in!\n"
msgstr "Prihlásený!\n"

# , c-format
#: src/ftp.c:270
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Neznámy typ `%c', uzatváram riadiace spojenie.\n"

#: src/ftp.c:283
msgid "done.  "
msgstr "hotovo."

#: src/ftp.c:289
msgid "==> CWD not needed.\n"
msgstr "==> CWD nie je potrebné.\n"

# , c-format
#: src/ftp.c:317
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Adresár `%s' neexistuje.\n\n"

#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1431
msgid "done.\n"
msgstr "hotovo.\n"

#. do not CWD
#: src/ftp.c:335
msgid "==> CWD not required.\n"
msgstr "==> CWD nie je potrebné.\n"

#: src/ftp.c:369
msgid "Cannot initiate PASV transfer.\n"
msgstr "Nemo¾no inicializova» prenos príkazom PASV.\n"

#: src/ftp.c:373
msgid "Cannot parse PASV response.\n"
msgstr "Odpovrï na PASV je nepochopiteµná.\n"

# , c-format
#: src/ftp.c:387
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Pokúsim sa spoji» s %s:%hu.\n"

#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
msgid "done.    "
msgstr "hotovo.  "

# , c-format
#: src/ftp.c:474
#, c-format
msgid "Bind error (%s).\n"
msgstr "Chyba pri operácii \"bind\" (%s).\n"

#: src/ftp.c:490
msgid "Invalid PORT.\n"
msgstr "Neplatný PORT.\n"

#: src/ftp.c:537
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nPríkaz REST zlyhal, prená¹am súbor od zaèiatku.\n"

# , c-format
#: src/ftp.c:586
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Súbor `%s' neexistuje.\n\n"

# , c-format
#: src/ftp.c:634
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Súbor alebo adresár `%s' neexistuje.\n\n"

# , c-format
#: src/ftp.c:692 src/ftp.c:699
#, c-format
msgid "Length: %s"
msgstr "Då¾ka: %s"

# , c-format
#: src/ftp.c:694 src/ftp.c:701
#, c-format
msgid " [%s to go]"
msgstr " [ostáva %s]"

#: src/ftp.c:703
msgid " (unauthoritative)\n"
msgstr " (nie je smerodajné)\n"

# , c-format
#: src/ftp.c:721
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, uzatváram riadiace spojenie.\n"

# , c-format
#: src/ftp.c:729
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Dátové spojenie: %s; "

#: src/ftp.c:746
msgid "Control connection closed.\n"
msgstr "Riadiace spojenie uzatvorené.\n"

#: src/ftp.c:764
msgid "Data transfer aborted.\n"
msgstr "Prenos dát bol predèasne ukonèený.\n"

# , c-format
#: src/ftp.c:830
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Súbor `%s' je u¾ tu, nebudem ho prená¹a».\n"

# , c-format
#: src/ftp.c:896 src/http.c:922
#, c-format
msgid "(try:%2d)"
msgstr "(pokus:%2d)"

# , c-format
#: src/ftp.c:955 src/http.c:1116
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' ulo¾ený [%ld]\n\n"

# , c-format
#: src/ftp.c:1001
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Zoznam súborov bude doèasne ulo¾ený v `%s'.\n"

# , c-format
#: src/ftp.c:1013
#, c-format
msgid "Removed `%s'.\n"
msgstr "Vymazané `%s'.\n"

# , c-format
#: src/ftp.c:1049
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Håbka rekurzie %d prekroèila maximálnu povolenú håbku %d.\n"

# , c-format
#: src/ftp.c:1096 src/http.c:1054
#, c-format
msgid "Local file `%s' is more recent, not retrieving.\n\n"
msgstr "Súbor `%s' nebudem prená¹a», preto¾e je lokálna verzia nov¹ia.\n\n"

# , c-format
#: src/ftp.c:1102 src/http.c:1060
#, c-format
msgid "The sizes do not match (local %ld), retrieving.\n"
msgstr "Veµkosti se nezhodujú (lokálne %ld), prená¹am.\n"

#: src/ftp.c:1119
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Neplatný názov symoblického odkazu, preskakujem.\n"

# , c-format
#: src/ftp.c:1136
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Korektný symbolický odkaz %s -> %s u¾ existuje.\n\n"

# , c-format
#: src/ftp.c:1144
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Vytváram symbolický odkaz %s -> %s\n"

# , c-format
#: src/ftp.c:1155
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr ""
