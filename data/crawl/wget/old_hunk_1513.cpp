msgid "Failed writing HTTP request: %s.\n"
msgstr "Feil ved sending av HTTP-forespørsel.\n"

#: src/http.c:737
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1417
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1570
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr ""

#: src/http.c:1619
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Vil prøve å kontakte %s:%hu.\n"

#: src/http.c:1687
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr ""

#: src/http.c:1707
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1752
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s forespørsel sendt, mottar topptekster... "

#: src/http.c:1763
#, fuzzy
msgid "No data received.\n"
msgstr "Ingen data mottatt"

#: src/http.c:1770
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lesefeil (%s) i topptekster.\n"

#: src/http.c:1816 src/http.c:2368
#, fuzzy, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr "File «%s» eksisterer allerede, ignoreres.\n"

#: src/http.c:1969
msgid "Unknown authentication scheme.\n"
msgstr "Ukjent autorisasjons-protokoll.\n"

#: src/http.c:2000
msgid "Authorization failed.\n"
msgstr "Autorisasjon mislyktes\n"

#: src/http.c:2014
msgid "Malformed status line"
msgstr "Feil i statuslinje"

#: src/http.c:2016
msgid "(no description)"
msgstr "(ingen beskrivelse)"

#: src/http.c:2082
#, c-format
msgid "Location: %s%s\n"
msgstr "Sted: %s%s\n"

#: src/http.c:2083 src/http.c:2193
msgid "unspecified"
msgstr "uspesifisert"

#: src/http.c:2084
msgid " [following]"
msgstr " [omdirigert]"

#: src/http.c:2140
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""

#: src/http.c:2173
msgid "Length: "
msgstr "Lengde: "

#: src/http.c:2193
msgid "ignored"
msgstr "ignoreres"

#: src/http.c:2264
#, fuzzy, c-format
msgid "Saving to: `%s'\n"
msgstr "Ignorerer katalog «%s».\n"

#: src/http.c:2345
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Advarsel: jokertegn ikke støttet i HTTP.\n"

#: src/http.c:2412
msgid "Spider mode enabled. Check if remote file exists.\n"
msgstr ""

#: src/http.c:2497
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kan ikke skrive til «%s» (%s).\n"

#: src/http.c:2506
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:2514
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEIL: Omdirigering (%d) uten nytt sted.\n"

#: src/http.c:2560
msgid "Remote file does not exist -- broken link!!!\n"
msgstr ""

#: src/http.c:2565
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEIL %d: %s.\n"

#: src/http.c:2581
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified topptekst mangler -- tidsstempling slås av.\n"

#: src/http.c:2589
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified topptekst ugyldig -- tidsstempel ignoreres.\n"

#: src/http.c:2619
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:2627
#, fuzzy, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr "Filstørrelsene er forskjellige (local %ld), hentes.\n"

#: src/http.c:2634
msgid "Remote file is newer, retrieving.\n"
msgstr "Fil på tjener er nyere - hentes.\n"

#: src/http.c:2650
msgid ""
"Remote file exists and could contain links to other resources -- "
"retrieving.\n"
"\n"
msgstr ""

#: src/http.c:2655
msgid ""
"Remote file exists but does not contain any link -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:2663
#, fuzzy
msgid ""
"Remote file exists but recursion is disabled -- not retrieving.\n"
"\n"
msgstr "Fil på tjener er nyere - hentes.\n"

#: src/http.c:2715
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s]\n"
"\n"
msgstr ""
"%s (%s) - «%s» lagret [%ld/%ld]\n"
"\n"

#: src/http.c:2770
#, fuzzy, c-format
msgid "%s (%s) - Connection closed at byte %s. "
msgstr "%s (%s) - Forbindelse brutt ved byte %ld. "

#: src/http.c:2785
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s (%s)."
msgstr "%s (%s) - Lesefeil ved byte %ld (%s)."

#: src/http.c:2794
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s/%s (%s). "
msgstr "%s (%s) - Lesefeil ved byte %ld/%ld (%s)."

#: src/init.c:387
#, c-format
msgid "%s: WGETRC points to %s, which doesn't exist.\n"
msgstr ""

#: src/init.c:450 src/netrc.c:265
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Kan ikke lese %s (%s).\n"

#: src/init.c:468
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Feil i %s på linje %d.\n"

#: src/init.c:474
#, fuzzy, c-format
msgid "%s: Syntax error in %s at line %d.\n"
msgstr "%s: Feil i %s på linje %d.\n"

#: src/init.c:479
#, fuzzy, c-format
msgid "%s: Unknown command `%s' in %s at line %d.\n"
msgstr "%s: Ukjent kommando «%s», verdi «%s».\n"

#: src/init.c:524
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Advarsel: Både systemets og brukerens wgetrc peker til «%s».\n"

#: src/init.c:677
#, fuzzy, c-format
msgid "%s: Invalid --execute command `%s'\n"
msgstr "%s: Ugyldig spesifikasjon «%s»\n"

#: src/init.c:722
#, fuzzy, c-format
msgid "%s: %s: Invalid boolean `%s'; use `on' or `off'.\n"
msgstr "%s: %s: Vennligst spesifiser «on» eller «off».\n"

#: src/init.c:739
#, fuzzy, c-format
msgid "%s: %s: Invalid number `%s'.\n"
msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"

#: src/init.c:970 src/init.c:989
#, fuzzy, c-format
msgid "%s: %s: Invalid byte value `%s'\n"
msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"

#: src/init.c:1014
#, fuzzy, c-format
msgid "%s: %s: Invalid time period `%s'\n"
msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"

#: src/init.c:1068 src/init.c:1158 src/init.c:1261 src/init.c:1286
#, fuzzy, c-format
msgid "%s: %s: Invalid value `%s'.\n"
msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"

#: src/init.c:1105
#, fuzzy, c-format
msgid "%s: %s: Invalid header `%s'.\n"
msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"

#: src/init.c:1171
#, fuzzy, c-format
msgid "%s: %s: Invalid progress type `%s'.\n"
msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"

#: src/init.c:1230
#, c-format
msgid ""
"%s: %s: Invalid restriction `%s', use [unix|windows],[lowercase|uppercase],"
"[nocontrol].\n"
msgstr ""

