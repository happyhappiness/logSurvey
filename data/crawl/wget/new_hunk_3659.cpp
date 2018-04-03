# Swedish messages for wget.
# Copyright (C) 1999, 2000, 2001 Free Software Foundation, Inc.
# Christian Rose <menthos@menthos.com>, 1999-2001.
#
# $Id: sv.po 476 2001-06-02 17:05:15Z hniksic $
#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.7-pre1\n"
"POT-Creation-Date: 2001-05-26 11:07+0200\n"
"PO-Revision-Date: 2001-06-01 00:55+0200\n"
"Last-Translator: Christian Rose <menthos@menthos.com>\n"
"Language-Team: Swedish <sv@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-1\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/cookies.c:588
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Fel i \"Set-Cookie\", f�lt \"%s\""

#: src/cookies.c:612
#, c-format
msgid "Syntax error in Set-Cookie at charxacter `%c'.\n"
msgstr "Syntaxfel i \"Set-Cookie\" vid tecknet \"%c\".\n"

#: src/cookies.c:620
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Syntaxfel i \"Set-Cookie\": f�r tidigt slut p� str�ng.\n"

#: src/cookies.c:1352
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Kan inte �ppna kakfilen \"%s\": %s\n"

#: src/cookies.c:1364
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Fel vid skrivning till \"%s\": %s\n"

#: src/cookies.c:1368
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Fel vid st�ngning av \"%s\": %s\n"

#: src/ftp-ls.c:787
msgid "Usupported listing type, trying Unix listing parser.\n"
msgstr "Listningstypen st�ds inte, f�rs�ker med Unix-listtolkare.\n"

#: src/ftp-ls.c:832 src/ftp-ls.c:834
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Inneh�ll i /%s p� %s:%d"

#: src/ftp-ls.c:856
msgid "time unknown       "
msgstr "ok�nd tid          "

#: src/ftp-ls.c:860
msgid "File        "
msgstr "Fil         "

#: src/ftp-ls.c:863
msgid "Directory   "
msgstr "Katalog     "

#: src/ftp-ls.c:866
msgid "Link        "
msgstr "L�nk        "

#: src/ftp-ls.c:869
msgid "Not sure    "
msgstr "Os�ker      "

#: src/ftp-ls.c:887
#, c-format
msgid " (%s bytes)"
msgstr " (%s byte) "

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:149 src/http.c:623
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Ansluter till %s:%hu... "

#: src/ftp.c:171 src/ftp.c:538 src/http.c:640
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Anslutning till %s:%hu v�gras.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:192 src/http.c:651
msgid "connected!\n"
msgstr "ansluten!\n"

#: src/ftp.c:193
#, c-format
msgid "Logging in as %s ... "
msgstr "Loggar in som %s... "

#: src/ftp.c:202 src/ftp.c:255 src/ftp.c:287 src/ftp.c:335 src/ftp.c:428
#: src/ftp.c:480 src/ftp.c:574 src/ftp.c:647 src/ftp.c:708 src/ftp.c:756
msgid "Error in server response, closing control connection.\n"
msgstr "Fel i serversvar, st�nger styrf�rbindelse.\n"

#: src/ftp.c:210
msgid "Error in server greeting.\n"
msgstr "Fel i serverh�lsning.\n"

#: src/ftp.c:218 src/ftp.c:344 src/ftp.c:437 src/ftp.c:489 src/ftp.c:584
#: src/ftp.c:657 src/ftp.c:718 src/ftp.c:766
msgid "Write failed, closing control connection.\n"
msgstr "Skrivning misslyckades, st�nger styrf�rbindelse.\n"

#: src/ftp.c:225
msgid "The server refuses login.\n"
msgstr "Inloggning nekas av servern.\n"

#: src/ftp.c:232
msgid "Login incorrect.\n"
msgstr "Felaktig inloggning.\n"

#: src/ftp.c:239
msgid "Logged in!\n"
msgstr "Inloggad!\n"

#: src/ftp.c:264
msgid "Server error, can't determine system type.\n"
msgstr "Serverfel, kan inte avg�ra systemtyp.\n"

#: src/ftp.c:274 src/ftp.c:559 src/ftp.c:631 src/ftp.c:688
msgid "done.    "
msgstr "f�rdig.  "

#: src/ftp.c:324 src/ftp.c:458 src/ftp.c:739 src/ftp.c:787 src/url.c:1429
msgid "done.\n"
msgstr "f�rdig.\n"

#: src/ftp.c:352
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Typen \"%c\" �r ok�nd, st�nger styrf�rbindelse.\n"

#: src/ftp.c:365
msgid "done.  "
msgstr "f�rdig.  "

#: src/ftp.c:371
msgid "==> CWD not needed.\n"
msgstr "==> CWD beh�vs inte.\n"

#: src/ftp.c:444
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Katalogen \"%s\" finns inte.\n\n"

#. do not CWD
#: src/ftp.c:462
msgid "==> CWD not required.\n"
msgstr "==> CWD kr�vs inte.\n"

#: src/ftp.c:496
msgid "Cannot initiate PASV transfer.\n"
msgstr "Kan inte initiera PASV-�verf�ring.\n"

#: src/ftp.c:500
msgid "Cannot parse PASV response.\n"
msgstr "Kan inte tolka PASV-svar.\n"

#: src/ftp.c:514
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "F�rs�ker ansluta till %s:%hu.\n"

#: src/ftp.c:601
#, c-format
msgid "Bind error (%s).\n"
msgstr "Bindningsfel (%s).\n"

#: src/ftp.c:617
msgid "Invalid PORT.\n"
msgstr "Felaktig PORT.\n"

#: src/ftp.c:670
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST misslyckades, kommer inte att klippa \"%s\".\n"

#: src/ftp.c:677
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST misslyckades, startar om fr�n b�rjan.\n"

#: src/ftp.c:726
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Filen \"%s\" finns inte.\n\n"

#: src/ftp.c:774
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Filen eller katalogen \"%s\" finns inte.\n\n"

#: src/ftp.c:858 src/ftp.c:866
#, c-format
msgid "Length: %s"
msgstr "L�ngd: %s"

#: src/ftp.c:860 src/ftp.c:868
#, c-format
msgid " [%s to go]"
msgstr " [%s kvar]"

#: src/ftp.c:870
msgid " (unauthoritative)\n"
msgstr " (ej auktoritativt)\n"

#: src/ftp.c:897
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, st�nger styrf�rbindelse.\n"

#: src/ftp.c:905
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Dataf�rbindelse: %s; "

#: src/ftp.c:922
msgid "Control connection closed.\n"
msgstr "Styrf�rbindelse st�ngd.\n"

#: src/ftp.c:940
msgid "Data transfer aborted.\n"
msgstr "Data�verf�ring avbruten.\n"

#: src/ftp.c:1004
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Filen \"%s\" finns redan, h�mtar inte.\n"

#: src/ftp.c:1074 src/http.c:1501
#, c-format
msgid "(try:%2d)"
msgstr "(f�rs�k:%2d)"

#: src/ftp.c:1138 src/http.c:1752
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - \"%s\" sparad [%ld]\n\n"

#: src/ftp.c:1180 src/main.c:809 src/recur.c:483 src/retr.c:566
#, c-format
msgid "Removing %s.\n"
msgstr "Tar bort %s.\n"

#: src/ftp.c:1220
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Anv�nder \"%s\" som tempor�r listningsfil.\n"

#: src/ftp.c:1232
#, c-format
msgid "Removed `%s'.\n"
msgstr "Tog bort \"%s\".\n"

#: src/ftp.c:1268
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Rekursionsdjupet %d �verskred det maximala djupet %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1329
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Filen p� servern �r inte nyare �n lokala filen \"%s\" -- h�mtar inte.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1336
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "Filen p� servern �r nyare �n lokala filen \"%s\" -- h�mtar.\n\n"

#. Sizes do not match
#: src/ftp.c:1343
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "Storlekarna st�mmer inte �verens (lokal %ld) -- h�mtar.\n\n"

#: src/ftp.c:1360
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Ogiltig symbolisk l�nk, hoppar �ver.\n"

#: src/ftp.c:1377
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "En korrekt symbolisk l�nk %s -> %s finns redan.\n\n"

#: src/ftp.c:1385
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Skapar symbolisk l�nk %s -> %s\n"

#: src/ftp.c:1396
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Symboliska l�nkar st�ds inte, hoppar �ver symboliska l�nken \"%s\".\n"

#: src/ftp.c:1408
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Hoppar �ver katalogen \"%s\".\n"

#: src/ftp.c:1417
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: ok�nd filtyp/filtypen st�ds inte.\n"

#: src/ftp.c:1444
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: felaktig tidsst�mpel.\n"

#: src/ftp.c:1465
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "H�mtar inte kataloger eftersom djupet �r %d (max %d).\n"

#: src/ftp.c:1511
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "G�r inte ner till \"%s\" eftersom det �r undantaget/inte ing�r.\n"

#: src/ftp.c:1558
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "F�rkastar \"%s\".\n"
