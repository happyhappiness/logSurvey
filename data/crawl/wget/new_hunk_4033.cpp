msgid "ignored"
msgstr "zanemarena"

#: src/http.c:858
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Upozorenje: wildcardi nisu podr�ani za HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:873
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Datoteka `%s' ve� postoji, ne skidam.\n"

#: src/http.c:1015
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Ne mogu pisati u `%s' (%s).\n"

#: src/http.c:1025
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "GRE�KA: Redirekcija (%d) bez novog polo�aja (location).\n"

#: src/http.c:1048
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s GRE�KA %d: %s.\n"

#: src/http.c:1060
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Nedostaje Last-Modified zaglavlje -- ignoriram vremensku oznaku.\n"

#: src/http.c:1068
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Nevaljan Last-Modified header -- ignoriram vremensku oznaku.\n"

#. We can't collapse this down into just one logprintf()
#. call with a variable set to u->local or the .orig
#. filename because we have to malloc() space for the
#. latter, and because there are multiple returns above (a
#. coding style no-no by many measures, for reasons such as
#. this) we'd have to remember to free() the string at each
#. one to avoid a memory leak.
#: src/http.c:1099
#, c-format
msgid ""
"Server file no newer than local file `%s.orig' -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:1113
msgid "Remote file is newer, retrieving.\n"
msgstr "Datoteka na poslu�itelju je novija, skidam.\n"

#: src/http.c:1147
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
