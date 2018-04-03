msgid "Unknown error"
msgstr "Errore sconosciuto"

#: src/http.c:621 src/http.c:1433
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:629
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Prover� a connettermi a %s:%hu.\n"

#: src/http.c:805
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Non riesco a scrivere la richiesta HTTP.\n"

#: src/http.c:810
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s richiesta inviata, aspetto la risposta... "

#: src/http.c:854
msgid "End of file while parsing headers.\n"
msgstr "Raggiunta la fine del file durante l'analisi degli header.\n"

#: src/http.c:865
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Errore di lettura degli header (%s).\n"

#: src/http.c:905
msgid "No data received"
msgstr "Nessun dato ricevuto"

#: src/http.c:907
msgid "Malformed status line"
msgstr "Riga di stato malformata"

#: src/http.c:912
msgid "(no description)"
msgstr "(nessuna descrizione)"

#: src/http.c:1030
msgid "Authorization failed.\n"
msgstr "Autorizzazione fallita.\n"

#: src/http.c:1037
msgid "Unknown authentication scheme.\n"
msgstr "Schema di autotentificazione sconosciuto.\n"

#: src/http.c:1127
#, c-format
msgid "Location: %s%s\n"
msgstr "Location: %s%s\n"

#: src/http.c:1128 src/http.c:1153
msgid "unspecified"
msgstr "non specificato"

#: src/http.c:1129
msgid " [following]"
msgstr " [segue]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1143
msgid "Length: "
msgstr "Lunghezza: "

#: src/http.c:1148
#, c-format
msgid " (%s to go)"
msgstr " (%s per finire)"

#: src/http.c:1153
msgid "ignored"
msgstr "ignorato"

#: src/http.c:1254
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Attenzione: le wildcard non sono supportate in HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1275
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Il file `%s' � gi� presente, non lo scarico.\n"

#: src/http.c:1425
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Non riesco a scrivere in `%s' (%s).\n"

#: src/http.c:1443
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERRORE: Redirezione (%d) senza posizione.\n"

#: src/http.c:1468
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERRORE %d: %s.\n"

#: src/http.c:1481
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Manca l'header last-modified -- date disattivate.\n"

#: src/http.c:1489
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Header last-modified non valido -- data ignorata.\n"

#: src/http.c:1524
msgid "Remote file is newer, retrieving.\n"
msgstr "Il file remoto � pi� recente, lo scarico.\n"

#: src/http.c:1559
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
