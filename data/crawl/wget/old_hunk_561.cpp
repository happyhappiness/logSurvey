"Har allerede gyldig symbolsk link %s -> %s\n"
"\n"

#: src/ftp.c:1533
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Lager symbolsk link %s -> %s\n"

#: src/ftp.c:1543
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr "Symbolske linker ikke støttet, ignorerer «%s».\n"

#: src/ftp.c:1555
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "Ignorerer katalog «%s».\n"

#: src/ftp.c:1564
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: filtypen er ukjent/ikke støttet.\n"

#: src/ftp.c:1591
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: ugyldig tidsstempel.\n"

#: src/ftp.c:1619
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Henter ikke kataloger på dybde %d (max %d).\n"

#: src/ftp.c:1669
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "Behandler ikke «%s» da det er ekskludert/ikke inkludert.\n"

#: src/ftp.c:1735 src/ftp.c:1749
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "Ignorerer «%s».\n"

#: src/ftp.c:1772
#, c-format
msgid "Error matching %s against %s: %s\n"
msgstr ""

#: src/ftp.c:1814
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Ingenting passer med mønsteret «%s».\n"

#: src/ftp.c:1880
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "Skrev HTML-formattert indeks til «%s» [%ld].\n"

#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "Skrev HTML-formattert indeks til «%s».\n"

#: src/host.c:348
#, fuzzy
msgid "Unknown host"
msgstr "Ukjent feil"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:354
msgid "Unknown error"
msgstr "Ukjent feil"

#: src/host.c:715
#, fuzzy, c-format
msgid "Resolving %s... "
msgstr "Fjerner %s.\n"

#: src/host.c:763
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:786
msgid "failed: timed out.\n"
msgstr ""

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr ""

#: src/html-url.c:696
#, fuzzy, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: Ugyldig spesifikasjon «%s»\n"

#: src/http.c:368
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Feil ved sending av HTTP-forespørsel.\n"

#: src/http.c:745
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1430
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1548
#, c-format
msgid "POST data file %s missing: %s\n"
msgstr ""

#: src/http.c:1632
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Vil prøve å kontakte %s:%hu.\n"

#: src/http.c:1701
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr ""

#: src/http.c:1721
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1766
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s forespørsel sendt, mottar topptekster... "

#: src/http.c:1777
#, fuzzy
msgid "No data received.\n"
msgstr "Ingen data mottatt"

#: src/http.c:1784
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lesefeil (%s) i topptekster.\n"

#: src/http.c:1831 src/http.c:2385
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
"\n"
msgstr "File «%s» eksisterer allerede, ignoreres.\n"

#: src/http.c:1985
msgid "Unknown authentication scheme.\n"
msgstr "Ukjent autorisasjons-protokoll.\n"

#: src/http.c:2016
msgid "Authorization failed.\n"
msgstr "Autorisasjon mislyktes\n"

#: src/http.c:2030
msgid "Malformed status line"
msgstr "Feil i statuslinje"

#: src/http.c:2032
msgid "(no description)"
msgstr "(ingen beskrivelse)"

#: src/http.c:2098
#, c-format
msgid "Location: %s%s\n"
msgstr "Sted: %s%s\n"

#: src/http.c:2099 src/http.c:2209
msgid "unspecified"
msgstr "uspesifisert"

#: src/http.c:2100
msgid " [following]"
msgstr " [omdirigert]"

#: src/http.c:2156
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""

#: src/http.c:2189
msgid "Length: "
msgstr "Lengde: "

#: src/http.c:2209
msgid "ignored"
msgstr "ignoreres"

#: src/http.c:2280
#, c-format
msgid "Saving to: %s\n"
msgstr ""

#: src/http.c:2361
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Advarsel: jokertegn ikke støttet i HTTP.\n"

#: src/http.c:2430
msgid "Spider mode enabled. Check if remote file exists.\n"
msgstr ""

#: src/http.c:2515
#, fuzzy, c-format
msgid "Cannot write to %s (%s).\n"
msgstr "Kan ikke skrive til «%s» (%s).\n"

#: src/http.c:2524
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:2532
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEIL: Omdirigering (%d) uten nytt sted.\n"

#: src/http.c:2578
msgid "Remote file does not exist -- broken link!!!\n"
msgstr ""

#: src/http.c:2583
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEIL %d: %s.\n"

#: src/http.c:2600
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified topptekst mangler -- tidsstempling slås av.\n"

#: src/http.c:2608
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified topptekst ugyldig -- tidsstempel ignoreres.\n"

#: src/http.c:2638
#, c-format
msgid ""
"Server file no newer than local file %s -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:2646
#, fuzzy, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr "Filstørrelsene er forskjellige (local %ld), hentes.\n"

#: src/http.c:2653
msgid "Remote file is newer, retrieving.\n"
msgstr "Fil på tjener er nyere - hentes.\n"

#: src/http.c:2669
msgid ""
"Remote file exists and could contain links to other resources -- "
"retrieving.\n"
"\n"
msgstr ""

#: src/http.c:2674
msgid ""
"Remote file exists but does not contain any link -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:2684
msgid ""
"Remote file exists and could contain further links,\n"
"but recursion is disabled -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:2690
#, fuzzy
msgid ""
"Remote file exists.\n"
"\n"
msgstr "Fil på tjener er nyere - hentes.\n"

#: src/http.c:2743
#, fuzzy, c-format
msgid ""
"%s (%s) - %s saved [%s/%s]\n"
