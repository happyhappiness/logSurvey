# Slovak translations for GNU wget
# Copyright (C) 1998 Free Software Foundation, Inc.
# Miroslav Vasko <vasko@debian.cz>, 1999
#
msgid ""
msgstr ""
"Project-Id-Version: GNU wget 1.7\n"
"POT-Creation-Date: 2001-06-03 15:27+0200\n"
"PO-Revision-Date: 2001-06-08 20:45 +02:00\n"
"Last-Translator: Stanislav Meduna <stano@eunet.sk>\n"
"Language-Team: Slovak <sk-i18n@rak.isternet.sk>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-2\n"
"Content-Transfer-Encoding: 8-bit\n"

#: src/cookies.c:588
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Chyba v Set-Cookie, pole `%s'"

#: src/cookies.c:612
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Chyba syntaxe v Set-Cookie na znaku `%c'.\n"

#: src/cookies.c:620
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Chyba syntaxe v Set-Cookie: pred�asn� koniec re�azca.\n"

# , c-format
#: src/cookies.c:1352
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Nedok�em otvori� s�bor s cookie `%s': %s\n"

# , c-format
#: src/cookies.c:1364
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Nemo�no zap�sa� do `%s': %s\n"

#: src/cookies.c:1368
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Chyba pri zatv�ran� `%s': %s\n"

#: src/ftp-ls.c:787
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Nepodporovan� typ v�pisu, sk��a sa unixov� parser.\n"

# , c-format
#: src/ftp-ls.c:832 src/ftp-ls.c:834
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Obsah /%s na %s:%d"

#: src/ftp-ls.c:856
msgid "time unknown       "
msgstr "�as nezn�my        "

#: src/ftp-ls.c:860
msgid "File        "
msgstr "S�bor       "

#: src/ftp-ls.c:863
msgid "Directory   "
msgstr "Adres�r     "

#: src/ftp-ls.c:866
msgid "Link        "
msgstr "Sym. odkaz  "

#: src/ftp-ls.c:869
msgid "Not sure    "
msgstr "Nezn�my typ "

# , c-format
#: src/ftp-ls.c:887
#, c-format
msgid " (%s bytes)"
msgstr " (%s bytov)"

# , c-format
#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:150 src/http.c:624
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Nav�zujem spojenie s %s:%hu... "

# , c-format
#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Spojenie s %s:%hu odmietnut�.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:193 src/http.c:652
msgid "connected!\n"
msgstr "spojen�!\n"

# , c-format
#: src/ftp.c:194
#, c-format
msgid "Logging in as %s ... "
msgstr "Prihlasujem sa ako %s ... "

#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
msgid "Error in server response, closing control connection.\n"
msgstr "Server odpovedal chybne, uzatv�ram riadiace spojenie.\n"

#: src/ftp.c:211
msgid "Error in server greeting.\n"
msgstr "�vodn� odpove� serveru je chybn�.\n"

#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
msgid "Write failed, closing control connection.\n"
msgstr "Nem��em zap�sa� d�ta, uzatv�ram riadiace spojenie.\n"

#: src/ftp.c:226
msgid "The server refuses login.\n"
msgstr "Server odmieta prihl�senie.\n"

#: src/ftp.c:233
msgid "Login incorrect.\n"
msgstr "Chyba pri prihl�sen�.\n"

#: src/ftp.c:240
msgid "Logged in!\n"
msgstr "Prihl�sen�!\n"

#: src/ftp.c:265
msgid "Server error, can't determine system type.\n"
msgstr "Chyba servera, nie je mo�n� zisti� typ syst�mu.\n"

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
msgstr "Nezn�my typ `%c', uzatv�ram riadiace spojenie.\n"

#: src/ftp.c:366
msgid "done.  "
msgstr "hotovo."

#: src/ftp.c:372
msgid "==> CWD not needed.\n"
msgstr "==> CWD nie je potrebn�.\n"

# , c-format
#: src/ftp.c:445
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Adres�r `%s' neexistuje.\n\n"

#. do not CWD
#: src/ftp.c:463
msgid "==> CWD not required.\n"
msgstr "==> CWD nie je potrebn�.\n"

#: src/ftp.c:497
msgid "Cannot initiate PASV transfer.\n"
msgstr "Nemo�no inicializova� prenos pr�kazom PASV.\n"

#: src/ftp.c:501
msgid "Cannot parse PASV response.\n"
msgstr "Odpovr� na PASV je nepochopite�n�.\n"

# , c-format
#: src/ftp.c:515
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Pok�sim sa spoji� s %s:%hu.\n"

# , c-format
#: src/ftp.c:602
#, c-format
msgid "Bind error (%s).\n"
msgstr "Chyba pri oper�cii \"bind\" (%s).\n"

#: src/ftp.c:618
msgid "Invalid PORT.\n"
msgstr "Neplatn� PORT.\n"

#: src/ftp.c:671
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST zlyhal; `%s' sa neskr�ti.\n"

#: src/ftp.c:678
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nPr�kaz REST zlyhal, pren�am s�bor od za�iatku.\n"

# , c-format
#: src/ftp.c:727
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "S�bor `%s' neexistuje.\n\n"

# , c-format
#: src/ftp.c:775
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "S�bor alebo adres�r `%s' neexistuje.\n\n"

# , c-format
#: src/ftp.c:859 src/ftp.c:867
#, c-format
msgid "Length: %s"
msgstr "D�ka: %s"

# , c-format
#: src/ftp.c:861 src/ftp.c:869
#, c-format
msgid " [%s to go]"
msgstr " [ost�va %s]"

#: src/ftp.c:871
msgid " (unauthoritative)\n"
msgstr " (nie je smerodajn�)\n"

# , c-format
#: src/ftp.c:898
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, uzatv�ram riadiace spojenie.\n"

# , c-format
#: src/ftp.c:906
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - D�tov� spojenie: %s; "

#: src/ftp.c:923
msgid "Control connection closed.\n"
msgstr "Riadiace spojenie uzatvoren�.\n"

#: src/ftp.c:941
msgid "Data transfer aborted.\n"
msgstr "Prenos d�t bol pred�asne ukon�en�.\n"

# , c-format
#: src/ftp.c:1005
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "S�bor `%s' je u� tu, nebudem ho pren�a�.\n"

# , c-format
#: src/ftp.c:1075 src/http.c:1502
#, c-format
msgid "(try:%2d)"
msgstr "(pokus:%2d)"

# , c-format
#: src/ftp.c:1139 src/http.c:1753
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' ulo�en� [%ld]\n\n"

# , c-format
#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
#, c-format
msgid "Removing %s.\n"
msgstr "Ma�e sa %s.\n"

# , c-format
#: src/ftp.c:1221
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Zoznam s�borov bude do�asne ulo�en� v `%s'.\n"

# , c-format
#: src/ftp.c:1233
#, c-format
msgid "Removed `%s'.\n"
msgstr "Vymazan� `%s'.\n"

# , c-format
#: src/ftp.c:1269
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "H�bka rekurzie %d prekro�ila maxim�lnu povolen� h�bku %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1330
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Vzdialen� s�bor nie je nov�� ako lok�lny s�bor `%s' -- nepren�am.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1337
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "Vzdialen� s�bor je nov�� ako lok�lny s�bor `%s' -- pren�am.\n\n"

# , c-format
#. Sizes do not match
#: src/ftp.c:1344
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "Ve�kosti se nezhoduj� (lok�lne %ld) -- pren�am.\n\n"

#: src/ftp.c:1361
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Neplatn� n�zov symoblick�ho odkazu, preskakujem.\n"

# , c-format
#: src/ftp.c:1378
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Korektn� symbolick� odkaz %s -> %s u� existuje.\n\n"

# , c-format
#: src/ftp.c:1386
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Vytv�ram symbolick� odkaz %s -> %s\n"

# , c-format
#: src/ftp.c:1397
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr ""
"Preskakujem symbolick� odkaz `%s', preto�e tento syst�m symbolick� odkazy\n"
"nepodporuje.\n"

# , c-format
#: src/ftp.c:1409
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Preskakujem adres�r `%s'.\n"

# , c-format
#: src/ftp.c:1418
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: nezn�my/nepodporovan� typ s�boru.\n"

# , c-format
#: src/ftp.c:1445
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: �asov� raz�tko s�boru je poru�en�.\n"

# , c-format
#: src/ftp.c:1466
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Podadres�re nebudem pren�a�, preto�e sme u� v h�bke %d (maximum je %d).\n"

# , c-format
#: src/ftp.c:1512
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr ""
