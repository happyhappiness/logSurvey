"Content-Type: text/plain; charset=iso-8859-2\n"
"Content-Transfer-Encoding: 8-bit\n"

#: src/cookies.c:588
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Chyba v hlavi�ce Set-Cookie v poli `%s'"

#: src/cookies.c:612
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Syntaktick� chyba v hlavi�ce Set-Cookie na znaku `%c'.\n"

#: src/cookies.c:620
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Syntaktick� chyba v hlavi�ce Set-Cookie: P�ed�asn� konec �et�zce.\n"

# , c-format
#: src/cookies.c:1352
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Nelze otev��t soubor s kol��ky `%s': %s\n"

# , c-format
#: src/cookies.c:1364
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "P�i z�pisu do `%s' nastala chyba: %s.\n"

#: src/cookies.c:1368
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "P�i uzav�r�n� `%s' nastala chyba: %s\n"

#: src/ftp-ls.c:787
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Nepodporovan� typ v�pisu, pou�ije se Unixov� parser.\n"

# , c-format
#: src/ftp-ls.c:832 src/ftp-ls.c:834
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Obsah /%s na %s:%d"

#: src/ftp-ls.c:856
msgid "time unknown       "
msgstr "�as nezn�m�        "

#: src/ftp-ls.c:860
msgid "File        "
msgstr "Soubor      "

#: src/ftp-ls.c:863
msgid "Directory   "
msgstr "Adres��     "

#: src/ftp-ls.c:866
msgid "Link        "
msgstr "Sym. odkaz  "

#: src/ftp-ls.c:869
msgid "Not sure    "
msgstr "Nezn�m� typ "

# , c-format
#: src/ftp-ls.c:887
#, c-format
msgid " (%s bytes)"
msgstr " (%s bajt�)"

# , c-format
#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:150 src/http.c:624
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Navazuje se spojen� s %s:%hu... "

# , c-format
#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Spojen� s %s:%hu odm�tnuto.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:193 src/http.c:652
msgid "connected!\n"
msgstr "spojeno!\n"

# , c-format
#: src/ftp.c:194
#, c-format
msgid "Logging in as %s ... "
msgstr "Prob�h� p�ihla�ov�n� jako %s ... "

#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
msgid "Error in server response, closing control connection.\n"
msgstr "��dic� spojen� bude ukon�eno, proto�e server odpov�d�l chybov�m hl�en�m.\n"

#: src/ftp.c:211
msgid "Error in server greeting.\n"
msgstr "�vodn� odpov�� serveru je chybn�.\n"

#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
msgid "Write failed, closing control connection.\n"
msgstr "R�dic� spojen� bude ukon�eno, proto�e nelze zapsat data.\n"

#: src/ftp.c:226
msgid "The server refuses login.\n"
msgstr "Server odm�t� p�ihl�en�.\n"

#: src/ftp.c:233
msgid "Login incorrect.\n"
msgstr "Chyba p�i p�ihl�en�.\n"

#: src/ftp.c:240
msgid "Logged in!\n"
msgstr "P�ihl�eno!\n"

#: src/ftp.c:265
msgid "Server error, can't determine system type.\n"
msgstr "Nelze zjistit typ vzd�len�ho opera�n�ho syst�mu, proto�e server odpov�d�l chybov�m hl�en�m.\n"

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
msgstr "R�dic� spojen� bude ukon�eno, proto�e je po�adov�n nezn�m� typ p�enosu `%c'.\n"

#: src/ftp.c:366
msgid "done.  "
msgstr "hotovo."

#: src/ftp.c:372
msgid "==> CWD not needed.\n"
msgstr "==> CWD nen� pot�eba.\n"

# , c-format
#: src/ftp.c:445
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Adres�� `%s' neexistuje.\n\n"

#. do not CWD
#: src/ftp.c:463
msgid "==> CWD not required.\n"
msgstr "==> CWD nen� pot�eba.\n"

#: src/ftp.c:497
msgid "Cannot initiate PASV transfer.\n"
msgstr "Nelze spustit pasivn� p�enos dat.\n"

#: src/ftp.c:501
msgid "Cannot parse PASV response.\n"
msgstr "Odpov�� na PASV nen� pochopiteln�.\n"

# , c-format
#: src/ftp.c:515
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Program se pokus� spojit s %s:%hu.\n"

# , c-format
#: src/ftp.c:602
#, c-format
msgid "Bind error (%s).\n"
msgstr "Chyba p�i operaci \"bind\" (%s).\n"

#: src/ftp.c:618
msgid "Invalid PORT.\n"
msgstr "Neplatn� PORT.\n"

#: src/ftp.c:671
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nP��kaz REST selhal, `%s' nebude zkr�ceno.\n"

#: src/ftp.c:678
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nP��kaz REST selhal, p�enos za�ne od za��tku souboru.\n"

# , c-format
#: src/ftp.c:727
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Soubor `%s' neexistuje.\n\n"

# , c-format
#: src/ftp.c:775
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Soubor �i adres�� `%s' neexistuje.\n\n"

# , c-format
#: src/ftp.c:859 src/ftp.c:867
#, c-format
msgid "Length: %s"
msgstr "D�lka: %s"

# , c-format
#: src/ftp.c:861 src/ftp.c:869
#, c-format
msgid " [%s to go]"
msgstr " [%s zb�v�]"

#: src/ftp.c:871
msgid " (unauthoritative)\n"
msgstr " (nen� sm�rodatn�)\n"

# , c-format
#: src/ftp.c:898
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, ��dic� spojen� bude ukon�eno.\n"

# , c-format
#: src/ftp.c:906
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Datov� spojen�: %s; "

#: src/ftp.c:923
msgid "Control connection closed.\n"
msgstr "��dic� spojen� bylo ukon�eno.\n"

#: src/ftp.c:941
msgid "Data transfer aborted.\n"
msgstr "P�enos dat byl p�ed�asn� ukon�en.\n"

# , c-format
#: src/ftp.c:1005
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Soubor `%s' je ji� zde a nen� jej t�eba p�en�et.\n"

# , c-format
#: src/ftp.c:1075 src/http.c:1502
#, c-format
msgid "(try:%2d)"
msgstr "(pokus:%2d)"

# , c-format
#: src/ftp.c:1139 src/http.c:1753
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' ulo�en [%ld]\n\n"

# , c-format
#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
#, c-format
msgid "Removing %s.\n"
msgstr "Ma�e se %s.\n"

# , c-format
#: src/ftp.c:1221
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Seznam soubor� bude do�asn� ulo�en v `%s'.\n"

# , c-format
#: src/ftp.c:1233
#, c-format
msgid "Removed `%s'.\n"
msgstr "Soubor `%s' byl vymaz�n.\n"

# , c-format
#: src/ftp.c:1269
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Hloubka rekurze %d p�ekro�ila maxim�ln� hloubku %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1330
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Vzd�len� soubor nen� nov�j��, ne� lok�ln� soubor `%s', a nen� jej t�eba stahovat.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1337
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "Vzd�len� soubor je nov�j��, ne� lok�ln� soubor `%s', a je jej t�eba st�hnout.\n\n"

# , c-format
#. Sizes do not match
#: src/ftp.c:1344
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "Velikosti se neshoduj� (lok�ln� %ld), soubor je t�eba st�hnout.\n\n"

#: src/ftp.c:1361
msgid "Invalid name of the symlink, skipping.\n"
msgstr "P�eskakuje se symbolick� odkaz, nebo� n�zev odkazu nen� platn�.\n"

# , c-format
#: src/ftp.c:1378
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Korektn� symbolick� odkaz %s -> %s ji� existuje.\n\n"

# , c-format
#: src/ftp.c:1386
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Vytv��� se symbolick� odkaz %s -> %s\n"

# , c-format
#: src/ftp.c:1397
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Symbolick� odkaz `%s' bude vynech�n, proto�e syst�m symbolick� odkazy nepodporuje.\n"

# , c-format
#: src/ftp.c:1409
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Adres�� `%s' bude vynech�n.\n"

# , c-format
#: src/ftp.c:1418
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: nezn�m�/nepodporovan� typ souboru.\n"

# , c-format
#: src/ftp.c:1445
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: �asov� raz�tko souboru je poru�en�.\n"

# , c-format
#: src/ftp.c:1466
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Podadres��e se nebudou p�en�et, proto�e ji� bylo dosa�eno hloubky %d (maximum je %d).\n"

# , c-format
#: src/ftp.c:1512
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr ""
"Do adres��e `%s' se nesetupuje, proto�e tento adres�� se bu� m� vynechat nebo\n"
"nebyl zad�n k proch�zen�.\n"

# , c-format
#: src/ftp.c:1559
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Soubor `%s' se nem� stahovat.\n"
