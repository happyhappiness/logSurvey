# , c-format
#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:150 src/http.c:624
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Naväzujem spojenie s %s:%hu... "

# , c-format
#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Spojenie s %s:%hu odmietnuté.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:193 src/http.c:652
msgid "connected!\n"
msgstr "spojené!\n"

# , c-format
#: src/ftp.c:194
#, c-format
msgid "Logging in as %s ... "
msgstr "Prihlasujem sa ako %s ... "

#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
msgid "Error in server response, closing control connection.\n"
msgstr "Server odpovedal chybne, uzatváram riadiace spojenie.\n"

#: src/ftp.c:211
msgid "Error in server greeting.\n"
msgstr "Úvodná odpoveï serveru je chybná.\n"

#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
msgid "Write failed, closing control connection.\n"
msgstr "Nemô¾em zapísa» dáta, uzatváram riadiace spojenie.\n"

#: src/ftp.c:226
msgid "The server refuses login.\n"
msgstr "Server odmieta prihlásenie.\n"

#: src/ftp.c:233
msgid "Login incorrect.\n"
msgstr "Chyba pri prihlásení.\n"

#: src/ftp.c:240
msgid "Logged in!\n"
msgstr "Prihlásený!\n"

#: src/ftp.c:265
msgid "Server error, can't determine system type.\n"
msgstr "Chyba servera, nie je mo¾né zisti» typ systému.\n"

#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
msgid "done.    "
msgstr "hotovo.  "

#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
msgid "done.\n"
msgstr "hotovo.\n"

# , c-format
#: src/ftp.c:353
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Neznámy typ `%c', uzatváram riadiace spojenie.\n"

#: src/ftp.c:366
msgid "done.  "
msgstr "hotovo."

#: src/ftp.c:372
msgid "==> CWD not needed.\n"
msgstr "==> CWD nie je potrebné.\n"

# , c-format
#: src/ftp.c:445
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Adresár `%s' neexistuje.\n\n"

#. do not CWD
#: src/ftp.c:463
msgid "==> CWD not required.\n"
msgstr "==> CWD nie je potrebné.\n"

#: src/ftp.c:497
msgid "Cannot initiate PASV transfer.\n"
msgstr "Nemo¾no inicializova» prenos príkazom PASV.\n"

#: src/ftp.c:501
msgid "Cannot parse PASV response.\n"
msgstr "Odpovrï na PASV je nepochopiteµná.\n"

# , c-format
#: src/ftp.c:515
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Pokúsim sa spoji» s %s:%hu.\n"

# , c-format
#: src/ftp.c:602
#, c-format
msgid "Bind error (%s).\n"
msgstr "Chyba pri operácii \"bind\" (%s).\n"

#: src/ftp.c:618
msgid "Invalid PORT.\n"
msgstr "Neplatný PORT.\n"

#: src/ftp.c:671
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST zlyhal; `%s' sa neskráti.\n"

#: src/ftp.c:678
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nPríkaz REST zlyhal, prená¹am súbor od zaèiatku.\n"

# , c-format
#: src/ftp.c:727
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Súbor `%s' neexistuje.\n\n"

# , c-format
#: src/ftp.c:775
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Súbor alebo adresár `%s' neexistuje.\n\n"

# , c-format
#: src/ftp.c:859 src/ftp.c:867
#, c-format
msgid "Length: %s"
msgstr "Då¾ka: %s"

# , c-format
#: src/ftp.c:861 src/ftp.c:869
#, c-format
msgid " [%s to go]"
msgstr " [ostáva %s]"

#: src/ftp.c:871
msgid " (unauthoritative)\n"
msgstr " (nie je smerodajné)\n"

# , c-format
#: src/ftp.c:898
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, uzatváram riadiace spojenie.\n"

# , c-format
#: src/ftp.c:906
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Dátové spojenie: %s; "

#: src/ftp.c:923
msgid "Control connection closed.\n"
msgstr "Riadiace spojenie uzatvorené.\n"

#: src/ftp.c:941
msgid "Data transfer aborted.\n"
msgstr "Prenos dát bol predèasne ukonèený.\n"

# , c-format
#: src/ftp.c:1005
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Súbor `%s' je u¾ tu, nebudem ho prená¹a».\n"

# , c-format
#: src/ftp.c:1075 src/http.c:1502
#, c-format
msgid "(try:%2d)"
msgstr "(pokus:%2d)"

# , c-format
#: src/ftp.c:1139 src/http.c:1753
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' ulo¾ený [%ld]\n\n"

# , c-format
#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
#, c-format
msgid "Removing %s.\n"
msgstr "Ma¾e sa %s.\n"

# , c-format
#: src/ftp.c:1221
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Zoznam súborov bude doèasne ulo¾ený v `%s'.\n"

# , c-format
#: src/ftp.c:1233
#, c-format
msgid "Removed `%s'.\n"
msgstr "Vymazané `%s'.\n"

# , c-format
#: src/ftp.c:1269
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Håbka rekurzie %d prekroèila maximálnu povolenú håbku %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1330
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Vzdialený súbor nie je nov¹í ako lokálny súbor `%s' -- neprená¹am.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1337
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "Vzdialený súbor je nov¹í ako lokálny súbor `%s' -- prená¹am.\n\n"

# , c-format
#. Sizes do not match
#: src/ftp.c:1344
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "Veµkosti se nezhodujú (lokálne %ld) -- prená¹am.\n\n"

#: src/ftp.c:1361
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Neplatný názov symoblického odkazu, preskakujem.\n"

# , c-format
#: src/ftp.c:1378
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Korektný symbolický odkaz %s -> %s u¾ existuje.\n\n"

# , c-format
#: src/ftp.c:1386
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Vytváram symbolický odkaz %s -> %s\n"

# , c-format
#: src/ftp.c:1397
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr ""
