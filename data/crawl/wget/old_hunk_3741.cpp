msgid "Unknown error"
msgstr "Ukendt fejl"

#: src/http.c:621 src/http.c:1433
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:629
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Vil prøve at kontakte %s:%hu.\n"

#: src/http.c:805
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Fejl ved sending af HTTP-forespørgsel.\n"

#: src/http.c:810
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s forespørgsel sendt, modtager toptekster... "

#: src/http.c:854
msgid "End of file while parsing headers.\n"
msgstr "Filafslutning fundet ved læsning af toptekster.\n"

#: src/http.c:865
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Læsefejl (%s) i toptekster.\n"

#: src/http.c:905
msgid "No data received"
msgstr "Ingen data modtaget"

#: src/http.c:907
msgid "Malformed status line"
msgstr "Fejl i statuslinje"

#: src/http.c:912
msgid "(no description)"
msgstr "(ingen beskrivelse)"

#: src/http.c:1030
msgid "Authorization failed.\n"
msgstr "Autorisation mislykkedes\n"

#: src/http.c:1037
msgid "Unknown authentication scheme.\n"
msgstr "Ukendt autorisations-protokol.\n"

#: src/http.c:1127
#, c-format
msgid "Location: %s%s\n"
msgstr "Sted: %s%s\n"

#: src/http.c:1128 src/http.c:1153
msgid "unspecified"
msgstr "uangivet"

#: src/http.c:1129
msgid " [following]"
msgstr " [omdirigeret]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1143
msgid "Length: "
msgstr "Længde: "

#: src/http.c:1148
#, c-format
msgid " (%s to go)"
msgstr " (%s tilbage)"

#: src/http.c:1153
msgid "ignored"
msgstr "ignoreret"

#: src/http.c:1254
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Advarsel: jokertegn ikke understøttet i HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1275
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Filen '%s' hentes ikke, fordi den allerede eksisterer.\n"

#: src/http.c:1425
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kan ikke skrive til '%s' (%s).\n"

#: src/http.c:1443
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEJL: Omdirigering (%d) uden nyt sted.\n"

#: src/http.c:1468
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEJL %d: %s.\n"

#: src/http.c:1481
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified toptekst mangler -- tidsstempling slås fra.\n"

#: src/http.c:1489
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified toptekst ugyldig -- tidsstempel ignoreret.\n"

#: src/http.c:1524
msgid "Remote file is newer, retrieving.\n"
msgstr "Fil på tjener er nyere - hentes.\n"

#: src/http.c:1559
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
