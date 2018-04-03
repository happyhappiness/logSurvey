# Hungarian translation of GNU wget
# Copyright (C) 2001 Free Software Foundation, Inc.
# Pal Szasz <szpal@Maria.UTCluj.Ro>, 2001.
#
msgid ""
msgstr ""
"Project-Id-Version: GNU wget 1.7\n"
"POT-Creation-Date: 2001-06-03 15:27+0200\n"
"PO-Revision-Date: 2001-10-28 10:56+0200\n"
"Last-Translator: Pal Szasz <szpal@Maria.UTCluj.Ro>\n"
"Language-Team: Hungarian <hu@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-2\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/cookies.c:588
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Hiba a Set-Cookie-ban, mez� `%s'"

#: src/cookies.c:612
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Szintaktikai hiba a Set-Cookie-ban a `%c' karaktern�l.\n"

#: src/cookies.c:620
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Szintaktikai hiba a Set-Cookie-ban: korai v�ge a sz�vegnek.\n"

#: src/cookies.c:1352
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Nem tudom megnyitni a `%s' cookie �llom�nyt: %s\n"

#: src/cookies.c:1364
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Nem tudok �rni `%s'-ba (%s).\n"

#: src/cookies.c:1368
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Hiba `%s' bez�r�s�n�l: %s\n"

#: src/ftp-ls.c:787
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Nemkezelt lista tipus, pr�b�lom Unix lista �rtelmez�vel.\n"

#: src/ftp-ls.c:832 src/ftp-ls.c:834
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "/%s tartalma %s:%d-n"

#: src/ftp-ls.c:856
msgid "time unknown       "
msgstr "id� ismeretlen     "

#: src/ftp-ls.c:860
msgid "File        "
msgstr "�llom�ny    "

#: src/ftp-ls.c:863
msgid "Directory   "
msgstr "K�nyvt�r    "

#: src/ftp-ls.c:866
msgid "Link        "
msgstr "Link        "

#: src/ftp-ls.c:869
msgid "Not sure    "
msgstr "Nem biztos  "

#: src/ftp-ls.c:887
#, c-format
msgid " (%s bytes)"
msgstr " (%s b�jt)"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:150 src/http.c:624
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Csatlakoz�s %s:%hu-hoz... "

#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Kapcsol�d�s %s:%hu-hoz visszautas�tva.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:193 src/http.c:652
msgid "connected!\n"
msgstr "kapcsol�dva!\n"

#: src/ftp.c:194
#, c-format
msgid "Logging in as %s ... "
msgstr "Bel�p�s mint %s ... "

#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
msgid "Error in server response, closing control connection.\n"
msgstr "Hiba a szerver v�lasz�ban, vez�rl� kapcsolat bez�rva.\n"

#: src/ftp.c:211
msgid "Error in server greeting.\n"
msgstr "Hiba a szerver �dv�zl�s�ben.\n"

#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
msgid "Write failed, closing control connection.\n"
msgstr "�r�s nem siker�lt, vez�rl� kapcsolat bez�rva.\n"

#: src/ftp.c:226
msgid "The server refuses login.\n"
msgstr "A szerver visszautas�tja a bel�p�st.\n"

#: src/ftp.c:233
msgid "Login incorrect.\n"
msgstr "Bel�p�s sikertelen.\n"

#: src/ftp.c:240
msgid "Logged in!\n"
msgstr "Bel�pve !\n"

#: src/ftp.c:265
msgid "Server error, can't determine system type.\n"
msgstr "Szerver hiba, nem tudom meghat�rozni a rendszer tipus�t.\n"

#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
msgid "done.    "
msgstr "v�ge.    "

#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
msgid "done.\n"
msgstr "v�ge.\n"

#: src/ftp.c:353
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Ismeretlen tipus `%c', vez�rl� kapcsolat bez�rva.\n"

#: src/ftp.c:366
msgid "done.  "
msgstr "v�ge.  "

#: src/ftp.c:372
msgid "==> CWD not needed.\n"
msgstr "==> CWD nem sz�ks�ges.\n"

#: src/ftp.c:445
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Nincs ilyen k�nyvt�r `%s'.\n\n"

#. do not CWD
#: src/ftp.c:463
msgid "==> CWD not required.\n"
msgstr "==> CWD nem sz�ks�ges.\n"

#: src/ftp.c:497
msgid "Cannot initiate PASV transfer.\n"
msgstr "Nem tudok kezdem�nyezni PASV �tvitelt.\n"

#: src/ftp.c:501
msgid "Cannot parse PASV response.\n"
msgstr "Nem tudom �rtelmezni a PASV v�laszt.\n"

#: src/ftp.c:515
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Megpr�b�lok csatlakozni %s:%hu-hoz.\n"

#: src/ftp.c:602
#, c-format
msgid "Bind error (%s).\n"
msgstr "Hozz�rendel�si hiba (%s).\n"

#: src/ftp.c:618
msgid "Invalid PORT.\n"
msgstr "Hib�s PORT.\n"

#: src/ftp.c:671
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST nem siker�lt; nem fogom t�rdelni `%s'-t.\n"

#: src/ftp.c:678
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST nem siker�lt, kezd�s el�lr�l.\n"

#: src/ftp.c:727
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Nincs ilyen �llom�ny `%s'.\n\n"

#: src/ftp.c:775
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Nincs ilyen �llom�ny vagy k�nyvt�r `%s'.\n\n"

#: src/ftp.c:859 src/ftp.c:867
#, c-format
msgid "Length: %s"
msgstr "Hossz: %s"

#: src/ftp.c:861 src/ftp.c:869
#, c-format
msgid " [%s to go]"
msgstr " [m�g %s]"

#: src/ftp.c:871
msgid " (unauthoritative)\n"
msgstr " (nem hiteles)\n"

#: src/ftp.c:898
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, vez�rl� kapcsolat bez�rva.\n"

#: src/ftp.c:906
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Adat kapcsolat: %s; "

#: src/ftp.c:923
msgid "Control connection closed.\n"
msgstr "Vez�rl� kapcsolat bez�rva.\n"

#: src/ftp.c:941
msgid "Data transfer aborted.\n"
msgstr "Adat�tvitel megszak�tva.\n"

#: src/ftp.c:1005
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Az `%s' �llom�ny m�r l�tezik, nem t�lt�m le.\n"

#: src/ftp.c:1075 src/http.c:1502
#, c-format
msgid "(try:%2d)"
msgstr "(pr�ba:%2d)"

#: src/ftp.c:1139 src/http.c:1753
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' lementve [%ld]\n\n"

#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
#, c-format
msgid "Removing %s.\n"
msgstr "T�rl�m %s.\n"

#: src/ftp.c:1221
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "`%s'-t haszn�lom mint ideiglenes lista �llom�ny.\n"

#: src/ftp.c:1233
#, c-format
msgid "Removed `%s'.\n"
msgstr "T�r�lve `%s'.\n"

#: src/ftp.c:1269
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Rekurzi�s hat�r %d t�ll�pte a maxim�lis %d m�lys�get.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1330
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "A szerveren l�v� `%s' �llom�ny nem �jabb mint a helyi -- nem t�lt�m le.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1337
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "A szerveren l�v� `%s' �llom�ny �jabb mint a helyi -- let�lt�m.\n\n"

#. Sizes do not match
#: src/ftp.c:1344
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "A m�retek nem eggyeznek (helyi %ld) -- let�lt�m.\n\n"

#: src/ftp.c:1361
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Hib�s nev� szimb�likus link, kihagyom.\n"

#: src/ftp.c:1378
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "M�r l�tez� helyes szimb�likus link %s -> %s\n\n"

#: src/ftp.c:1386
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "L�trehozom a %s -> %s szimb�likus linket\n"

#: src/ftp.c:1397
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "A `%s' szimb�likus linket kihagyom.\n"

#: src/ftp.c:1409
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "A `%s' k�nyvt�rat kihagyom.\n"

#: src/ftp.c:1418
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: nem ismert/nem kezelhet� �llom�ny tipus.\n"

#: src/ftp.c:1445
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: hib�s id�-bejegyz�s.\n"

#: src/ftp.c:1466
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "K�nyvt�rakat nem t�lt�m le, mivel a m�lys�g %d (max %d).\n"

#: src/ftp.c:1512
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Nem l�pek be `%s'-be mert ki van z�rva/nincs kijel�lve.\n"

#: src/ftp.c:1559
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Visszautas�tom `%s'-t.\n"
