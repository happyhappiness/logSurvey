"Content-Type: text/plain; charset=iso-8859-2\n"
"Content-Transfer-Encoding: 8-bit\n"

#: src/connect.c:195
#, c-format
msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
msgstr ""

# , c-format
#: src/connect.c:267
#, fuzzy, c-format
msgid "Connecting to %s|%s|:%d... "
msgstr "Navazuje se spojen� s %s:%hu... "

# , c-format
#: src/connect.c:270
#, fuzzy, c-format
msgid "Connecting to %s:%d... "
msgstr "Navazuje se spojen� s %s:%hu... "

#: src/connect.c:330
#, fuzzy
msgid "connected.\n"
msgstr "spojeno!\n"

#: src/connect.c:342 src/host.c:752 src/host.c:781
#, c-format
msgid "failed: %s.\n"
msgstr ""

#: src/convert.c:171
#, c-format
msgid "Converted %d files in %s seconds.\n"
msgstr ""

# , c-format
#: src/convert.c:196
#, c-format
msgid "Converting %s... "
msgstr "P�ev�d� se %s... "

#: src/convert.c:209
msgid "nothing to do.\n"
msgstr "nic nen� pot�eba p�ev�d�t.\n"

# , c-format
#: src/convert.c:217 src/convert.c:241
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "Nelze p�ev�st odkazy v %s: %s\n"

# , c-format
#: src/convert.c:232
#, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "Nebylo mo�n� odstranit `%s': %s\n"

# , c-format
#: src/convert.c:441
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "Nelze z�lohovat %s jako %s: %s\n"

#: src/cookies.c:443
#, fuzzy, c-format
msgid "Syntax error in Set-Cookie: %s at position %d.\n"
msgstr "Syntaktick� chyba v hlavi�ce Set-Cookie: P�ed�asn� konec �et�zce.\n"

#: src/cookies.c:685
#, c-format
msgid "Cookie coming from %s attempted to set domain to %s\n"
msgstr ""

# , c-format
#: src/cookies.c:1132 src/cookies.c:1250
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Nelze otev��t soubor s kol��ky `%s': %s\n"

# , c-format
#: src/cookies.c:1287
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "P�i z�pisu do `%s' nastala chyba: %s.\n"

#: src/cookies.c:1290
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "P�i uzav�r�n� `%s' nastala chyba: %s\n"

#: src/ftp-ls.c:836
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Nepodporovan� typ v�pisu, pou�ije se Unixov� parser.\n"

# , c-format
#: src/ftp-ls.c:882 src/ftp-ls.c:884
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Obsah /%s na %s:%d"

#: src/ftp-ls.c:907
#, c-format
msgid "time unknown       "
msgstr "�as nezn�m�        "

#: src/ftp-ls.c:911
#, c-format
msgid "File        "
msgstr "Soubor      "

#: src/ftp-ls.c:914
#, c-format
msgid "Directory   "
msgstr "Adres��     "

#: src/ftp-ls.c:917
#, c-format
msgid "Link        "
msgstr "Sym. odkaz  "

#: src/ftp-ls.c:920
#, c-format
msgid "Not sure    "
msgstr "Nezn�m� typ "

# , c-format
#: src/ftp-ls.c:938
#, c-format
msgid " (%s bytes)"
msgstr " (%s bajt�)"

# , c-format
#: src/ftp.c:209
#, c-format
msgid "Length: %s"
msgstr "D�lka: %s"

#: src/ftp.c:215 src/http.c:2174
#, c-format
msgid ", %s (%s) remaining"
msgstr ""

#: src/ftp.c:219 src/http.c:2178
#, c-format
msgid ", %s remaining"
msgstr ""

#: src/ftp.c:222
msgid " (unauthoritative)\n"
msgstr " (nen� sm�rodatn�)\n"

# , c-format
#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:298
#, c-format
msgid "Logging in as %s ... "
msgstr "Prob�h� p�ihla�ov�n� jako %s ... "

#: src/ftp.c:311 src/ftp.c:357 src/ftp.c:386 src/ftp.c:438 src/ftp.c:550
#: src/ftp.c:596 src/ftp.c:625 src/ftp.c:682 src/ftp.c:743 src/ftp.c:803
#: src/ftp.c:850
msgid "Error in server response, closing control connection.\n"
msgstr ""
"��dic� spojen� bude ukon�eno, proto�e server odpov�d�l chybov�m hl�en�m.\n"

#: src/ftp.c:318
msgid "Error in server greeting.\n"
msgstr "�vodn� odpov�� serveru je chybn�.\n"

#: src/ftp.c:325 src/ftp.c:446 src/ftp.c:558 src/ftp.c:633 src/ftp.c:692
#: src/ftp.c:753 src/ftp.c:813 src/ftp.c:860
msgid "Write failed, closing control connection.\n"
msgstr "R�dic� spojen� bude ukon�eno, proto�e nelze zapsat data.\n"

#: src/ftp.c:331
msgid "The server refuses login.\n"
msgstr "Server odm�t� p�ihl�en�.\n"

#: src/ftp.c:337
msgid "Login incorrect.\n"
msgstr "Chyba p�i p�ihl�en�.\n"

#: src/ftp.c:343
msgid "Logged in!\n"
msgstr "P�ihl�eno!\n"

#: src/ftp.c:365
msgid "Server error, can't determine system type.\n"
msgstr ""
"Nelze zjistit typ vzd�len�ho opera�n�ho syst�mu, proto�e server odpov�d�l "
"chybov�m hl�en�m.\n"

#: src/ftp.c:374 src/ftp.c:669 src/ftp.c:726 src/ftp.c:769
msgid "done.    "
msgstr "hotovo.  "

#: src/ftp.c:426 src/ftp.c:575 src/ftp.c:608 src/ftp.c:833 src/ftp.c:879
msgid "done.\n"
msgstr "hotovo.\n"

# , c-format
#: src/ftp.c:453
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr ""
"R�dic� spojen� bude ukon�eno, proto�e je po�adov�n nezn�m� typ p�enosu `%"
"c'.\n"

#: src/ftp.c:465
msgid "done.  "
msgstr "hotovo."

#: src/ftp.c:471
msgid "==> CWD not needed.\n"
msgstr "==> CWD nen� pot�eba.\n"

# , c-format
#: src/ftp.c:564
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Adres�� `%s' neexistuje.\n"
"\n"

#. do not CWD
#: src/ftp.c:579
msgid "==> CWD not required.\n"
msgstr "==> CWD nen� pot�eba.\n"

#: src/ftp.c:639
msgid "Cannot initiate PASV transfer.\n"
msgstr "Nelze spustit pasivn� p�enos dat.\n"

#: src/ftp.c:643
msgid "Cannot parse PASV response.\n"
msgstr "Odpov�� na PASV nen� pochopiteln�.\n"

#: src/ftp.c:660
#, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr ""

# , c-format
#: src/ftp.c:708
#, c-format
msgid "Bind error (%s).\n"
msgstr "Chyba p�i operaci \"bind\" (%s).\n"

#: src/ftp.c:714
msgid "Invalid PORT.\n"
msgstr "Neplatn� PORT.\n"

#: src/ftp.c:760
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"P��kaz REST selhal, p�enos za�ne od za��tku souboru.\n"

# , c-format
#: src/ftp.c:821
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Soubor `%s' neexistuje.\n"
"\n"

# , c-format
#: src/ftp.c:868
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Soubor �i adres�� `%s' neexistuje.\n"
"\n"

#. We cannot just invent a new name and use it (which is
#. what functions like unique_create typically do)
#. because we told the user we'd use this name.
#. Instead, return and retry the download.
#: src/ftp.c:930 src/http.c:2236
#, c-format
msgid "%s has sprung into existence.\n"
msgstr ""

# , c-format
#: src/ftp.c:982
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, ��dic� spojen� bude ukon�eno.\n"

# , c-format
#: src/ftp.c:991
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Datov� spojen�: %s; "

#: src/ftp.c:1006
msgid "Control connection closed.\n"
msgstr "��dic� spojen� bylo ukon�eno.\n"

#: src/ftp.c:1024
msgid "Data transfer aborted.\n"
msgstr "P�enos dat byl p�ed�asn� ukon�en.\n"

# , c-format
#: src/ftp.c:1092
#, fuzzy, c-format
msgid "File `%s' already there; not retrieving.\n"
msgstr "Soubor `%s' je ji� zde a nen� jej t�eba p�en�et.\n"

# , c-format
#: src/ftp.c:1160 src/http.c:2375
#, c-format
msgid "(try:%2d)"
msgstr "(pokus:%2d)"

# , c-format
#: src/ftp.c:1230 src/http.c:2683
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s]\n"
"\n"
msgstr ""
"%s (%s) - `%s' ulo�en [%ld]\n"
"\n"

# , c-format
#: src/ftp.c:1272 src/main.c:990 src/recur.c:376 src/retr.c:859
#, c-format
msgid "Removing %s.\n"
msgstr "Ma�e se %s.\n"

# , c-format
#: src/ftp.c:1314
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Seznam soubor� bude do�asn� ulo�en v `%s'.\n"

# , c-format
#: src/ftp.c:1329
#, c-format
msgid "Removed `%s'.\n"
msgstr "Soubor `%s' byl vymaz�n.\n"

# , c-format
#: src/ftp.c:1362
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Hloubka rekurze %d p�ekro�ila maxim�ln� hloubku %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1432
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr ""
"Vzd�len� soubor nen� nov�j��, ne� lok�ln� soubor `%s', a nen� jej t�eba "
"stahovat.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1439
#, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr ""
"Vzd�len� soubor je nov�j��, ne� lok�ln� soubor `%s', a je jej t�eba "
"st�hnout.\n"
"\n"

# , c-format
#. Sizes do not match
#: src/ftp.c:1446
#, fuzzy, c-format
msgid ""
"The sizes do not match (local %s) -- retrieving.\n"
"\n"
msgstr ""
"Velikosti se neshoduj� (lok�ln� %ld), soubor je t�eba st�hnout.\n"
"\n"

#: src/ftp.c:1464
msgid "Invalid name of the symlink, skipping.\n"
msgstr "P�eskakuje se symbolick� odkaz, nebo� n�zev odkazu nen� platn�.\n"

# , c-format
#: src/ftp.c:1481
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"Korektn� symbolick� odkaz %s -> %s ji� existuje.\n"
"\n"

# , c-format
#: src/ftp.c:1489
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Vytv��� se symbolick� odkaz %s -> %s\n"

# , c-format
#: src/ftp.c:1499
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr ""
"Symbolick� odkaz `%s' bude vynech�n, proto�e syst�m symbolick� odkazy "
"nepodporuje.\n"

# , c-format
#: src/ftp.c:1511
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Adres�� `%s' bude vynech�n.\n"

# , c-format
#: src/ftp.c:1520
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: nezn�m�/nepodporovan� typ souboru.\n"

# , c-format
#: src/ftp.c:1547
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: �asov� raz�tko souboru je poru�en�.\n"

# , c-format
#: src/ftp.c:1575
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ""
"Podadres��e se nebudou p�en�et, proto�e ji� bylo dosa�eno hloubky %d "
"(maximum je %d).\n"

# , c-format
#: src/ftp.c:1625
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr ""
"Do adres��e `%s' se nesetupuje, proto�e tento adres�� se bu� m� vynechat "
"nebo\n"
"nebyl zad�n k proch�zen�.\n"

# , c-format
#: src/ftp.c:1691 src/ftp.c:1705
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Soubor `%s' se nem� stahovat.\n"
