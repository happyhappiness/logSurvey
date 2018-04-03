#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:516
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""
"%s: Advarsel: fikk ikke FQDN fra tilbake-oppslag for lokal IP-adresse!\n"

#: src/host.c:544
msgid "Host not found"
msgstr "Tjener ikke funnet"

#: src/host.c:546
msgid "Unknown error"
msgstr "Ukjent feil"

#: src/html.c:615 src/html.c:617
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Indeks for /%s på %s:%d"

#: src/html.c:639
msgid "time unknown       "
msgstr "ukjent tid         "

#: src/html.c:643
msgid "File        "
msgstr "Fil         "

#: src/html.c:646
msgid "Directory   "
msgstr "Katalog     "

#: src/html.c:649
msgid "Link        "
msgstr "Link        "

#: src/html.c:652
msgid "Not sure    "
msgstr "Usikker     "

#: src/html.c:670
#, c-format
msgid " (%s bytes)"
msgstr " (%s bytes)"

#: src/http.c:508
msgid "Failed writing HTTP request.\n"
msgstr "Feil ved sending av HTTP-forespørsel.\n"

#: src/http.c:512
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s forespørsel sendt, mottar topptekster... "

#: src/http.c:551
msgid "End of file while parsing headers.\n"
msgstr "Filslutt funnet ved lesing av topptekster.\n"

#: src/http.c:562
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lesefeil (%s) i topptekster.\n"

#: src/http.c:602
msgid "No data received"
msgstr "Ingen data mottatt"

#: src/http.c:604
msgid "Malformed status line"
msgstr "Feil i statuslinje"

#: src/http.c:609
msgid "(no description)"
msgstr "(ingen beskrivelse)"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:693
msgid "Authorization failed.\n"
msgstr "Autorisasjon mislyktes\n"

#: src/http.c:700
msgid "Unknown authentication scheme.\n"
msgstr "Ukjent autorisasjons-protokoll.\n"

#: src/http.c:783
#, c-format
msgid "Location: %s%s\n"
msgstr "Sted: %s%s\n"

#: src/http.c:784 src/http.c:809
msgid "unspecified"
msgstr "uspesifisert"

#: src/http.c:785
msgid " [following]"
msgstr " [omdirigert]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:799
msgid "Length: "
msgstr "Lengde: "

#: src/http.c:804
#, c-format
msgid " (%s to go)"
msgstr " (%s igjen)"

#: src/http.c:809
msgid "ignored"
msgstr "ignoreres"

#: src/http.c:912
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Advarsel: jokertegn ikke støttet i HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:933
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Filen «%s» hentes ikke, fordi den allerede eksisterer.\n"

#: src/http.c:1099
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kan ikke skrive til «%s» (%s).\n"

#: src/http.c:1110
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEIL: Omdirigering (%d) uten nytt sted.\n"

#: src/http.c:1135
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEIL %d: %s.\n"

#: src/http.c:1148
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified topptekst mangler -- tidsstempling slås av.\n"

#: src/http.c:1156
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified topptekst ugyldig -- tidsstempel ignoreres.\n"

#: src/http.c:1191
msgid "Remote file is newer, retrieving.\n"
msgstr "Fil på tjener er nyere - hentes.\n"

#: src/http.c:1226
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""
"%s (%s) - «%s» lagret [%ld/%ld]\n"
"\n"

#: src/http.c:1274
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Forbindelse brutt ved byte %ld. "

#: src/http.c:1282
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - «%s» lagret [%ld/%ld]\n"
"\n"

#: src/http.c:1302
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Forbindelse brutt ved byte %ld/%ld. "

#: src/http.c:1313
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Lesefeil ved byte %ld (%s)."

#: src/http.c:1321
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Lesefeil ved byte %ld/%ld (%s)."

#: src/init.c:329 src/netrc.c:260
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Kan ikke lese %s (%s).\n"

#: src/init.c:350 src/init.c:356
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Feil i %s på linje %d.\n"

#: src/init.c:387
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Advarsel: Både systemets og brukerens wgetrc peker til «%s».\n"

#: src/init.c:475
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: Ukjent kommando «%s», verdi «%s».\n"

#: src/init.c:497
#, fuzzy, c-format
msgid "%s: Out of memory.\n"
msgstr "%s: %s: Ikke nok minne.\n"

#: src/init.c:503
#, fuzzy, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: Advarsel: feil fra tilbake-oppslag for lokal IP-adresse.\n"

#: src/init.c:531
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Vennligst spesifiser «on» eller «off».\n"

#: src/init.c:575
#, fuzzy, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Vennligst spesifiser «on» eller «off».\n"

#: src/init.c:594 src/init.c:851 src/init.c:873 src/init.c:937
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"

#: src/init.c:707 src/init.c:729 src/init.c:751 src/init.c:777
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Ugyldig spesifikasjon «%s»\n"

#: src/main.c:105
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Bruk: %s [FLAGG]... [URL]...\n"

#: src/main.c:113
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, en ikke-interaktiv informasjonsagent.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:118
msgid ""
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Obligatoriske argumenter til lange flagg er obligatoriske også \n"
"for korte.\n"
"\n"

#: src/main.c:121
#, fuzzy
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
"  -h,  --help              print this help.\n"
"  -b,  --background        go to background after startup.\n"
"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
"\n"
msgstr ""
"Oppstart:\n"
