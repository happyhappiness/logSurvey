msgid "Unknown error"
msgstr "Nepoznata gre¹ka"

#: src/http.c:625 src/http.c:1437
msgid "Unable to establish SSL connection.\n"
msgstr "Ne mogu uspostaviti SSL vezu.\n"

#: src/http.c:633
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Koristim postojeæu vezu prema %s:%hu.\n"

#: src/http.c:809
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Nisam uspio poslati HTTP zahtjev: %s.\n"

#: src/http.c:814
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s zahtjev poslan, èekam odgovor... "

#: src/http.c:858
msgid "End of file while parsing headers.\n"
msgstr "Kraj datoteke za vrijeme obrade zaglavlja.\n"

#: src/http.c:869
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Gre¹ka pri èitanju zaglavlja (%s).\n"

#: src/http.c:909
msgid "No data received"
msgstr "Podaci nisu primljeni"

#: src/http.c:911
msgid "Malformed status line"
msgstr "Deformirana statusna linija"

#: src/http.c:916
msgid "(no description)"
msgstr "(bez opisa)"

#: src/http.c:1034
msgid "Authorization failed.\n"
msgstr "Ovjera nije uspjela.\n"

#: src/http.c:1041
msgid "Unknown authentication scheme.\n"
msgstr "Nepoznata metoda ovjere.\n"

#: src/http.c:1131
#, c-format
msgid "Location: %s%s\n"
msgstr "Polo¾aj: %s%s\n"

#: src/http.c:1132 src/http.c:1157
msgid "unspecified"
msgstr "neodreðen"

#: src/http.c:1133
msgid " [following]"
msgstr " [pratim]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1147
msgid "Length: "
msgstr "Duljina: "

#: src/http.c:1152
#, c-format
msgid " (%s to go)"
msgstr " (jo¹ %s)"

#: src/http.c:1157
msgid "ignored"
msgstr "zanemarena"

#: src/http.c:1258
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Upozorenje: wildcardi nisu podr¾ani za HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1279
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Datoteka `%s' veæ postoji, ne skidam.\n"

#: src/http.c:1429
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Ne mogu pisati u `%s' (%s).\n"

#: src/http.c:1447
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "GRE©KA: Redirekcija (%d) bez novog polo¾aja (location).\n"

#: src/http.c:1472
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s GRE©KA %d: %s.\n"

#: src/http.c:1485
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Nedostaje Last-Modified zaglavlje -- ignoriram vremensku oznaku.\n"

#: src/http.c:1493
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Nevaljan Last-Modified header -- ignoriram vremensku oznaku.\n"

#: src/http.c:1528
msgid "Remote file is newer, retrieving.\n"
msgstr "Datoteka na poslu¾itelju je novija, skidam.\n"

#: src/http.c:1573
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
