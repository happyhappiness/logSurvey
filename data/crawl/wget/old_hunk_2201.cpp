msgid "Reusing existing connection to %s:%d.\n"
msgstr "Vil prøve å kontakte %s:%hu.\n"

#: src/http.c:1684
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr ""

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s forespørsel sendt, mottar topptekster... "

#: src/http.c:1760
#, fuzzy
msgid "No data received.\n"
msgstr "Ingen data mottatt"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lesefeil (%s) i topptekster.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, fuzzy, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr "File «%s» eksisterer allerede, ignoreres.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "Ukjent autorisasjons-protokoll.\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "Autorisasjon mislyktes\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "Feil i statuslinje"

#: src/http.c:2013
msgid "(no description)"
msgstr "(ingen beskrivelse)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "Sted: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "uspesifisert"

#: src/http.c:2078
msgid " [following]"
msgstr " [omdirigert]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:2164
msgid "Length: "
msgstr "Lengde: "

#: src/http.c:2184
msgid "ignored"
msgstr "ignoreres"

#: src/http.c:2255
#, fuzzy, c-format
msgid "Saving to: `%s'\n"
msgstr "Ignorerer katalog «%s».\n"
