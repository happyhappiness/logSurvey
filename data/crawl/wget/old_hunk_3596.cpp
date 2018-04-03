msgid "%s: option requires an argument -- %c\n"
msgstr "%s: optie vereist een argument -- %c\n"

#: src/host.c:394
#, c-format
msgid "%s: Cannot determine user-id.\n"
msgstr "%s: Kan gebruikers-id niet bepalen.\n"

#: src/host.c:406
#, c-format
msgid "%s: Warning: uname failed: %s\n"
msgstr "%s: Waarschuwing: uname gefaald: %s\n"

#: src/host.c:418
#, c-format
msgid "%s: Warning: gethostname failed\n"
msgstr "%s: Waarschuwing: gethostname gefaald\n"

#: src/host.c:446
#, c-format
msgid "%s: Warning: cannot determine local IP address.\n"
msgstr "%s: Waarschuwing: kan lokaal IP-adres niet bepalen.\n"

#: src/host.c:460
#, c-format
msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
msgstr "%s: Waarschuwing: omgekeerd opzoeken van lokaal IP-adres onmogelijk.\n"

#. This gets ticked pretty often.  Karl Berry reports
#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:473
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""
"%s: Waarschuwing: omgekeerd opzoeken van lokaal adres levert geen\n"
"volledige domein naam.\n"

#: src/host.c:501
msgid "Host not found"
msgstr "Host niet gevonden"

#: src/host.c:503
msgid "Unknown error"
msgstr "Onbekende fout"

#. this is fatal
#: src/http.c:549
msgid "Failed to set up an SSL context\n"
msgstr ""

#: src/http.c:555
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr ""

#: src/http.c:559 src/http.c:567
msgid "Trying without the specified certificate\n"
msgstr ""

#: src/http.c:563
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr ""

#: src/http.c:657 src/http.c:1470
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:665
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Tracht verbinding met %s:%hu te herstellen.\n"

#: src/http.c:841
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Schrijven HTTP-verzoek gefaald.\n"

#: src/http.c:846
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s verzoek verzonden, wacht op antwoord... "

#: src/http.c:890
msgid "End of file while parsing headers.\n"
msgstr "Bestandseinde bij ontleden kopregels.\n"

#: src/http.c:901
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Leesfout (%s) in kopregels.\n"

#: src/http.c:941
msgid "No data received"
msgstr "Geen gegevens ontvangen"

#: src/http.c:943
msgid "Malformed status line"
msgstr "Onjuiste statusregel"

#: src/http.c:948
msgid "(no description)"
msgstr "(geen beschrijving)"

#: src/http.c:1066
msgid "Authorization failed.\n"
msgstr "Authorisatie gefaald.\n"

#: src/http.c:1073
msgid "Unknown authentication scheme.\n"
msgstr "Onbekend authenticatieschema.\n"

#: src/http.c:1163
#, c-format
msgid "Location: %s%s\n"
msgstr "Lokatie: %s%s\n"

#: src/http.c:1164 src/http.c:1189
msgid "unspecified"
msgstr "ongespecificeerd"

#: src/http.c:1165
msgid " [following]"
msgstr "[volgt]"

# Header
#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1179
msgid "Length: "
msgstr "Lengte: "

#: src/http.c:1184
#, c-format
msgid " (%s to go)"
msgstr " (nog %s)"

#: src/http.c:1189
msgid "ignored"
msgstr "genegeerd"

#: src/http.c:1290
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Waarschuwing: jokertekens niet ondersteund in HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1311
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Bestand `%s' reeds aanwezig, niet ophalen.\n"

#: src/http.c:1462
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kan niet schrijven naar `%s' (%s).\n"

#: src/http.c:1480
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FOUT: Omleiding (%d) zonder lokatie.\n"

#: src/http.c:1505
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FOUT %d: %s.\n"

#: src/http.c:1518
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Laatste-aanpassingskopregel mist -- tijdstempels uitgeschakeld.\n"

#: src/http.c:1526
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Laatst-aanpassingskopregel ongeldig -- tijdtstempels genegeerd.\n"

#: src/http.c:1549
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:1557
#, fuzzy, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Groottes komen niet overeen (lokaal %ld), ophalen.\n"

#: src/http.c:1561
msgid "Remote file is newer, retrieving.\n"
msgstr "Verafgelegen bestand is nieuwer, ophalen.\n"

#: src/http.c:1606
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' bewaard [%ld/%ld]\n"
"\n"

#: src/http.c:1654
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Verbinding verbroken bij byte %ld. "

#: src/http.c:1662
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - `%s' bewaard [%ld/%ld])\n"
"\n"

#: src/http.c:1682
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Verbinding verbroken bij byte %ld/%ld. "

#: src/http.c:1693
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Leesfout bij byte %ld (%s)."

#: src/http.c:1701
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Leesfout bij byte %ld/%ld (%s). "

#: src/init.c:336 src/netrc.c:261
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Kan `%s' niet lezen (%s).\n"

#: src/init.c:354 src/init.c:360
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Fout in `%s' bij regel %d.\n"

#: src/init.c:391
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: Waarschuwing: Zowel systeem als gebruiker wgetrc verwijzen naar `%s'.\n"

#: src/init.c:483
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: Onbekende opdracht `%s', waarde `%s'.\n"

#: src/init.c:504
#, fuzzy, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: Waarschuwing: omgekeerd opzoeken van lokaal IP-adres onmogelijk.\n"

#: src/init.c:532
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Gelieve `aan' of `uit' te specificeren.\n"

#: src/init.c:576
#, fuzzy, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Gelieve `aan' of `uit' te specificeren.\n"

#: src/init.c:595 src/init.c:852 src/init.c:874 src/init.c:938
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Ongeldige specificatie `%s'\n"

#: src/init.c:708 src/init.c:730 src/init.c:752 src/init.c:778
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Ongeldige specificatie `%s'\n"
