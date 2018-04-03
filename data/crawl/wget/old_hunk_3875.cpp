#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:517
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr "%s: Upozorenje: reverzni lookup lokalne adrese ne daje FQDN!\n"

#: src/host.c:545
msgid "Host not found"
msgstr "Raèunalo nije pronaðeno"

#: src/host.c:547
msgid "Unknown error"
msgstr "Nepoznata gre¹ka"

#: src/html.c:615 src/html.c:617
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Indeks direktorija /%s na %s:%d"

#: src/html.c:639
msgid "time unknown       "
msgstr "nepoznato vrijeme    "

#: src/html.c:643
msgid "File        "
msgstr "Datoteka    "

#: src/html.c:646
msgid "Directory   "
msgstr "Direktorij  "

#: src/html.c:649
msgid "Link        "
msgstr "Link        "

#: src/html.c:652
msgid "Not sure    "
msgstr "Ne znam     "

#: src/html.c:670
#, c-format
msgid " (%s bytes)"
msgstr " (%s bajtova)"

#: src/http.c:508
msgid "Failed writing HTTP request.\n"
msgstr "Nisam uspio poslati HTTP zahtjev.\n"

#: src/http.c:512
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s zahtjev poslan, èekam odgovor... "

#: src/http.c:551
msgid "End of file while parsing headers.\n"
msgstr "Kraj datoteke za vrijeme obrade zaglavlja.\n"

#: src/http.c:562
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Gre¹ka pri èitanju zaglavlja (%s).\n"

#: src/http.c:602
msgid "No data received"
msgstr "Podaci nisu primljeni"

#: src/http.c:604
msgid "Malformed status line"
msgstr "Deformirana statusna linija"

#: src/http.c:609
msgid "(no description)"
msgstr "(bez opisa)"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:693
msgid "Authorization failed.\n"
msgstr "Ovjera nije uspjela.\n"

#: src/http.c:700
msgid "Unknown authentication scheme.\n"
msgstr "Nepoznata metoda ovjere.\n"

#: src/http.c:783
#, c-format
msgid "Location: %s%s\n"
msgstr "Polo¾aj: %s%s\n"

#: src/http.c:784 src/http.c:809
msgid "unspecified"
msgstr "neodreðen"

#: src/http.c:785
msgid " [following]"
msgstr " [pratim]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:799
msgid "Length: "
msgstr "Duljina: "

#: src/http.c:804
#, c-format
msgid " (%s to go)"
msgstr " (jo¹ %s)"

#: src/http.c:809
msgid "ignored"
msgstr "zanemarena"

#: src/http.c:912
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Upozorenje: wildcardi nisu podr¾ani za HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:933
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Datoteka `%s' veæ postoji, ne skidam.\n"

#: src/http.c:1099
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Ne mogu pisati u `%s' (%s).\n"

#: src/http.c:1110
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "GRE©KA: Redirekcija (%d) bez novog polo¾aja (location).\n"

#: src/http.c:1135
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s GRE©KA %d: %s.\n"

#: src/http.c:1148
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Nedostaje Last-Modified zaglavlje -- ignoriram vremensku oznaku.\n"

#: src/http.c:1156
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Nevaljan Last-Modified header -- ignoriram vremensku oznaku.\n"

#: src/http.c:1191
msgid "Remote file is newer, retrieving.\n"
msgstr "Datoteka na poslu¾itelju je novija, skidam.\n"

#: src/http.c:1226
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
