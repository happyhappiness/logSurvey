# Hungarian translation of GNU wget
# Copyright (C) 2001 Free Software Foundation, Inc.
# Szasz Pal <szpal@Maria.UTCluj.Ro>, 2001.
#
msgid ""
msgstr ""
"Project-Id-Version: GNU wget 1.8.2\n"
"POT-Creation-Date: 2001-12-17 16:30+0100\n"
"PO-Revision-Date: 2003-01-22 10:56+0200\n"
"Last-Translator: Szasz Pal <szpal@Maria.UTCluj.Ro>\n"
"Language-Team: Hungarian <translation-team-hu@lists.sourceforge.net>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-2\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/connect.c:94
#, c-format
msgid "Connecting to %s[%s]:%hu... "
msgstr "Csatlakozás %s[%s]:%hu-hoz... "

#: src/connect.c:97
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Csatlakozás %s:%hu-hoz... "

#: src/connect.c:131
msgid "connected.\n"
msgstr "kapcsolódva.\n"

#: src/cookies.c:595
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Hiba a Set-Cookie-ban, mezõ `%s'"

#: src/cookies.c:619
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Szintaktikai hiba a Set-Cookie-ban a `%c' karakternél.\n"

#: src/cookies.c:627
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Szintaktikai hiba a Set-Cookie-ban: korai vége a szövegnek.\n"

#: src/cookies.c:1329
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Nem tudom megnyitni a `%s' cookie állományt: %s\n"

#: src/cookies.c:1341
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Nem tudok írni `%s'-ba (%s).\n"

#: src/cookies.c:1345
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Hiba `%s' bezárásánál: %s\n"

#: src/ftp-ls.c:802
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Nemkezelt lista tipus, próbálom Unix lista értelmezõvel.\n"

#: src/ftp-ls.c:847 src/ftp-ls.c:849
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "/%s tartalma %s:%d-n"

#: src/ftp-ls.c:871
msgid "time unknown       "
msgstr "idõ ismeretlen     "

#: src/ftp-ls.c:875
msgid "File        "
msgstr "Állomány    "

#: src/ftp-ls.c:878
msgid "Directory   "
msgstr "Könyvtár    "

#: src/ftp-ls.c:881
msgid "Link        "
msgstr "Link        "

#: src/ftp-ls.c:884
msgid "Not sure    "
msgstr "Nem biztos  "

#: src/ftp-ls.c:902
#, c-format
msgid " (%s bytes)"
msgstr " (%s bájt)"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:179
#, c-format
msgid "Logging in as %s ... "
msgstr "Belépés mint %s ... "

#: src/ftp.c:188 src/ftp.c:241 src/ftp.c:272 src/ftp.c:326 src/ftp.c:419
#: src/ftp.c:470 src/ftp.c:500 src/ftp.c:564 src/ftp.c:628 src/ftp.c:689
#: src/ftp.c:737
msgid "Error in server response, closing control connection.\n"
msgstr "Hiba a szerver válaszában, vezérlõ kapcsolat bezárva.\n"

#: src/ftp.c:196
msgid "Error in server greeting.\n"
msgstr "Hiba a szerver üdvözlésében.\n"

#: src/ftp.c:204 src/ftp.c:335 src/ftp.c:428 src/ftp.c:509 src/ftp.c:574
#: src/ftp.c:638 src/ftp.c:699 src/ftp.c:747
msgid "Write failed, closing control connection.\n"
msgstr "Írás nem sikerült, vezérlõ kapcsolat bezárva.\n"

#: src/ftp.c:211
msgid "The server refuses login.\n"
msgstr "A szerver visszautasítja a belépést.\n"

#: src/ftp.c:218
msgid "Login incorrect.\n"
msgstr "Belépés sikertelen.\n"

#: src/ftp.c:225
msgid "Logged in!\n"
msgstr "Belépve !\n"

#: src/ftp.c:250
msgid "Server error, can't determine system type.\n"
msgstr "Szerver hiba, nem tudom meghatározni a rendszer tipusát.\n"

#: src/ftp.c:260 src/ftp.c:549 src/ftp.c:612 src/ftp.c:669
msgid "done.    "
msgstr "vége.    "

#: src/ftp.c:314 src/ftp.c:449 src/ftp.c:484 src/ftp.c:720 src/ftp.c:768
#: src/host.c:283
msgid "done.\n"
msgstr "vége.\n"

#: src/ftp.c:343
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Ismeretlen tipus `%c', vezérlõ kapcsolat bezárva.\n"

#: src/ftp.c:356
msgid "done.  "
msgstr "vége.  "

#: src/ftp.c:362
msgid "==> CWD not needed.\n"
msgstr "==> CWD nem szükséges.\n"

#: src/ftp.c:435
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Nincs ilyen könyvtár `%s'.\n"
"\n"

#. do not CWD
#: src/ftp.c:453
msgid "==> CWD not required.\n"
msgstr "==> CWD nem szükséges.\n"

#: src/ftp.c:516
msgid "Cannot initiate PASV transfer.\n"
msgstr "Nem tudok kezdeményezni PASV átvitelt.\n"

#: src/ftp.c:520
msgid "Cannot parse PASV response.\n"
msgstr "Nem tudom értelmezni a PASV választ.\n"

#: src/ftp.c:541
#, c-format
msgid "couldn't connect to %s:%hu: %s\n"
msgstr "nem tudok csatlakozni %s:%hu-hoz: %s\n"

#: src/ftp.c:591
#, c-format
msgid "Bind error (%s).\n"
msgstr "Hozzárendelési hiba (%s).\n"

#: src/ftp.c:598
msgid "Invalid PORT.\n"
msgstr "Hibás PORT.\n"

#: src/ftp.c:651
#, c-format
msgid ""
"\n"
"REST failed; will not truncate `%s'.\n"
msgstr ""
"\n"
"REST nem sikerült; nem fogom tördelni `%s'-t.\n"

#: src/ftp.c:658
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"REST nem sikerült, kezdés elõlröl.\n"

#: src/ftp.c:707
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Nincs ilyen állomány `%s'.\n"
"\n"

#: src/ftp.c:755
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Nincs ilyen állomány vagy könyvtár `%s'.\n"
"\n"

#: src/ftp.c:839 src/ftp.c:847
#, c-format
msgid "Length: %s"
msgstr "Hossz: %s"

#: src/ftp.c:841 src/ftp.c:849
#, c-format
msgid " [%s to go]"
msgstr " [még %s]"

#: src/ftp.c:851
msgid " (unauthoritative)\n"
msgstr " (nem hiteles)\n"

#: src/ftp.c:877
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, vezérlõ kapcsolat bezárva.\n"

#: src/ftp.c:885
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Adat kapcsolat: %s; "

#: src/ftp.c:902
msgid "Control connection closed.\n"
msgstr "Vezérlõ kapcsolat bezárva.\n"

#: src/ftp.c:920
msgid "Data transfer aborted.\n"
msgstr "Adatátvitel megszakítva.\n"

#: src/ftp.c:984
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Az `%s' állomány már létezik, nem töltöm le.\n"

#: src/ftp.c:1054 src/http.c:1527
#, c-format
msgid "(try:%2d)"
msgstr "(próba:%2d)"

#: src/ftp.c:1118 src/http.c:1786
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' lementve [%ld]\n"
"\n"

#: src/ftp.c:1160 src/main.c:819 src/recur.c:349 src/retr.c:587
#, c-format
msgid "Removing %s.\n"
msgstr "Törlöm %s.\n"

#: src/ftp.c:1202
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "`%s'-t használom mint ideiglenes lista állomány.\n"

#: src/ftp.c:1217
#, c-format
msgid "Removed `%s'.\n"
msgstr "Törölve `%s'.\n"

#: src/ftp.c:1252
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Rekurziós határ %d túllépte a maximális %d mélységet.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1317
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "A szerveren lévõ `%s' állomány nem újabb mint a helyi -- nem töltöm le.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1324
#, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr ""
"A szerveren lévõ `%s' állomány újabb mint a helyi -- letöltöm.\n"
"\n"

#. Sizes do not match
#: src/ftp.c:1331
#, c-format
msgid ""
"The sizes do not match (local %ld) -- retrieving.\n"
"\n"
msgstr ""
"A méretek nem eggyeznek (helyi %ld) -- letöltöm.\n"
"\n"

#: src/ftp.c:1348
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Hibás nevû szimbólikus link, kihagyom.\n"

#: src/ftp.c:1365
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"Már létezõ helyes szimbólikus link %s -> %s\n"
"\n"

#: src/ftp.c:1373
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Létrehozom a %s -> %s szimbólikus linket\n"

#: src/ftp.c:1384
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "A `%s' szimbólikus linket kihagyom.\n"

#: src/ftp.c:1396
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "A `%s' könyvtárat kihagyom.\n"

#: src/ftp.c:1405
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: nem ismert/nem kezelhetõ állomány tipus.\n"

#: src/ftp.c:1432
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: hibás idö-bejegyzés.\n"

#: src/ftp.c:1457
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Könyvtárakat nem töltöm le, mivel a mélység %d (max %d).\n"

#: src/ftp.c:1507
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Nem lépek be `%s'-be mert ki van zárva/nincs kijelölve.\n"

#: src/ftp.c:1561
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Visszautasítom `%s'-t.\n"
