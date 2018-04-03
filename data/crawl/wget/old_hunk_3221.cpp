# Dutch messages for GNU Wget.
# Copyright © 1997, 1998 Free Software Foundation, Inc.
# André van Dijk <ady@unseen.demon.nl>, 1998
#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.7\n"
"POT-Creation-Date: 2001-06-03 15:27+0200\n"
"PO-Revision-Date: 2001-11-10 15:29+0200\n"
"Last-Translator: André van Dijk <ady@unseen.demon.nl>\n"
"Language-Team: Dutch <nl@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-1\n"
"Content-Transfer-Encoding: 8-bit\n"

#: src/cookies.c:588
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Fout in Set-Cookie, veld `%s'"

#: src/cookies.c:612
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Syntaxfout in Set-Cookie bij teken `%c'.\n"

#: src/cookies.c:620
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Syntaxfout in Set-Cookie: voortijdig einde van string.\n"

#: src/cookies.c:1352
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Kan cookiesbestand niet openen `%s': %s\n"

#: src/cookies.c:1364
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Fout bij schrijven naar `%s': %s\n"

#: src/cookies.c:1368
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Fout bij sluiten `%s': %s\n"

#: src/ftp-ls.c:787
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Niet ondersteund listingtype, probeer de Unix listing parser.\n"

#: src/ftp-ls.c:832 src/ftp-ls.c:834
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Index van /%s op %s:%d"

#: src/ftp-ls.c:856
msgid "time unknown       "
msgstr "tijd onbekend     "

#: src/ftp-ls.c:860
msgid "File        "
msgstr "Bestand     "

#: src/ftp-ls.c:863
msgid "Directory   "
msgstr "Map         "

#: src/ftp-ls.c:866
msgid "Link        "
msgstr "Koppeling   "

#: src/ftp-ls.c:869
msgid "Not sure    "
msgstr "Niet zeker  "

#: src/ftp-ls.c:887
#, c-format
msgid " (%s bytes)"
msgstr " (%s Bytes)"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:150 src/http.c:624
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Verbinden met %s:%hu... "

#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Verbinding met %s:%hu geweigerd.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:193 src/http.c:652
msgid "connected!\n"
msgstr "verbonden!\n"

#: src/ftp.c:194
#, c-format
msgid "Logging in as %s ... "
msgstr "Inloggen als %s ... "

# Ist das gemeint?
#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
msgid "Error in server response, closing control connection.\n"
msgstr "Fout in antwoord server, verbreek besturingsverbinding.\n"

#: src/ftp.c:211
msgid "Error in server greeting.\n"
msgstr "Fout in servergroet.\n"

#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
msgid "Write failed, closing control connection.\n"
msgstr "Schrijffout, verbreek besturingsverbinding.\n"

#: src/ftp.c:226
msgid "The server refuses login.\n"
msgstr "De server weigert de login.\n"

#: src/ftp.c:233
msgid "Login incorrect.\n"
msgstr "Login onjuist.\n"

#: src/ftp.c:240
msgid "Logged in!\n"
msgstr "Ingelogd!\n"

#: src/ftp.c:265
msgid "Server error, can't determine system type.\n"
msgstr "Serverfout, kan systeemtype niet bepalen.\n"

#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
msgid "done.    "
msgstr "gereed.    "

#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
msgid "done.\n"
msgstr "gereed.\n"

#: src/ftp.c:353
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Onbekend type `%c', verbreek besturingsverbinding.\n"

#: src/ftp.c:366
msgid "done.  "
msgstr "gereed.  "

#: src/ftp.c:372
msgid "==> CWD not needed.\n"
msgstr "-=> CWD onnodig.\n"

#: src/ftp.c:445
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Onbekende directory `%s'.\n\n"

#. do not CWD
#: src/ftp.c:463
msgid "==> CWD not required.\n"
msgstr "==> CWD niet noodzakelijk.\n"

#: src/ftp.c:497
msgid "Cannot initiate PASV transfer.\n"
msgstr "Kan PASV-overdracht niet beginnen.\n"

#: src/ftp.c:501
msgid "Cannot parse PASV response.\n"
msgstr "Kan PASV-antwoord niet ontleden.\n"

#: src/ftp.c:515
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Tracht verbinding met %s:%hu te herstellen.\n"

#: src/ftp.c:602
#, c-format
msgid "Bind error (%s).\n"
msgstr "Bindfout (%s).\n"

#: src/ftp.c:618
msgid "Invalid PORT.\n"
msgstr "Ongeldige POORT.\n"

#: src/ftp.c:671
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST gefaald; zal niet afkappen `%s'.\n"

#: src/ftp.c:678
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST gefaald, begin opnieuw.\n"

#: src/ftp.c:727
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Onbekend bestand `%s'.\n\n"

#: src/ftp.c:775
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Onbekend bestand of directory `%s'.\n\n"

#: src/ftp.c:859 src/ftp.c:867
#, c-format
msgid "Length: %s"
msgstr "Lengte: %s"

#: src/ftp.c:861 src/ftp.c:869
#, c-format
msgid " [%s to go]"
msgstr " [nog %s]"

# Geen idee hoe dit correct te vertalen
#: src/ftp.c:871
msgid " (unauthoritative)\n"
msgstr " (onauthoritatief)\n"

#: src/ftp.c:898
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, verbreek besturingsverbinding.\n"

#: src/ftp.c:906
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Gegevensverbinding: %s; "

#: src/ftp.c:923
msgid "Control connection closed.\n"
msgstr "Besturingsverbinding verbroken.\n"

#: src/ftp.c:941
msgid "Data transfer aborted.\n"
msgstr "Gegevensoverdracht afgebroken.\n"

#: src/ftp.c:1005
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Bestand `%s' reeds aanwezig, niet ophalen.\n"

#: src/ftp.c:1075 src/http.c:1502
#, c-format
msgid "(try:%2d)"
msgstr "(poging:%2d)"

#: src/ftp.c:1139 src/http.c:1753
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' bewaard [%ld]\n\n"

#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
#, c-format
msgid "Removing %s.\n"
msgstr "Verwijder `%s'.\n"

#: src/ftp.c:1221
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Aanroep `%s' als tijdelijk lijstbestand.\n"

#: src/ftp.c:1233
#, c-format
msgid "Removed `%s'.\n"
msgstr "Verwijderd `%s'.\n"

#: src/ftp.c:1269
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "De recursiediepte %d overschreed de maximum diepte %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1330
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Serverbestand niet nieuwer dan lokaal bestand `%s' -- niet ophalen.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1337
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "Serverbestand nieuwer dan lokaal bestand `%s' -- ophalen.\n\n"

#. Sizes do not match
#: src/ftp.c:1344
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "Groottes komen niet overeen (lokaal %ld) -- ophalen.\n\n"

#: src/ftp.c:1361
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Ongeldige naam voor een symbolische koppeling, overslaan.\n"

#: src/ftp.c:1378
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Juiste symbolische koppeling bestaat reeds %s -> %s\n"

#: src/ftp.c:1386
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Maak symbolische koppeling %s -> %s\n"

#: src/ftp.c:1397
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Symbolische koppelingen niet ondersteund, symbolische koppeling overslaan `%s'.\n"

#: src/ftp.c:1409
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Directory overslaan `%s'.\n"

#: src/ftp.c:1418
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: onbekend/niet-ondersteund bestandstype.\n"

#: src/ftp.c:1445
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: beschadigd tijdstempel.\n"

#: src/ftp.c:1466
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Mappen worden niet opgehaald, omdat diepte %d is (max %d).\n"

#: src/ftp.c:1512
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Daal niet af naar `%s', omdat het uitgesloten/niet-ingesloten is.\n"

#: src/ftp.c:1559
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "`%s' afgewezen.\n"
