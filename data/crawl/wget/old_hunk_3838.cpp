"Content-Type: text/plain; charset=iso-8859-1\n"
"Content-Transfer-Encoding: 8-bit\n"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:147 src/http.c:346
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Verbinden met %s:%hu... "

#: src/ftp.c:169 src/ftp.c:411 src/http.c:363
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Verbinding met %s:%hu geweigerd.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:190 src/http.c:374
msgid "connected!\n"
msgstr "verbonden!\n"

#: src/ftp.c:191
#, c-format
msgid "Logging in as %s ... "
msgstr "Inloggen als %s ... "

# Ist das gemeint?
#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
msgid "Error in server response, closing control connection.\n"
msgstr "Fout in antwoord server, verbreek besturingsverbinding.\n"

#: src/ftp.c:208
msgid "Error in server greeting.\n"
msgstr "Fout in servers groet.\n"

#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
msgid "Write failed, closing control connection.\n"
msgstr "Schrijf fout, verbreek besturingsverbinding.\n"

#: src/ftp.c:223
msgid "The server refuses login.\n"
msgstr "De server weigert de login.\n"

#: src/ftp.c:230
msgid "Login incorrect.\n"
msgstr "Login onjuist.\n"

#: src/ftp.c:237
msgid "Logged in!\n"
msgstr "Ingelogt!\n"

#: src/ftp.c:270
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Onbekend type `%c', verbreek besturingsverbinding.\n"

#: src/ftp.c:283
msgid "done.  "
msgstr "gereed.  "

#: src/ftp.c:289
msgid "=> CWD not needed.\n"
msgstr "=> CWD niet nodig.\n"

#: src/ftp.c:317
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Onbekende directory `%s'.\n\n"

#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1426
msgid "done.\n"
msgstr "gereed.\n"

#. do not CWD
#: src/ftp.c:335
msgid "=> CWD not required.\n"
msgstr "=> CWD niet noodzakelijk.\n"

#: src/ftp.c:369
msgid "Cannot initiate PASV transfer.\n"
msgstr "Kan PASV-overdracht niet beginnen.\n"

#: src/ftp.c:373
msgid "Cannot parse PASV response.\n"
msgstr "Kan PASV-antwoord niet ontleden.\n"

#: src/ftp.c:387
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Tracht verbinding met %s:%hu te herstellen.\n"

#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
msgid "done.    "
msgstr "gereed.    "

#: src/ftp.c:474
#, c-format
msgid "Bind error (%s).\n"
msgstr "Bind fout (%s).\n"

#: src/ftp.c:490
msgid "Invalid PORT.\n"
msgstr "Ongeldige POORT.\n"

#: src/ftp.c:537
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST gefaald, begin opnieuw.\n"

#: src/ftp.c:586
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Onbekend bestand `%s'.\n\n"

#: src/ftp.c:634
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Onbekend bestand of directory `%s'.\n\n"

#: src/ftp.c:692 src/ftp.c:699
#, c-format
msgid "Length: %s"
msgstr "Lengte: %s"

#: src/ftp.c:694 src/ftp.c:701
#, c-format
msgid " [%s to go]"
msgstr " [nog %s]"

# Geen idee hoe dit correct te vertalen
#: src/ftp.c:703
msgid " (unauthoritative)\n"
msgstr " (onauthoritatief)\n"

#: src/ftp.c:721
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, verbreek besturingsverbinding.\n"

#: src/ftp.c:729
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Gegevensverbinding: %s; "

#: src/ftp.c:746
msgid "Control connection closed.\n"
msgstr "Besturingsverbinding verbroken.\n"

#: src/ftp.c:764
msgid "Data transfer aborted.\n"
msgstr "Gegevensoverdracht afgebroken.\n"

#: src/ftp.c:830
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Bestand `%s' reeds aanwezig, niet ophalen.\n"

#: src/ftp.c:896 src/http.c:922
#, c-format
msgid "(try:%2d)"
msgstr "(poging:%2d)"

#: src/ftp.c:955 src/http.c:1116
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' bewaard [%ld]\n\n"

#: src/ftp.c:1001
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Aanroep `%s' als tijdelijk lijstbestand.\n"

#: src/ftp.c:1013
#, c-format
msgid "Removed `%s'.\n"
msgstr "Verwijderd `%s'.\n"

#: src/ftp.c:1049
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "De recursiediepte %d overschreed de maximum diepte %d.\n"

#: src/ftp.c:1096 src/http.c:1054
#, c-format
msgid "Local file `%s' is more recent, not retrieving.\n\n"
msgstr "Lokaal bestand `%s' is nieuwer, niet ophalen.\n\n"

#: src/ftp.c:1102 src/http.c:1060
#, c-format
msgid "The sizes do not match (local %ld), retrieving.\n"
msgstr "Groottes komen niet overeen (lokaal %ld), ophalen.\n"

#: src/ftp.c:1119
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Ongeldige naam voor een symbolische koppeling, overslaan.\n"

#: src/ftp.c:1136
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Juiste symbolische koppeling bestaat reeds %s -> %s\n"

#: src/ftp.c:1143
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Maak symbolische koppeling %s -> %s\n"

#: src/ftp.c:1154
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Symbolische koppelingen niet ondersteunt, symbolische koppeling overslaan `%s'.\n"

#: src/ftp.c:1166
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Directory overslaan `%s'.\n"

#: src/ftp.c:1175
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: onbekend/niet-ondersteund bestandstype.\n"

#: src/ftp.c:1191
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: beschadigd tijdstempel.\n"

#: src/ftp.c:1211
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Mappen worden niet opgehaald, omdat diepte %d is (max %d).\n"

#: src/ftp.c:1250
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Daal niet af naar `%s', omdat het uitgesloten/niet-ingesloten is.\n"

#: src/ftp.c:1295
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "`%s' afgewezen.\n"
