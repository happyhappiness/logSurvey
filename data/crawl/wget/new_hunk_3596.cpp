msgid "%s: option requires an argument -- %c\n"
msgstr "%s: optie vereist een argument -- %c\n"

#: src/host.c:374
msgid "Host not found"
msgstr "Host niet gevonden"

#: src/host.c:376
msgid "Unknown error"
msgstr "Onbekende fout"

#. this is fatal
#: src/http.c:555
msgid "Failed to set up an SSL context\n"
msgstr "SSL-omgeving omzetten is mislukt\n"

#: src/http.c:561
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Laden certificaten van %s mislukt\n"

#: src/http.c:565 src/http.c:573
msgid "Trying without the specified certificate\n"
msgstr "Pogen zonder gespecificeerde certificaat\n"

#: src/http.c:569
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Verkrijgen certificaatsleutel van %s mislukt\n"

#: src/http.c:663 src/http.c:1593
msgid "Unable to establish SSL connection.\n"
msgstr "Niet in staat SSL-verbinding op te zetten\n"

#: src/http.c:671
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Herbruik  verbinding met %s:%hu.\n"

#: src/http.c:861
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Schrijven HTTP-verzoek gefaald: %s.\n"

#: src/http.c:866
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s verzoek verzonden, wacht op antwoord... "

#: src/http.c:910
msgid "End of file while parsing headers.\n"
msgstr "Bestandseinde bij ontleden kopregels.\n"

#: src/http.c:920
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Leesfout (%s) in kopregels.\n"

#: src/http.c:959
msgid "No data received"
msgstr "Geen gegevens ontvangen"

#: src/http.c:961
msgid "Malformed status line"
msgstr "Onjuiste statusregel"

#: src/http.c:966
msgid "(no description)"
msgstr "(geen beschrijving)"

#: src/http.c:1089
msgid "Authorization failed.\n"
msgstr "Authorisatie gefaald.\n"

#: src/http.c:1096
msgid "Unknown authentication scheme.\n"
msgstr "Onbekend authenticatieschema.\n"

#: src/http.c:1136
#, c-format
msgid "Location: %s%s\n"
msgstr "Lokatie: %s%s\n"

#: src/http.c:1137 src/http.c:1269
msgid "unspecified"
msgstr "ongespecificeerd"

#: src/http.c:1138
msgid " [following]"
msgstr "[volgt]"

#: src/http.c:1200
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    Het bestand is reeds volledig ontvangen; niets te doen.\n\n"

#: src/http.c:1216
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
"Voortzetten ophalen van dit bestand mislukt, dit is in strijd met `-c'.\n"
"Weiger bestaande bestand af te kappen `%s'.\n"
"\n"

# Header
#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1259
msgid "Length: "
msgstr "Lengte: "

#: src/http.c:1264
#, c-format
msgid " (%s to go)"
msgstr " (nog %s)"

#: src/http.c:1269
msgid "ignored"
msgstr "genegeerd"

#: src/http.c:1399
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Waarschuwing: jokertekens niet ondersteund in HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1417
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Bestand `%s' reeds aanwezig, niet ophalen.\n"

#: src/http.c:1585
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kan niet schrijven naar `%s' (%s).\n"

#: src/http.c:1602
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FOUT: Omleiding (%d) zonder lokatie.\n"

#: src/http.c:1630
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FOUT %d: %s.\n"

#: src/http.c:1642
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Laatste-aanpassingskopregel mist -- tijdstempels uitgeschakeld.\n"

#: src/http.c:1650
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Laatst-aanpassingskopregel ongeldig -- tijdtstempels genegeerd.\n"

#: src/http.c:1673
#, c-format
msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
msgstr "Serverbestand niet nieuwer dan lokaal bestand `%s' -- niet ophalen.\n\n"

#: src/http.c:1680
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Groottes komen niet overeen (lokaal %ld) -- ophalen.\n"

#: src/http.c:1684
msgid "Remote file is newer, retrieving.\n"
msgstr "Verafgelegen bestand is nieuwer, ophalen.\n"

#: src/http.c:1728
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - `%s' bewaard [%ld/%ld]\n\n"

#: src/http.c:1774
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Verbinding verbroken bij byte %ld. "

#: src/http.c:1782
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - `%s' bewaard [%ld/%ld])\n\n"

#: src/http.c:1801
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Verbinding verbroken bij byte %ld/%ld. "

#: src/http.c:1812
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Leesfout bij byte %ld (%s)."

#: src/http.c:1820
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Leesfout bij byte %ld/%ld (%s). "

#: src/init.c:349 src/netrc.c:267
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Kan `%s' niet lezen (%s).\n"

#: src/init.c:367 src/init.c:373
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Fout in `%s' bij regel %d.\n"

#: src/init.c:405
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Waarschuwing: Zowel systeem als gebruiker wgetrc verwijzen naar `%s'.\n"

#: src/init.c:497
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: Onbekende opdracht `%s', waarde `%s'.\n"

#: src/init.c:529
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: Kan `%s' niet omzetten naar een IP-adres.\n"

#: src/init.c:559
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Gelieve `aan' of `uit' te specificeren.\n"

#: src/init.c:603
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Gelieve aan, uit of nooit te specificeren.\n"

#: src/init.c:622 src/init.c:919 src/init.c:941 src/init.c:1005
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Ongeldige specificatie `%s'\n"

#: src/init.c:775 src/init.c:797 src/init.c:819 src/init.c:845
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Ongeldige specificatie `%s'\n"
