"\n"

#. do not CWD
#: src/ftp.c:595
msgid "==> CWD not required.\n"
msgstr "==> CWD nem sz�ks�ges.\n"

#: src/ftp.c:654
msgid "Cannot initiate PASV transfer.\n"
msgstr "Nem tudok kezdem�nyezni PASV �tvitelt.\n"

#: src/ftp.c:658
msgid "Cannot parse PASV response.\n"
msgstr "Nem tudom �rtelmezni a PASV v�laszt.\n"

#: src/ftp.c:676
#, fuzzy, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr "nem tudok csatlakozni %s:%hu-hoz: %s\n"

#: src/ftp.c:724
#, c-format
msgid "Bind error (%s).\n"
msgstr "Hozz�rendel�si hiba (%s).\n"

#: src/ftp.c:730
msgid "Invalid PORT.\n"
msgstr "Hib�s PORT.\n"

#: src/ftp.c:776
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"REST nem siker�lt, kezd�s el�lr�l.\n"

#: src/ftp.c:837
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Nincs ilyen �llom�ny `%s'.\n"
"\n"

#: src/ftp.c:884
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Nincs ilyen �llom�ny vagy k�nyvt�r `%s'.\n"
"\n"

#. We cannot just invent a new name and use it (which is
#. what functions like unique_create typically do)
#. because we told the user we'd use this name.
#. Instead, return and retry the download.
#: src/ftp.c:946 src/http.c:1913
#, c-format
msgid "%s has sprung into existence.\n"
msgstr ""

#: src/ftp.c:1008
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, vez�rl� kapcsolat bez�rva.\n"

#: src/ftp.c:1016
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Adat kapcsolat: %s; "

#: src/ftp.c:1031
msgid "Control connection closed.\n"
msgstr "Vez�rl� kapcsolat bez�rva.\n"

#: src/ftp.c:1049
msgid "Data transfer aborted.\n"
msgstr "Adat�tvitel megszak�tva.\n"

#: src/ftp.c:1114
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Az `%s' �llom�ny m�r l�tezik, nem t�lt�m le.\n"

#: src/ftp.c:1182 src/http.c:2130
#, c-format
msgid "(try:%2d)"
msgstr "(pr�ba:%2d)"

#: src/ftp.c:1252 src/http.c:2409
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s]\n"
"\n"
msgstr ""
"%s (%s) - `%s' lementve [%ld]\n"
"\n"

#: src/ftp.c:1294 src/main.c:948 src/recur.c:376 src/retr.c:842
#, c-format
msgid "Removing %s.\n"
msgstr "T�rl�m %s.\n"

#: src/ftp.c:1336
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "`%s'-t haszn�lom mint ideiglenes lista �llom�ny.\n"

#: src/ftp.c:1351
#, c-format
msgid "Removed `%s'.\n"
msgstr "T�r�lve `%s'.\n"

#: src/ftp.c:1386
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Rekurzi�s hat�r %d t�ll�pte a maxim�lis %d m�lys�get.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1456
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr ""
"A szerveren l�v� `%s' �llom�ny nem �jabb mint a helyi -- nem t�lt�m le.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1463
#, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr ""
"A szerveren l�v� `%s' �llom�ny �jabb mint a helyi -- let�lt�m.\n"
"\n"

#. Sizes do not match
#: src/ftp.c:1470
#, fuzzy, c-format
msgid ""
"The sizes do not match (local %s) -- retrieving.\n"
"\n"
msgstr ""
"A m�retek nem eggyeznek (helyi %ld) -- let�lt�m.\n"
"\n"

#: src/ftp.c:1488
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Hib�s nev� szimb�likus link, kihagyom.\n"

#: src/ftp.c:1505
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"M�r l�tez� helyes szimb�likus link %s -> %s\n"
"\n"

#: src/ftp.c:1513
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "L�trehozom a %s -> %s szimb�likus linket\n"

#: src/ftp.c:1523
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "A `%s' szimb�likus linket kihagyom.\n"

#: src/ftp.c:1535
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "A `%s' k�nyvt�rat kihagyom.\n"

#: src/ftp.c:1544
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: nem ismert/nem kezelhet� �llom�ny tipus.\n"

#: src/ftp.c:1571
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: hib�s id�-bejegyz�s.\n"

#: src/ftp.c:1599
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "K�nyvt�rakat nem t�lt�m le, mivel a m�lys�g %d (max %d).\n"

#: src/ftp.c:1649
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Nem l�pek be `%s'-be mert ki van z�rva/nincs kijel�lve.\n"

#: src/ftp.c:1715 src/ftp.c:1729
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Visszautas�tom `%s'-t.\n"
