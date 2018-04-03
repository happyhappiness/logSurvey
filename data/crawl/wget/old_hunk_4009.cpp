msgid " (%s bytes)"
msgstr " (%s bytes)"

#: src/http.c:507
msgid "Failed writing HTTP request.\n"
msgstr "Feil ved sending av HTTP-forespørsel.\n"

#: src/http.c:511
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s forespørsel sendt, mottar topptekster... "

#: src/http.c:550
msgid "End of file while parsing headers.\n"
msgstr "Filslutt funnet ved lesing av topptekster.\n"

#: src/http.c:561
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lesefeil (%s) i topptekster.\n"

#: src/http.c:601
msgid "No data received"
msgstr "Ingen data mottatt"

#: src/http.c:603
msgid "Malformed status line"
msgstr "Feil i statuslinje"

#: src/http.c:608
msgid "(no description)"
msgstr "(ingen beskrivelse)"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:692
msgid "Authorization failed.\n"
msgstr "Autorisasjon mislyktes\n"

#: src/http.c:699
msgid "Unknown authentication scheme.\n"
msgstr "Ukjent autorisasjons-protokoll.\n"

#: src/http.c:762
#, c-format
msgid "Location: %s%s\n"
msgstr "Sted: %s%s\n"

#: src/http.c:763 src/http.c:788
msgid "unspecified"
msgstr "uspesifisert"

#: src/http.c:764
msgid " [following]"
msgstr " [omdirigert]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:778
msgid "Length: "
msgstr "Lengde: "

#: src/http.c:783
#, c-format
msgid " (%s to go)"
msgstr " (%s igjen)"

#: src/http.c:788
msgid "ignored"
msgstr "ignoreres"

#: src/http.c:880
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Advarsel: jokertegn ikke støttet i HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:895
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Filen «%s» hentes ikke, fordi den allerede eksisterer.\n"

#: src/http.c:1048
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kan ikke skrive til «%s» (%s).\n"

#: src/http.c:1058
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEIL: Omdirigering (%d) uten nytt sted.\n"

#: src/http.c:1081
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEIL %d: %s.\n"

#: src/http.c:1093
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified topptekst mangler -- tidsstempling slås av.\n"

#: src/http.c:1101
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified topptekst ugyldig -- tidsstempel ignoreres.\n"

#. We can't collapse this down into just one logprintf()
#. call with a variable set to u->local or the .orig
#. filename because we have to malloc() space for the
#. latter, and because there are multiple returns above (a
#. coding style no-no by many measures, for reasons such as
#. this) we'd have to remember to free() the string at each
#. one to avoid a memory leak.
#: src/http.c:1132
#, c-format
msgid ""
"Server file no newer than local file `%s.orig' -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:1146
msgid "Remote file is newer, retrieving.\n"
msgstr "Fil på tjener er nyere - hentes.\n"

#: src/http.c:1180
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
