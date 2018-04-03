# Slovak translations for GNU wget
# Copyright (C) 1999, 2002 Free Software Foundation, Inc.
# Marcel Telka <marcel@telka.sk>, 2002.
# Miroslav Vasko <vasko@debian.cz>, 1999.
#
msgid ""
msgstr ""
"Project-Id-Version: GNU wget 1.8.1\n"
"POT-Creation-Date: 2001-12-17 16:30+0100\n"
"PO-Revision-Date: 2002-01-16 19:57+0100\n"
"Last-Translator: Marcel Telka <marcel@telka.sk>\n"
"Language-Team: Slovak <sk-i18n@lists.linux.sk>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-2\n"
"Content-Transfer-Encoding: 8-bit\n"

# , c-format
#: src/connect.c:94
#, c-format
msgid "Connecting to %s[%s]:%hu... "
msgstr "Pripájam sa k %s[%s]:%hu... "

# , c-format
#: src/connect.c:97
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Pripájam sa k %s:%hu... "

#: src/connect.c:131
msgid "connected.\n"
msgstr "pripojené.\n"

#: src/cookies.c:595
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Chyba v Set-Cookie, pole `%s'"

#: src/cookies.c:619
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Chyba syntaxe v Set-Cookie na znaku `%c'.\n"

#: src/cookies.c:627
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Chyba syntaxe v Set-Cookie: predèasný koniec re»azca.\n"

# , c-format
#: src/cookies.c:1329
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Nedoká¾em otvori» súbor s cookie `%s': %s\n"

# , c-format
#: src/cookies.c:1341
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Chyba pri zápise do `%s': %s\n"

#: src/cookies.c:1345
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Chyba pri zatváraní `%s': %s\n"

#: src/ftp-ls.c:802
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Nepodporovaný typ výpisu, skú¹a sa unixový parser.\n"

# , c-format
#: src/ftp-ls.c:847 src/ftp-ls.c:849
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Obsah /%s na %s:%d"

#: src/ftp-ls.c:871
msgid "time unknown       "
msgstr "èas neznámy        "

#: src/ftp-ls.c:875
msgid "File        "
msgstr "Súbor       "

#: src/ftp-ls.c:878
msgid "Directory   "
msgstr "Adresár     "

#: src/ftp-ls.c:881
msgid "Link        "
msgstr "Sym. odkaz  "

#: src/ftp-ls.c:884
msgid "Not sure    "
msgstr "Neznámy typ "

# , c-format
#: src/ftp-ls.c:902
#, c-format
msgid " (%s bytes)"
msgstr " (%s bajtov)"

# , c-format
#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:179
#, c-format
msgid "Logging in as %s ... "
msgstr "Prihlasujem sa ako %s ... "

#: src/ftp.c:188 src/ftp.c:241 src/ftp.c:272 src/ftp.c:326 src/ftp.c:419
#: src/ftp.c:470 src/ftp.c:500 src/ftp.c:564 src/ftp.c:628 src/ftp.c:689
#: src/ftp.c:737
msgid "Error in server response, closing control connection.\n"
msgstr "Server odpovedal chybne, uzatváram riadiace spojenie.\n"

#: src/ftp.c:196
msgid "Error in server greeting.\n"
msgstr "Úvodná odpoveï servera je chybná.\n"

#: src/ftp.c:204 src/ftp.c:335 src/ftp.c:428 src/ftp.c:509 src/ftp.c:574
#: src/ftp.c:638 src/ftp.c:699 src/ftp.c:747
msgid "Write failed, closing control connection.\n"
msgstr "Nemô¾em zapísa» dáta, uzatváram riadiace spojenie.\n"

#: src/ftp.c:211
msgid "The server refuses login.\n"
msgstr "Server odmieta prihlásenie.\n"

#: src/ftp.c:218
msgid "Login incorrect.\n"
msgstr "Chyba pri prihlásení.\n"

#: src/ftp.c:225
msgid "Logged in!\n"
msgstr "Prihlásený!\n"

#: src/ftp.c:250
msgid "Server error, can't determine system type.\n"
msgstr "Chyba servera, nie je mo¾né zisti» typ systému.\n"

#: src/ftp.c:260 src/ftp.c:549 src/ftp.c:612 src/ftp.c:669
msgid "done.    "
msgstr "hotovo.  "

#: src/ftp.c:314 src/ftp.c:449 src/ftp.c:484 src/ftp.c:720 src/ftp.c:768
#: src/host.c:283
msgid "done.\n"
msgstr "hotovo.\n"

# , c-format
#: src/ftp.c:343
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Neznámy typ `%c', uzatváram riadiace spojenie.\n"

#: src/ftp.c:356
msgid "done.  "
msgstr "hotovo."

#: src/ftp.c:362
msgid "==> CWD not needed.\n"
msgstr "==> CWD nie je potrebné.\n"

# , c-format
#: src/ftp.c:435
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Adresár `%s' neexistuje.\n\n"

#. do not CWD
#: src/ftp.c:453
msgid "==> CWD not required.\n"
msgstr "==> CWD nie je potrebné.\n"

#: src/ftp.c:516
msgid "Cannot initiate PASV transfer.\n"
msgstr "Nemo¾no iniciova» prenos príkazom PASV.\n"

#: src/ftp.c:520
msgid "Cannot parse PASV response.\n"
msgstr "Nemô¾em analyzova» odpoveï na PASV.\n"

# , c-format
#: src/ftp.c:541
#, c-format
msgid "couldn't connect to %s:%hu: %s\n"
msgstr "nemô¾em sa pripoji» k %s:%hu: %s.\n"

# , c-format
#: src/ftp.c:591
#, c-format
msgid "Bind error (%s).\n"
msgstr "Chyba pri operácii \"bind\" (%s).\n"

#: src/ftp.c:598
msgid "Invalid PORT.\n"
msgstr "Neplatný PORT.\n"

#: src/ftp.c:651
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST zlyhal; `%s' sa neskráti.\n"

#: src/ftp.c:658
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST zlyhal, zaèínam odznova.\n"

# , c-format
#: src/ftp.c:707
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Súbor `%s' neexistuje.\n\n"

# , c-format
#: src/ftp.c:755
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Súbor alebo adresár `%s' neexistuje.\n\n"

# , c-format
#: src/ftp.c:839 src/ftp.c:847
#, c-format
msgid "Length: %s"
msgstr "Då¾ka: %s"

# , c-format
#: src/ftp.c:841 src/ftp.c:849
#, c-format
msgid " [%s to go]"
msgstr " [ostáva %s]"

#: src/ftp.c:851
msgid " (unauthoritative)\n"
msgstr " (nie je smerodajné)\n"

# , c-format
#: src/ftp.c:877
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, uzatváram riadiace spojenie.\n"

# , c-format
#: src/ftp.c:885
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Dátové spojenie: %s; "

#: src/ftp.c:902
msgid "Control connection closed.\n"
msgstr "Riadiace spojenie uzatvorené.\n"

#: src/ftp.c:920
msgid "Data transfer aborted.\n"
msgstr "Prenos dát bol predèasne ukonèený.\n"

# , c-format
#: src/ftp.c:984
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Súbor `%s' je u¾ tu, nebudem ho prená¹a».\n"

# , c-format
#: src/ftp.c:1054 src/http.c:1527
#, c-format
msgid "(try:%2d)"
msgstr "(pokus:%2d)"

# , c-format
#: src/ftp.c:1118 src/http.c:1786
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' ulo¾ený [%ld]\n\n"

# , c-format
#: src/ftp.c:1160 src/main.c:819 src/recur.c:349 src/retr.c:587
#, c-format
msgid "Removing %s.\n"
msgstr "Odstraòujem %s.\n"

# , c-format
#: src/ftp.c:1202
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Zoznam súborov bude doèasne ulo¾ený v `%s'.\n"

# , c-format
#: src/ftp.c:1217
#, c-format
msgid "Removed `%s'.\n"
msgstr "Odstránené `%s'.\n"

# , c-format
#: src/ftp.c:1252
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Håbka rekurzie %d prekroèila maximálnu povolenú håbku %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1317
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Vzdialený súbor nie je nov¹í ako miestny súbor `%s' -- neprená¹am.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1324
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "Vzdialený súbor je nov¹í ako miestny súbor `%s' -- prená¹am.\n\n"

# , c-format
#. Sizes do not match
#: src/ftp.c:1331
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "Veµkosti se nezhodujú (miestny %ld) -- prená¹am.\n\n"

#: src/ftp.c:1348
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Neplatný názov symoblického odkazu, preskakujem.\n"

# , c-format
#: src/ftp.c:1365
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Korektný symbolický odkaz %s -> %s u¾ existuje.\n\n"

# , c-format
#: src/ftp.c:1373
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Vytváram symbolický odkaz %s -> %s\n"

# , c-format
#: src/ftp.c:1384
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Symbolické odkazy nie sú podporované, preskakujem symbolický odkaz `%s'.\n"

# , c-format
#: src/ftp.c:1396
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Preskakujem adresár `%s'.\n"

# , c-format
#: src/ftp.c:1405
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: neznámy/nepodporovaný typ súboru.\n"

# , c-format
#: src/ftp.c:1432
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: èasové znaèka súboru je poru¹ená.\n"

# , c-format
#: src/ftp.c:1457
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Nebudem prená¹a» adresáre, preto¾e sme u¾ v håbke %d (maximum je %d).\n"

# , c-format
#: src/ftp.c:1507
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr ""
