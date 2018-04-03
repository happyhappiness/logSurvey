#
msgid ""
msgstr ""
"Project-Id-Version: GNU Wget 1.7-dev\n"
"POT-Creation-Date: 2001-02-23 13:23-0800\n"
"PO-Revision-Date: 1998-12-12 15:29+0200\n"
"Last-Translator: André van Dijk <ady@unseen.demon.nl>\n"
"Language-Team: Dutch <nl@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-1\n"
"Content-Transfer-Encoding: 8-bit\n"

#: src/ftp-ls.c:779
msgid "Usupported listing type, trying Unix listing parser.\n"
msgstr ""

#: src/ftp-ls.c:824 src/ftp-ls.c:826
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Index van /%s op %s:%d"

#: src/ftp-ls.c:848
msgid "time unknown       "
msgstr "tijd onbekend     "

#: src/ftp-ls.c:852
msgid "File        "
msgstr "Bestand     "

#: src/ftp-ls.c:855
msgid "Directory   "
msgstr "Map         "

#: src/ftp-ls.c:858
msgid "Link        "
msgstr "Koppeling   "

#: src/ftp-ls.c:861
msgid "Not sure    "
msgstr "Niet zeker  "

#: src/ftp-ls.c:879
#, c-format
msgid " (%s bytes)"
msgstr " (%s Bytes)"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:151 src/http.c:618
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Verbinden met %s:%hu... "

#: src/ftp.c:173 src/ftp.c:517 src/http.c:635
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Verbinding met %s:%hu geweigerd.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:194 src/http.c:646
msgid "connected!\n"
msgstr "verbonden!\n"

#: src/ftp.c:195
#, c-format
msgid "Logging in as %s ... "
msgstr "Inloggen als %s ... "

# Ist das gemeint?
#: src/ftp.c:204 src/ftp.c:257 src/ftp.c:288 src/ftp.c:313 src/ftp.c:407
#: src/ftp.c:459 src/ftp.c:553 src/ftp.c:626 src/ftp.c:674 src/ftp.c:722
msgid "Error in server response, closing control connection.\n"
msgstr "Fout in antwoord server, verbreek besturingsverbinding.\n"

#: src/ftp.c:212
msgid "Error in server greeting.\n"
msgstr "Fout in servers groet.\n"

#: src/ftp.c:220 src/ftp.c:322 src/ftp.c:416 src/ftp.c:468 src/ftp.c:563
#: src/ftp.c:636 src/ftp.c:684 src/ftp.c:732
msgid "Write failed, closing control connection.\n"
msgstr "Schrijf fout, verbreek besturingsverbinding.\n"

#: src/ftp.c:227
msgid "The server refuses login.\n"
msgstr "De server weigert de login.\n"

#: src/ftp.c:234
msgid "Login incorrect.\n"
msgstr "Login onjuist.\n"

#: src/ftp.c:241
msgid "Logged in!\n"
msgstr "Ingelogt!\n"

#: src/ftp.c:266
msgid "Server error, can't determine system type.\n"
msgstr ""

#: src/ftp.c:276 src/ftp.c:538 src/ftp.c:610 src/ftp.c:654
msgid "done.    "
msgstr "gereed.    "

#: src/ftp.c:302 src/ftp.c:437 src/ftp.c:705 src/ftp.c:753 src/url.c:1432
msgid "done.\n"
msgstr "gereed.\n"

#: src/ftp.c:330
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Onbekend type `%c', verbreek besturingsverbinding.\n"

#: src/ftp.c:343
msgid "done.  "
msgstr "gereed.  "

#: src/ftp.c:349
#, fuzzy
msgid "==> CWD not needed.\n"
msgstr "=> CWD niet nodig.\n"

#: src/ftp.c:423
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Onbekende directory `%s'.\n"
"\n"

#. do not CWD
#: src/ftp.c:441
#, fuzzy
msgid "==> CWD not required.\n"
msgstr "=> CWD niet noodzakelijk.\n"

#: src/ftp.c:475
msgid "Cannot initiate PASV transfer.\n"
msgstr "Kan PASV-overdracht niet beginnen.\n"

#: src/ftp.c:479
msgid "Cannot parse PASV response.\n"
msgstr "Kan PASV-antwoord niet ontleden.\n"

#: src/ftp.c:493
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Tracht verbinding met %s:%hu te herstellen.\n"

#: src/ftp.c:580
#, c-format
msgid "Bind error (%s).\n"
msgstr "Bind fout (%s).\n"

#: src/ftp.c:596
msgid "Invalid PORT.\n"
msgstr "Ongeldige POORT.\n"

#: src/ftp.c:643
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"REST gefaald, begin opnieuw.\n"

#: src/ftp.c:692
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Onbekend bestand `%s'.\n"
"\n"

#: src/ftp.c:740
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Onbekend bestand of directory `%s'.\n"
"\n"

#: src/ftp.c:816 src/ftp.c:823
#, c-format
msgid "Length: %s"
msgstr "Lengte: %s"

#: src/ftp.c:818 src/ftp.c:825
#, c-format
msgid " [%s to go]"
msgstr " [nog %s]"

# Geen idee hoe dit correct te vertalen
#: src/ftp.c:827
msgid " (unauthoritative)\n"
msgstr " (onauthoritatief)\n"

#: src/ftp.c:853
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, verbreek besturingsverbinding.\n"

#: src/ftp.c:861
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Gegevensverbinding: %s; "

#: src/ftp.c:878
msgid "Control connection closed.\n"
msgstr "Besturingsverbinding verbroken.\n"

#: src/ftp.c:896
msgid "Data transfer aborted.\n"
msgstr "Gegevensoverdracht afgebroken.\n"

#: src/ftp.c:960
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Bestand `%s' reeds aanwezig, niet ophalen.\n"

#: src/ftp.c:1021 src/http.c:1394
#, c-format
msgid "(try:%2d)"
msgstr "(poging:%2d)"

#: src/ftp.c:1085 src/http.c:1632
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' bewaard [%ld]\n"
"\n"

#: src/ftp.c:1127 src/main.c:789 src/recur.c:509 src/retr.c:602
#, c-format
msgid "Removing %s.\n"
msgstr "Verwijder `%s'.\n"

#: src/ftp.c:1168
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Aanroep `%s' als tijdelijk lijstbestand.\n"

#: src/ftp.c:1180
#, c-format
msgid "Removed `%s'.\n"
msgstr "Verwijderd `%s'.\n"

#: src/ftp.c:1216
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "De recursiediepte %d overschreed de maximum diepte %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1277
#, fuzzy, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Verafgelegen bestand is nieuwer, ophalen.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1284
#, fuzzy, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr "Verafgelegen bestand is nieuwer, ophalen.\n"

#. Sizes do not match
#: src/ftp.c:1291
#, fuzzy, c-format
msgid ""
"The sizes do not match (local %ld) -- retrieving.\n"
"\n"
msgstr "Groottes komen niet overeen (lokaal %ld), ophalen.\n"

#: src/ftp.c:1308
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Ongeldige naam voor een symbolische koppeling, overslaan.\n"

#: src/ftp.c:1325
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr "Juiste symbolische koppeling bestaat reeds %s -> %s\n"

#: src/ftp.c:1333
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Maak symbolische koppeling %s -> %s\n"

#: src/ftp.c:1344
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr ""
"Symbolische koppelingen niet ondersteunt, symbolische koppeling overslaan "
"`%s'.\n"

#: src/ftp.c:1356
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Directory overslaan `%s'.\n"

#: src/ftp.c:1365
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: onbekend/niet-ondersteund bestandstype.\n"

#: src/ftp.c:1392
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: beschadigd tijdstempel.\n"

#: src/ftp.c:1413
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Mappen worden niet opgehaald, omdat diepte %d is (max %d).\n"

#: src/ftp.c:1449
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Daal niet af naar `%s', omdat het uitgesloten/niet-ingesloten is.\n"

#: src/ftp.c:1494
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "`%s' afgewezen.\n"
