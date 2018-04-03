"FERDIG --%s--\n"
"Lastet ned %s bytes i %d filer\n"

#: src/main.c:842
#, c-format
msgid "Download quota (%s bytes) EXCEEDED!\n"
msgstr "Nedlastingskvote (%s bytes) overskredet!\n"

#. Please note that the double `%' in `%%s' is intentional, because
#. redirect_output passes tmp through printf.
#: src/main.c:876
#, c-format
msgid "%s received, redirecting output to `%%s'.\n"
msgstr "%s mottatt, omdirigerer utskrifter til «%%s».\n"

#: src/mswindows.c:89
#, c-format
msgid ""
"\n"
"CTRL+Break received, redirecting output to `%s'.\n"
"Execution continued in background.\n"
"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
msgstr ""
"\n"
"CTRL+Break mottatt, omdirigerer utskrifter til `%s'.\n"
"Kjøring fortsetter i bakgrunnen.\n"
"Du kan stoppe Wget ved å trykke CTRL+ALT+DELETE.\n"
"\n"

#. parent, no error
#: src/mswindows.c:106 src/utils.c:458
msgid "Continuing in background.\n"
msgstr "Fortsetter i bakgrunnen.\n"

#: src/mswindows.c:108 src/utils.c:460
#, c-format
msgid "Output will be written to `%s'.\n"
msgstr "Utskrifter vil bli skrevet til «%s».\n"

#: src/mswindows.c:188
#, c-format
msgid "Starting WinHelp %s\n"
msgstr "Starter WinHelp %s\n"

#: src/mswindows.c:215 src/mswindows.c:222
#, c-format
msgid "%s: Couldn't find usable socket driver.\n"
msgstr "%s: Fant ingen brukbar socket-driver.\n"

#: src/netrc.c:367
#, c-format
msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
msgstr "%s: %s:%d: Advarsel: symbolet «%s» funnet før tjener-navn\n"

#: src/netrc.c:398
#, c-format
msgid "%s: %s:%d: unknown token \"%s\"\n"
msgstr "%s: %s:%d: ukjent symbol «%s»\n"

#: src/netrc.c:462
#, c-format
msgid "Usage: %s NETRC [HOSTNAME]\n"
msgstr "Bruk: %s NETRC [TJENERNAVN]\n"

#: src/netrc.c:472
#, c-format
msgid "%s: cannot stat %s: %s\n"
msgstr "%s: «stat» feilet for %s: %s\n"

#: src/recur.c:484
#, c-format
msgid "Removing %s since it should be rejected.\n"
msgstr "Fjerner %s fordi den skal forkastes.\n"

#: src/recur.c:679
msgid "Loading robots.txt; please ignore errors.\n"
msgstr "Henter robots.txt; ignorer eventuelle feilmeldinger.\n"

#: src/retr.c:227
#, c-format
msgid "\n          [ skipping %dK ]"
msgstr "\n          [ hopper over %dK ]"

#: src/retr.c:373
msgid "Could not find proxy host.\n"
msgstr "Fant ikke proxy-tjener.\n"

#: src/retr.c:387
#, c-format
msgid "Proxy %s: Must be HTTP.\n"
msgstr "Proxy %s: Må støtte HTTP.\n"

#: src/retr.c:481
#, fuzzy, c-format
msgid "%s: Redirection cycle detected.\n"
msgstr "%s: Omdirigerer til seg selv.\n"

#: src/retr.c:587
msgid "Giving up.\n\n"
msgstr "Gir opp.\n\n"

#: src/retr.c:587
msgid "Retrying.\n\n"
msgstr "Prøver igjen.\n\n"

#: src/url.c:1329
#, c-format
msgid "Converting %s... "
msgstr "Konverterer %s... "

#: src/url.c:1342
msgid "nothing to do.\n"
msgstr ""

#: src/url.c:1350 src/url.c:1374
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "Kan ikke konvertere linker i %s: %s\n"

#: src/url.c:1365
#, fuzzy, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "Kan ikke slette den symbolske linken «%s»: %s\n"

#: src/url.c:1555
#, fuzzy, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "Kan ikke konvertere linker i %s: %s\n"

#: src/utils.c:94
#, c-format
msgid "%s: %s: Not enough memory.\n"
msgstr "%s: %s: Ikke nok minne.\n"

#: src/utils.c:417
msgid "Unknown/unsupported protocol"
msgstr "Protokollen er ukjent/ikke støttet"

#: src/utils.c:420
msgid "Invalid port specification"
msgstr "Port-spesifikasjonen er ugyldig"

#: src/utils.c:423
msgid "Invalid host name"
msgstr "Tjenernavnet er ugyldig"

#: src/utils.c:620
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr "Kan ikke slette den symbolske linken «%s»: %s\n"

#~ msgid "Local file `%s' is more recent, not retrieving.\n\n"
#~ msgstr "Lokal fil «%s» er samme/nyere, ignoreres.\n\n"

#~ msgid "%s: Cannot determine user-id.\n"
#~ msgstr "%s: Fant ikke bruker-ID.\n"
