#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1777
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Nessun corrispondenza con il modello \"%s\".\n"

#: src/ftp.c:1843
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Indice in formato HTML scritto in \"%s\" [%s].\n"

#: src/ftp.c:1848
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Indice in formato HTML scritto in \"%s\".\n"

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: l'opzione \"%s\" è ambigua\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: l'opzione \"--%s\" non accetta argomenti\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: l'opzione \"%c%s\" non accetta argomenti\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: l'opzione \"%s\" richiede un argomento\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: opzione \"--%s\" non riconosciuta\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: opzione \"%c%s\" non riconosciuta\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: opzione illecita -- %c\n"

#: src/getopt.c:785
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: opzione non valida -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: l'opzione richiede un argomento -- %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: l'opzione \"-W %s\" è ambigua\n"

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: l'opzione \"-W %s\" non accetta argomenti\n"

#: src/host.c:366
msgid "Unknown host"
msgstr "Host sconosciuto"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:370
msgid "Temporary failure in name resolution"
msgstr "Risoluzione del nome fallita temporaneamente"

#: src/host.c:372
msgid "Unknown error"
msgstr "Errore sconosciuto"

#: src/host.c:751
#, c-format
msgid "Resolving %s... "
msgstr "Risoluzione di %s in corso... "

#: src/host.c:798
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "fallito: nessun indirizzo IPv4/IPv6 per l'host.\n"

#: src/host.c:821
msgid "failed: timed out.\n"
msgstr "fallito: tempo scaduto.\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: impossibile risolvere il link incompleto %s.\n"

#: src/html-url.c:705
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: URL non valido %s: %s\n"

#: src/http.c:373
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Scrittura della richiesta HTTP non riuscita: %s.\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr "Nessun header, si assume HTTP/0.9"

#: src/http.c:1204
msgid "Disabling SSL due to encountered errors.\n"
msgstr "SSL disabilitato a causa di errori.\n"

#: src/http.c:1374
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "File di dati POST \"%s\" mancante: %s\n"

#: src/http.c:1423
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Riutilizzo della connessione esistente a %s:%d.\n"

#: src/http.c:1492
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Lettura della risposta del proxy non riuscita: %s.\n"

#: src/http.c:1512
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Proxy tunneling non riuscito: %s"

#: src/http.c:1557
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s richiesta inviata, aspetto la risposta... "

#: src/http.c:1568
msgid "No data received.\n"
msgstr "Nessun dato ricevuto.\n"

#: src/http.c:1575
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Errore di lettura degli header (%s).\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1660
msgid "Unknown authentication scheme.\n"
msgstr "Schema di autotentificazione sconosciuto.\n"

#: src/http.c:1684
msgid "Authorization failed.\n"
msgstr "Autorizzazione fallita.\n"

#: src/http.c:1698
msgid "Malformed status line"
msgstr "Riga di stato malformata"

#: src/http.c:1700
msgid "(no description)"
msgstr "(nessuna descrizione)"

#: src/http.c:1763
#, c-format
msgid "Location: %s%s\n"
msgstr "Posizione: %s%s\n"

#: src/http.c:1764 src/http.c:1871
msgid "unspecified"
msgstr "non specificato"

#: src/http.c:1765
msgid " [following]"
msgstr " [segue]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1821
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
