# Czech translations for GNU wget
# Copyright (C) 1998, 2000, 2001 Free Software Foundation, Inc.
# Jan Prikryl <prikryl@acm.org>, 1998, 2000, 2001
#
msgid ""
msgstr ""
"Project-Id-Version: GNU wget 1.7\n"
"Report-Msgid-Bugs-To: \n"
"POT-Creation-Date: 2007-08-26 16:14-0700\n"
"PO-Revision-Date: 2001-06-05 23:19+0200\n"
"Last-Translator: Jan Prikryl <prikryl@acm.org>\n"
"Language-Team: Czech <cs@li.org>\n"
"MIME-Version: 1.0\n"
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

# , c-format
#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1753
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Vzorku `%s' nic neodpov�d�.\n"

# , c-format
#: src/ftp.c:1819
#, fuzzy, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "V�pis adres��e v HTML form�tu byl zaps�n do `%s' [%ld].\n"

# , c-format
#: src/ftp.c:1824
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "V�pis adres��e v HTML form�tu byl zaps�n do `%s'.\n"

# , c-format
#: src/getopt.c:670
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: p�ep�na� `%s' nen� jednozna�n�\n"

# , c-format
#: src/getopt.c:695
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: p�ep�na� `--%s' nem� argument\n"

# , c-format
#: src/getopt.c:700
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: p�ep�na� `%c%s' nem� argument\n"

# , c-format
#: src/getopt.c:718 src/getopt.c:891
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: p�ep�na� `%s' vy�aduje argument\n"

# , c-format
#. --option
#: src/getopt.c:747
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: nezn�m� p�ep�na� `--%s'\n"

# , c-format
#. +option or -option
#: src/getopt.c:751
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: nezn�m� p�ep�na� `%c%s'\n"

# , c-format
#. 1003.2 specifies the format of this message.
#: src/getopt.c:777
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: nep��pustn� p�ep�na� -- %c\n"

# , c-format
#: src/getopt.c:780
#, fuzzy, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: nep��pustn� p�ep�na� -- %c\n"

# , c-format
#. 1003.2 specifies the format of this message.
#: src/getopt.c:810 src/getopt.c:940
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: p�ep�na� vy�aduje argument -- %c\n"

# , c-format
#: src/getopt.c:857
#, fuzzy, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: p�ep�na� `%s' nen� jednozna�n�\n"

# , c-format
#: src/getopt.c:875
#, fuzzy, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: p�ep�na� `--%s' nem� argument\n"

#: src/host.c:347
#, fuzzy
msgid "Unknown host"
msgstr "Nezn�m� chyba"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:353
msgid "Unknown error"
msgstr "Nezn�m� chyba"

# , c-format
#: src/host.c:714
#, fuzzy, c-format
msgid "Resolving %s... "
msgstr "Ma�e se %s.\n"

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:784
msgid "failed: timed out.\n"
msgstr ""

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr ""

# , c-format
#: src/html-url.c:695
#, fuzzy, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: Neplatn� specifikace `%s'\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Nebylo mo�n� odeslat HTTP po�adavek: %s.\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr ""

# , c-format
#: src/http.c:1615
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Program vyu�ije existuj�c� spojen� s %s:%hu.\n"

#: src/http.c:1684
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Nebylo mo�n� odeslat HTTP po�adavek: %s.\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

# , c-format
#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s po�adavek odesl�n, program �ek� na odpov�� ... "

#: src/http.c:1760
#, fuzzy
msgid "No data received.\n"
msgstr "Nep�i�la ��dn� data"

# , c-format
#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Chyba (%s) p�i �ten� hlavi�ek.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, fuzzy, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr "Soubor `%s' je ji� zde a nen� jej t�eba p�en�et.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "Server po�aduje nezn�m� zp�sob autentifikace.\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "Autorizace selhala.\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "Odpov�� serveru m� zkomolen� stavov� ��dek"

#: src/http.c:2013
msgid "(no description)"
msgstr "(��dn� popis)"

# , c-format
#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "P�esm�rov�no na: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "neud�no"

#: src/http.c:2078
msgid " [following]"
msgstr " [n�sleduji]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"    Soubor je ji� pln� p�enesen, nebude se nic d�lat.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:2164
msgid "Length: "
msgstr "D�lka: "

#: src/http.c:2184
msgid "ignored"
msgstr "je ignorov�na"

# , c-format
#: src/http.c:2255
#, fuzzy, c-format
msgid "Saving to: `%s'\n"
msgstr "Adres�� `%s' bude vynech�n.\n"

#: src/http.c:2335
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varov�n�: HTTP nepodporuje �ol�kov� znaky.\n"

#: src/http.c:2364
msgid "Spider mode enabled. Check if remote file exists.\n"
msgstr ""

# , c-format
#: src/http.c:2450
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nelze zapsat do `%s' (%s).\n"

#. Another fatal error.
#: src/http.c:2459
msgid "Unable to establish SSL connection.\n"
msgstr "Nebylo mo�n� nav�zat SSL spojen�.\n"

# , c-format
#: src/http.c:2467
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "CHYBA: P�esm�rov�n� (%d) bez udan� nov� adresy.\n"

#: src/http.c:2505
msgid "Remote file does not exist -- broken link!!!\n"
msgstr ""

# , c-format
#: src/http.c:2510
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s CHYBA %d: %s.\n"

#: src/http.c:2526
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Nelze pou��t �asov� raz�tka (`time-stamps'), proto�e v odpov�di serveru \n"
"sch�z� hlavi�ka \"Last-modified\".\n"

#: src/http.c:2534
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"�asov� raz�tko souboru (`time-stamp') bude ignorov�no, proto�e hlavi�ka \n"
"\"Last-modified\" obsahuje neplatn� �daje.\n"

#: src/http.c:2558
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"Lok�ln� soubor `%s' nen� star��, ne� vzd�len� soubor, a nen� jej t�eba "
"stahovat.\n"
"\n"

# , c-format
#: src/http.c:2566
#, fuzzy, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr "Velikosti se neshoduj� (lok�ln� %ld), soubor je t�eba st�hnout.\n"

#: src/http.c:2573
msgid "Remote file is newer, retrieving.\n"
msgstr "Lok�ln� soubor je star�� a vzd�len� soubor se proto bude p�en�et.\n"

#: src/http.c:2596
#, fuzzy
msgid ""
"Remote file exists and could contain links to other resources -- "
"retrieving.\n"
"\n"
msgstr ""
"Vzd�len� soubor je nov�j��, ne� lok�ln� soubor `%s', a je jej t�eba "
"st�hnout.\n"
"\n"

#: src/http.c:2602
#, fuzzy
msgid ""
"Remote file exists but does not contain any link -- not retrieving.\n"
"\n"
msgstr ""
"Vzd�len� soubor nen� nov�j��, ne� lok�ln� soubor `%s', a nen� jej t�eba "
"stahovat.\n"

#: src/http.c:2610
#, fuzzy
msgid ""
"Remote file exists but recursion is disabled -- not retrieving.\n"
"\n"
msgstr ""
"Vzd�len� soubor nen� nov�j��, ne� lok�ln� soubor `%s', a nen� jej t�eba "
"stahovat.\n"

# , c-format
#: src/http.c:2652
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s]\n"
"\n"
msgstr ""
"%s (%s) - `%s' ulo�eno [%ld/%ld]\n"
"\n"

# , c-format
#: src/http.c:2707
#, fuzzy, c-format
msgid "%s (%s) - Connection closed at byte %s. "
msgstr "%s (%s) - Spojen� ukon�eno na bajtu %ld. "

# , c-format
#: src/http.c:2722
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s (%s)."
msgstr "%s (%s) - Chyba p�i �ten� dat na bajtu %ld (%s)."

# , c-format
#: src/http.c:2731
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s/%s (%s). "
msgstr "%s (%s) - Chyba p�i �ten� dat na bajtu %ld/%ld (%s). "

#: src/init.c:370
#, c-format
msgid "%s: WGETRC points to %s, which doesn't exist.\n"
msgstr ""

# , c-format
#: src/init.c:433 src/netrc.c:267
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Nelze p�e��st %s (%s).\n"

# , c-format
#: src/init.c:451
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Chyba v %s na ��dku %d.\n"

# , c-format
#: src/init.c:457
#, fuzzy, c-format
msgid "%s: Syntax error in %s at line %d.\n"
msgstr "%s: Chyba v %s na ��dku %d.\n"

# , c-format
#: src/init.c:462
#, fuzzy, c-format
msgid "%s: Unknown command `%s' in %s at line %d.\n"
msgstr "%s: CHYBA: Nezn�m� p��kaz `%s', hodnota `%s'.\n"

# , c-format
#: src/init.c:507
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: Varov�n�: Glob�ln� i u�ivatelsk� wgetrc jsou shodn� ulo�eny v `%s'.\n"

# , c-format
#: src/init.c:660
#, fuzzy, c-format
msgid "%s: Invalid --execute command `%s'\n"
msgstr "%s: Neplatn� specifikace `%s'\n"

# , c-format
#: src/init.c:705
#, fuzzy, c-format
msgid "%s: %s: Invalid boolean `%s'; use `on' or `off'.\n"
msgstr "%s: %s: Zadejte pros�m `on' (zapnuto) nebo `off' (vypnuto).\n"

# , c-format
#: src/init.c:722
#, fuzzy, c-format
msgid "%s: %s: Invalid number `%s'.\n"
msgstr "%s: %s: Neplatn� specifikace `%s'\n"

# , c-format
#: src/init.c:953 src/init.c:972
#, fuzzy, c-format
msgid "%s: %s: Invalid byte value `%s'\n"
msgstr "%s: %s: Neplatn� specifikace `%s'\n"

# , c-format
#: src/init.c:997
#, fuzzy, c-format
msgid "%s: %s: Invalid time period `%s'\n"
msgstr "%s: %s: Neplatn� specifikace `%s'\n"

# , c-format
#: src/init.c:1051 src/init.c:1141 src/init.c:1244 src/init.c:1269
#, fuzzy, c-format
msgid "%s: %s: Invalid value `%s'.\n"
msgstr "%s: %s: Neplatn� specifikace `%s'\n"

# , c-format
#: src/init.c:1088
#, fuzzy, c-format
msgid "%s: %s: Invalid header `%s'.\n"
msgstr "%s: %s: Neplatn� specifikace `%s'\n"

# , c-format
#: src/init.c:1154
#, fuzzy, c-format
msgid "%s: %s: Invalid progress type `%s'.\n"
msgstr "%s: %s: Neplatn� specifikace `%s'\n"

#: src/init.c:1213
#, c-format
msgid ""
"%s: %s: Invalid restriction `%s', use [unix|windows],[lowercase|uppercase],"
"[nocontrol].\n"
msgstr ""

#: src/log.c:783
#, fuzzy, c-format
msgid ""
"\n"
"%s received, redirecting output to `%s'.\n"
msgstr "Byl zachycen sign�l %s, v�stup p�esm�rov�n do `%%s'.\n"

#. Eek!  Opening the alternate log file has failed.  Nothing we
#. can do but disable printing completely.
#: src/log.c:793
#, fuzzy, c-format
msgid ""
"\n"
"%s received.\n"
msgstr "Nep�i�la ��dn� data"

#: src/log.c:794
#, c-format
msgid "%s: %s; disabling logging.\n"
msgstr ""

# , c-format
#: src/main.c:353
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Pou�it�: %s [P�EP�NA�]... [URL]...\n"

#: src/main.c:365
#, fuzzy
msgid ""
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Argumenty, povinn� u dlouh�ch p�ep�na��, jsou povinn� i pro kr�tk� verze\n"
"p�ep�na��.\n"
"\n"

#: src/main.c:367
msgid "Startup:\n"
msgstr ""

#: src/main.c:369
msgid "  -V,  --version           display the version of Wget and exit.\n"
msgstr ""

#: src/main.c:371
msgid "  -h,  --help              print this help.\n"
msgstr ""

#: src/main.c:373
msgid "  -b,  --background        go to background after startup.\n"
msgstr ""

#: src/main.c:375
msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
msgstr ""

#: src/main.c:379
msgid "Logging and input file:\n"
msgstr ""

#: src/main.c:381
msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
msgstr ""

#: src/main.c:383
msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
msgstr ""

#: src/main.c:386
msgid "  -d,  --debug               print lots of debugging information.\n"
msgstr ""

#: src/main.c:389
msgid "  -q,  --quiet               quiet (no output).\n"
msgstr ""

#: src/main.c:391
msgid "  -v,  --verbose             be verbose (this is the default).\n"
msgstr ""

#: src/main.c:393
msgid ""
"  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
msgstr ""

#: src/main.c:395
msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
msgstr ""

#: src/main.c:397
msgid "  -F,  --force-html          treat input file as HTML.\n"
msgstr ""

#: src/main.c:399
msgid ""
"  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
msgstr ""

#: src/main.c:403
msgid "Download:\n"
msgstr ""

#: src/main.c:405
msgid ""
"  -t,  --tries=NUMBER            set number of retries to NUMBER (0 "
"unlimits).\n"
msgstr ""

#: src/main.c:407
msgid "       --retry-connrefused       retry even if connection is refused.\n"
msgstr ""

#: src/main.c:409
msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
msgstr ""

#: src/main.c:411
msgid ""
"  -nc, --no-clobber              skip downloads that would download to\n"
"                                 existing files.\n"
msgstr ""

#: src/main.c:414
msgid ""
"  -c,  --continue                resume getting a partially-downloaded "
"file.\n"
msgstr ""

#: src/main.c:416
msgid "       --progress=TYPE           select progress gauge type.\n"
msgstr ""

#: src/main.c:418
msgid ""
"  -N,  --timestamping            don't re-retrieve files unless newer than\n"
"                                 local.\n"
msgstr ""

#: src/main.c:421
msgid "  -S,  --server-response         print server response.\n"
msgstr ""

#: src/main.c:423
msgid "       --spider                  don't download anything.\n"
msgstr ""

#: src/main.c:425
msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
msgstr ""

#: src/main.c:427
msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
msgstr ""

#: src/main.c:429
msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
msgstr ""

#: src/main.c:431
msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
msgstr ""

#: src/main.c:433
msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
msgstr ""

#: src/main.c:435
msgid ""
"       --waitretry=SECONDS       wait 1..SECONDS between retries of a "
"retrieval.\n"
msgstr ""

#: src/main.c:437
msgid ""
"       --random-wait             wait from 0...2*WAIT secs between "
"retrievals.\n"
msgstr ""

#: src/main.c:439
msgid "  -Y,  --proxy                   explicitly turn on proxy.\n"
msgstr ""

#: src/main.c:441
msgid "       --no-proxy                explicitly turn off proxy.\n"
msgstr ""

#: src/main.c:443
msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
msgstr ""

#: src/main.c:445
msgid ""
"       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local "
"host.\n"
msgstr ""

#: src/main.c:447
msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
msgstr ""

#: src/main.c:449
msgid "       --no-dns-cache            disable caching DNS lookups.\n"
msgstr ""

#: src/main.c:451
msgid ""
"       --restrict-file-names=OS  restrict chars in file names to ones OS "
"allows.\n"
msgstr ""

#: src/main.c:453
msgid ""
"       --ignore-case             ignore case when matching files/"
"directories.\n"
msgstr ""

#: src/main.c:456
msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
msgstr ""

#: src/main.c:458
msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
msgstr ""

#: src/main.c:460
msgid ""
"       --prefer-family=FAMILY    connect first to addresses of specified "
"family,\n"
"                                 one of IPv6, IPv4, or none.\n"
msgstr ""

#: src/main.c:464
msgid "       --user=USER               set both ftp and http user to USER.\n"
msgstr ""

#: src/main.c:466
msgid ""
"       --password=PASS           set both ftp and http password to PASS.\n"
msgstr ""

#: src/main.c:470
#, fuzzy
msgid "Directories:\n"
msgstr "Adres��     "

#: src/main.c:472
msgid "  -nd, --no-directories           don't create directories.\n"
msgstr ""

#: src/main.c:474
msgid "  -x,  --force-directories        force creation of directories.\n"
msgstr ""

#: src/main.c:476
msgid "  -nH, --no-host-directories      don't create host directories.\n"
msgstr ""

#: src/main.c:478
msgid "       --protocol-directories     use protocol name in directories.\n"
msgstr ""

#: src/main.c:480
msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
msgstr ""

#: src/main.c:482
msgid ""
"       --cut-dirs=NUMBER          ignore NUMBER remote directory "
"components.\n"
msgstr ""

#: src/main.c:486
msgid "HTTP options:\n"
msgstr ""

#: src/main.c:488
msgid "       --http-user=USER        set http user to USER.\n"
msgstr ""

#: src/main.c:490
msgid "       --http-password=PASS    set http password to PASS.\n"
msgstr ""

#: src/main.c:492
msgid "       --no-cache              disallow server-cached data.\n"
msgstr ""

#: src/main.c:494
msgid ""
"  -E,  --html-extension        save HTML documents with `.html' extension.\n"
msgstr ""

#: src/main.c:496
msgid "       --ignore-length         ignore `Content-Length' header field.\n"
msgstr ""

#: src/main.c:498
msgid "       --header=STRING         insert STRING among the headers.\n"
msgstr ""

#: src/main.c:500
msgid "       --max-redirect          maximum redirections allowed per page.\n"
msgstr ""

#: src/main.c:502
msgid "       --proxy-user=USER       set USER as proxy username.\n"
msgstr ""

#: src/main.c:504
msgid "       --proxy-password=PASS   set PASS as proxy password.\n"
msgstr ""

#: src/main.c:506
msgid ""
"       --referer=URL           include `Referer: URL' header in HTTP "
"request.\n"
msgstr ""

#: src/main.c:508
msgid "       --save-headers          save the HTTP headers to file.\n"
msgstr ""

#: src/main.c:510
msgid ""
"  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
msgstr ""

#: src/main.c:512
msgid ""
"       --no-http-keep-alive    disable HTTP keep-alive (persistent "
"connections).\n"
msgstr ""

#: src/main.c:514
msgid "       --no-cookies            don't use cookies.\n"
msgstr ""

#: src/main.c:516
msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
msgstr ""

#: src/main.c:518
msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
msgstr ""

#: src/main.c:520
msgid ""
"       --keep-session-cookies  load and save session (non-permanent) "
"cookies.\n"
msgstr ""

#: src/main.c:522
msgid ""
"       --post-data=STRING      use the POST method; send STRING as the "
"data.\n"
msgstr ""

#: src/main.c:524
msgid ""
"       --post-file=FILE        use the POST method; send contents of FILE.\n"
msgstr ""

#: src/main.c:526
msgid ""
"       --no-content-disposition  don't honor Content-Disposition header.\n"
msgstr ""

#: src/main.c:531
msgid "HTTPS (SSL/TLS) options:\n"
msgstr ""

#: src/main.c:533
msgid ""
"       --secure-protocol=PR     choose secure protocol, one of auto, SSLv2,\n"
"                                SSLv3, and TLSv1.\n"
msgstr ""

#: src/main.c:536
msgid ""
"       --no-check-certificate   don't validate the server's certificate.\n"
msgstr ""

#: src/main.c:538
msgid "       --certificate=FILE       client certificate file.\n"
msgstr ""

#: src/main.c:540
msgid "       --certificate-type=TYPE  client certificate type, PEM or DER.\n"
msgstr ""

#: src/main.c:542
msgid "       --private-key=FILE       private key file.\n"
msgstr ""

#: src/main.c:544
msgid "       --private-key-type=TYPE  private key type, PEM or DER.\n"
msgstr ""

#: src/main.c:546
msgid "       --ca-certificate=FILE    file with the bundle of CA's.\n"
msgstr ""

#: src/main.c:548
msgid ""
"       --ca-directory=DIR       directory where hash list of CA's is "
"stored.\n"
msgstr ""

#: src/main.c:550
msgid ""
"       --random-file=FILE       file with random data for seeding the SSL "
"PRNG.\n"
msgstr ""

#: src/main.c:552
msgid ""
"       --egd-file=FILE          file naming the EGD socket with random "
"data.\n"
msgstr ""

#: src/main.c:557
msgid "FTP options:\n"
msgstr ""

#: src/main.c:559
msgid "       --ftp-user=USER         set ftp user to USER.\n"
msgstr ""

#: src/main.c:561
msgid "       --ftp-password=PASS     set ftp password to PASS.\n"
msgstr ""

#: src/main.c:563
msgid "       --no-remove-listing     don't remove `.listing' files.\n"
msgstr ""

#: src/main.c:565
msgid "       --no-glob               turn off FTP file name globbing.\n"
msgstr ""

#: src/main.c:567
msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
msgstr ""

#: src/main.c:569
msgid ""
"       --retr-symlinks         when recursing, get linked-to files (not "
"dir).\n"
msgstr ""

#: src/main.c:571
msgid "       --preserve-permissions  preserve remote file permissions.\n"
msgstr ""

#: src/main.c:575
msgid "Recursive download:\n"
msgstr ""

#: src/main.c:577
msgid "  -r,  --recursive          specify recursive download.\n"
msgstr ""

#: src/main.c:579
msgid ""
"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
"infinite).\n"
msgstr ""

#: src/main.c:581
msgid ""
"       --delete-after       delete files locally after downloading them.\n"
msgstr ""

#: src/main.c:583
msgid ""
"  -k,  --convert-links      make links in downloaded HTML point to local "
"files.\n"
msgstr ""

#: src/main.c:585
msgid ""
"  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
msgstr ""

#: src/main.c:587
msgid ""
"  -m,  --mirror             shortcut for -N -r -l inf --no-remove-listing.\n"
msgstr ""

#: src/main.c:589
msgid ""
"  -p,  --page-requisites    get all images, etc. needed to display HTML "
"page.\n"
msgstr ""

#: src/main.c:591
msgid ""
"       --strict-comments    turn on strict (SGML) handling of HTML "
"comments.\n"
msgstr ""

#: src/main.c:595
msgid "Recursive accept/reject:\n"
msgstr ""

#: src/main.c:597
msgid ""
"  -A,  --accept=LIST               comma-separated list of accepted "
"extensions.\n"
msgstr ""

#: src/main.c:599
msgid ""
"  -R,  --reject=LIST               comma-separated list of rejected "
"extensions.\n"
msgstr ""

#: src/main.c:601
msgid ""
"  -D,  --domains=LIST              comma-separated list of accepted "
"domains.\n"
msgstr ""

#: src/main.c:603
msgid ""
"       --exclude-domains=LIST      comma-separated list of rejected "
"domains.\n"
msgstr ""

#: src/main.c:605
msgid ""
"       --follow-ftp                follow FTP links from HTML documents.\n"
msgstr ""

#: src/main.c:607
msgid ""
"       --follow-tags=LIST          comma-separated list of followed HTML "
"tags.\n"
msgstr ""

#: src/main.c:609
msgid ""
"       --ignore-tags=LIST          comma-separated list of ignored HTML "
"tags.\n"
msgstr ""

#: src/main.c:611
msgid ""
"  -H,  --span-hosts                go to foreign hosts when recursive.\n"
msgstr ""

#: src/main.c:613
msgid "  -L,  --relative                  follow relative links only.\n"
msgstr ""

#: src/main.c:615
msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
msgstr ""

#: src/main.c:617
msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
msgstr ""

#: src/main.c:619
msgid ""
"  -np, --no-parent                 don't ascend to the parent directory.\n"
msgstr ""

# , fuzzy
#: src/main.c:623
msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
msgstr ""
"Zpr�vy o chyb�ch a n�vrhy na vylep�en� programu zas�lejte na adresu\n"
"<bug-wget@gnu.org> (pouze anglicky).\n"
"Koment��e k �esk�mu p�ekladu zas�lejte na adresu <cs@li.org>. \n"

# , c-format
#: src/main.c:628
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, program pro neinteraktivn� stahov�n� soubor�.\n"

#: src/main.c:668
msgid "Copyright (C) 2007 Free Software Foundation, Inc.\n"
msgstr ""

#: src/main.c:670
msgid ""
"License GPLv3+: GNU GPL version 3 or later\n"
"<http://www.gnu.org/licenses/gpl.html>.\n"
"This is free software: you are free to change and redistribute it.\n"
"There is NO WARRANTY, to the extent permitted by law.\n"
msgstr ""

#: src/main.c:675
#, fuzzy
msgid ""
"\n"
"Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
msgstr ""
"\n"
"P�vodn�m autorem tohto programu je Hrvoje Nik�i� <hniksic@arsdigita.com>.\n"

#: src/main.c:677
msgid "Currently maintained by Micah Cowan <micah@cowan.name>.\n"
msgstr ""

# , c-format
#. #### Something nicer should be printed here -- similar to the
#. pre-1.5 `--help' page.
#: src/main.c:724 src/main.c:793 src/main.c:890
#, c-format
msgid "Try `%s --help' for more options.\n"
msgstr "P��kaz `%s --help' vyp�e v�znam platn�ch p�ep�na��.\n"

# , c-format
#: src/main.c:790
#, c-format
msgid "%s: illegal option -- `-n%c'\n"
msgstr "%s: nep��pustn� p�ep�na� -- `-n%c'\n"

#: src/main.c:845
#, c-format
msgid "Can't be verbose and quiet at the same time.\n"
msgstr "Program nem��e b�t upov�dan� a zitcha najednou.\n"

#: src/main.c:851
#, c-format
msgid "Can't timestamp and not clobber old files at the same time.\n"
msgstr "Nelze pou��vat �asov� raz�tka a nemazat p�itom star� soubory.\n"

#: src/main.c:859
#, c-format
msgid "Cannot specify both --inet4-only and --inet6-only.\n"
msgstr ""

#: src/main.c:869
#, c-format
msgid "Cannot specify -r, -p or -N if -O is given.\n"
msgstr ""

#: src/main.c:877
#, c-format
msgid "Cannot specify both -k and -O if multiple URLs are given.\n"
msgstr ""

#. No URL specified.
#: src/main.c:885
#, c-format
msgid "%s: missing URL\n"
msgstr "%s: chyb� URL\n"

# , c-format
#: src/main.c:1005
#, c-format
msgid "No URLs found in %s.\n"
msgstr "V souboru `%s' nebyla nalezena ��dn� URL.\n"

# , c-format
#: src/main.c:1023
#, fuzzy, c-format
msgid ""
"FINISHED --%s--\n"
"Downloaded: %d files, %s in %s (%s)\n"
msgstr ""
"\n"
"KONEC --%s--\n"
"Celkem na�teno %s bajt� v %d souborech\n"

# , c-format
#: src/main.c:1032
#, fuzzy, c-format
msgid "Download quota of %s EXCEEDED!\n"
msgstr "P�ekro�en limit objemu ulo�en�ch dat (%s bajt�)!\n"

#: src/mswindows.c:96
#, c-format
msgid "Continuing in background.\n"
msgstr "Program pokra�uje v b�hu na pozad�.\n"

#: src/mswindows.c:289
#, fuzzy, c-format
msgid "Continuing in background, pid %lu.\n"
msgstr "Program pokra�uje v b�hu na pozad�.\n"

# , c-format
#: src/mswindows.c:291 src/utils.c:326
#, c-format
msgid "Output will be written to `%s'.\n"
msgstr "V�stup bude zaps�n do `%s'.\n"

#: src/mswindows.c:459 src/mswindows.c:466
#, c-format
msgid "%s: Couldn't find usable socket driver.\n"
msgstr "%s: Nelze naj�t pou�iteln� ovlada� socket�.\n"

# , c-format
#: src/netrc.c:375
#, c-format
msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
msgstr ""
"%s: %s:%d varov�n�: token \"%s\" je uveden je�t� p�ed jak�mkoliv\n"
"      n�zvem po��ta�e\n"

# , c-format
#: src/netrc.c:406
#, c-format
msgid "%s: %s:%d: unknown token \"%s\"\n"
msgstr "%s: %s:%d: nezn�m� token \"%s\"\n"

# , c-format
#: src/netrc.c:470
#, c-format
msgid "Usage: %s NETRC [HOSTNAME]\n"
msgstr "Pou�it�: %s NETRC [N�ZEV PO��TA�E]\n"

# , c-format
#: src/netrc.c:480
#, c-format
msgid "%s: cannot stat %s: %s\n"
msgstr "%s: vol�n� `stat %s' skon�ilo chybou: %s\n"

#. Still not random enough, presumably because neither /dev/random
#. nor EGD were available.  Try to seed OpenSSL's PRNG with libc
#. PRNG.  This is cryptographically weak and defeats the purpose
#. of using OpenSSL, which is why it is highly discouraged.
#: src/openssl.c:112
msgid "WARNING: using a weak random seed.\n"
msgstr ""

#: src/openssl.c:172
msgid "Could not seed PRNG; consider using --random-file.\n"
msgstr ""

#. If the user has specified --no-check-cert, we still want to warn
#. him about problems with the server's certificate.
#: src/openssl.c:487
msgid "ERROR"
msgstr ""

#: src/openssl.c:487
msgid "WARNING"
msgstr ""

#: src/openssl.c:496
#, c-format
msgid "%s: No certificate presented by %s.\n"
msgstr ""

#: src/openssl.c:517
#, c-format
msgid "%s: cannot verify %s's certificate, issued by `%s':\n"
msgstr ""

#: src/openssl.c:525
msgid "  Unable to locally verify the issuer's authority.\n"
msgstr ""

#: src/openssl.c:529
msgid "  Self-signed certificate encountered.\n"
msgstr ""

#: src/openssl.c:532
msgid "  Issued certificate not yet valid.\n"
msgstr ""

#: src/openssl.c:535
msgid "  Issued certificate has expired.\n"
msgstr ""

#: src/openssl.c:567
#, c-format
msgid ""
"%s: certificate common name `%s' doesn't match requested host name `%s'.\n"
msgstr ""

#: src/openssl.c:580
#, c-format
msgid "To connect to %s insecurely, use `--no-check-certificate'.\n"
msgstr ""

# , c-format
#. Align the [ skipping ... ] line with the dots.  To do
#. that, insert the number of spaces equal to the number of
#. digits in the skipped amount in K.
#: src/progress.c:238
#, fuzzy, c-format
msgid ""
"\n"
"%*s[ skipping %sK ]"
msgstr ""
"\n"
"          [ p�eskakuje se %dK ]"

# , c-format
#: src/progress.c:452
#, fuzzy, c-format
msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
msgstr "%s: Neplatn� specifikace `%s'\n"

#. Translation note: "ETA" is English-centric, but this must
#. be short, ideally 3 chars.  Abbreviate if necessary.
#: src/progress.c:946
#, c-format
msgid "  eta %s"
msgstr ""

#. When the download is done, print the elapsed time.
#. Note to translators: this should not take up more room than
#. available here.  Abbreviate if necessary.
#: src/progress.c:961
msgid "   in "
msgstr ""

#. If no clock was found, it means that clock_getres failed for
#. the realtime clock.
#: src/ptimer.c:160
#, c-format
msgid "Cannot get REALTIME clock frequency: %s\n"
msgstr ""

# , c-format
#: src/recur.c:377
#, c-format
msgid "Removing %s since it should be rejected.\n"
msgstr "Ma�e se %s, proto�e tento soubor nen� po�adov�n.\n"

# , c-format
#: src/res.c:392
#, fuzzy, c-format
msgid "Cannot open %s: %s"
msgstr "Nelze p�ev�st odkazy v %s: %s\n"

#: src/res.c:544
msgid "Loading robots.txt; please ignore errors.\n"
msgstr "Na��t� se `robots.txt'. Chybov� hl�en� ignorujte, pros�m.\n"

# , c-format
#: src/retr.c:651
#, fuzzy, c-format
msgid "Error parsing proxy URL %s: %s.\n"
msgstr "P�i z�pisu do `%s' nastala chyba: %s.\n"

# , c-format
#: src/retr.c:659
#, fuzzy, c-format
msgid "Error in proxy URL %s: Must be HTTP.\n"
msgstr "Proxy %s: Mus� b�t HTTP.\n"

# , c-format
#: src/retr.c:745
#, fuzzy, c-format
msgid "%d redirections exceeded.\n"
msgstr "%s: Detekov�no zacyklen� p�esm�rov�n�.\n"

#: src/retr.c:880
msgid ""
"Giving up.\n"
"\n"
msgstr ""
"Ani posledn� pokus nebyl �sp�n�.\n"
"\n"

#: src/retr.c:880
