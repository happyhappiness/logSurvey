msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: voľba `-W %s' nepodporuje parameter\n"

# , c-format
#: src/host.c:636
#, c-format
msgid "Resolving %s... "
msgstr "Prevádzam %s na IP adresu... "

#: src/host.c:656 src/host.c:672
#, c-format
msgid "failed: %s.\n"
msgstr "zlyhalo: %s.\n"

#: src/host.c:674
msgid "failed: timed out.\n"
msgstr "zlyhalo: časový limit vypršal.\n"

#: src/host.c:762
msgid "Host not found"
msgstr "Hostiteľ nebol nájdený"

#: src/host.c:764
msgid "Unknown error"
msgstr "Neznáma chyba"

#: src/html-url.c:293
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Nemôžem rozložiť neúplný odkaz %s.\n"

#. this is fatal
#: src/http.c:674
msgid "Failed to set up an SSL context\n"
msgstr "Nepodarilo sa nastaviť SSL kontext.\n"

#: src/http.c:680
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Nepodarilo sa načítať certifikáty z %s\n"

#: src/http.c:684 src/http.c:692
msgid "Trying without the specified certificate\n"
msgstr "Skúšam bez zadaného certifikátu\n"

#: src/http.c:688
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Nepodarilo sa načítať kľúč certifikátu z %s\n"

#: src/http.c:761 src/http.c:1809
msgid "Unable to establish SSL connection.\n"
msgstr "Nepodarilo sa nadviazať SSL spojenie.\n"

# , c-format
#: src/http.c:770
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Používam existujúce spojenie s %s:%hu.\n"

#: src/http.c:1034
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Požiadavku HTTP nebolo možné odoslať: %s.\n"

# , c-format
#: src/http.c:1039
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s požiadavka odoslaná, čakám na odpoveď... "

#: src/http.c:1083
msgid "End of file while parsing headers.\n"
msgstr "Koniec súboru počas analýzy hlavičiek.\n"

# , c-format
#: src/http.c:1093
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Chyba (%s) pri čítaní hlavičiek.\n"

#: src/http.c:1128
msgid "No data received"
msgstr "Neprišli žiadne dáta"

#: src/http.c:1130
msgid "Malformed status line"
msgstr "Odpoveď servera má skomolený stavový riadok"

#: src/http.c:1135
msgid "(no description)"
msgstr "(bez popisu)"

#: src/http.c:1267
msgid "Authorization failed.\n"
msgstr "Autorizácia zlyhala.\n"

#: src/http.c:1274
msgid "Unknown authentication scheme.\n"
msgstr "Neznámy spôsob autentifikácie.\n"

# , c-format
#: src/http.c:1314
#, c-format
msgid "Location: %s%s\n"
msgstr "Presmerované na: %s%s\n"

#: src/http.c:1315 src/http.c:1454
msgid "unspecified"
msgstr "neudané"

#: src/http.c:1316
msgid " [following]"
msgstr " [nasledujem]"

#: src/http.c:1383
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
