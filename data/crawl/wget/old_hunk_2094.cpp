"Link simbolico già esistente %s -> %s\n"
"\n"

#: src/ftp.c:1493
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Creazione del link simbolico %s -> %s\n"

#: src/ftp.c:1503
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Link simbolici non gestiti, link \"%s\" ignorato.\n"

#: src/ftp.c:1515
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Directory \"%s\" ignorata.\n"

#: src/ftp.c:1524
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tipo di file sconosciuto/non gestito.\n"

#: src/ftp.c:1551
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: timestamp danneggiato.\n"

#: src/ftp.c:1579
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ""
"Le directory non verranno scaricate perché la loro profondità è %d (max %"
"d).\n"

#: src/ftp.c:1629
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Non scendo nella directory \"%s\" perché è esclusa/non inclusa.\n"

#: src/ftp.c:1695 src/ftp.c:1709
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "\"%s\" rifiutato.\n"

#: src/ftp.c:1757
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Nessun corrispondenza con il modello \"%s\".\n"

#: src/ftp.c:1823
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Indice in formato HTML scritto in \"%s\" [%s].\n"

#: src/ftp.c:1828
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Indice in formato HTML scritto in \"%s\".\n"

#: src/host.c:347
msgid "Unknown host"
msgstr "Host sconosciuto"

#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr "Risoluzione del nome fallita temporaneamente"

#: src/host.c:353
msgid "Unknown error"
msgstr "Errore sconosciuto"

#: src/host.c:714
#, c-format
msgid "Resolving %s... "
msgstr "Risoluzione di %s in corso... "

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "fallito: nessun indirizzo IPv4/IPv6 per l'host.\n"

#: src/host.c:784
msgid "failed: timed out.\n"
msgstr "fallito: tempo scaduto.\n"

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: impossibile risolvere il link incompleto %s.\n"

#: src/html-url.c:695
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: URL non valido %s: %s\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Scrittura della richiesta HTTP non riuscita: %s.\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr "Nessun header, si assume HTTP/0.9"

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr "SSL disabilitato a causa di errori.\n"

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "File di dati POST \"%s\" mancante: %s\n"

#: src/http.c:1615
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Riutilizzo della connessione esistente a %s:%d.\n"

#: src/http.c:1683
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Lettura della risposta del proxy non riuscita: %s.\n"

#: src/http.c:1703
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Proxy tunneling non riuscito: %s"

#: src/http.c:1748
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s richiesta inviata, aspetto la risposta... "

#: src/http.c:1759
msgid "No data received.\n"
msgstr "Nessun dato ricevuto.\n"

#: src/http.c:1766
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Errore di lettura degli header (%s).\n"

#: src/http.c:1812
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ""
"Il file \"%s\" esiste già, scaricamento non effettuato.\n"
"\n"

#: src/http.c:1965
msgid "Unknown authentication scheme.\n"
msgstr "Schema di autotentificazione sconosciuto.\n"

#: src/http.c:1996
msgid "Authorization failed.\n"
msgstr "Autorizzazione fallita.\n"

#: src/http.c:2010
msgid "Malformed status line"
msgstr "Riga di stato malformata"

#: src/http.c:2012
msgid "(no description)"
msgstr "(nessuna descrizione)"

#: src/http.c:2075
#, c-format
msgid "Location: %s%s\n"
msgstr "Posizione: %s%s\n"

#: src/http.c:2076 src/http.c:2183
msgid "unspecified"
msgstr "non specificato"

#: src/http.c:2077
msgid " [following]"
msgstr " [segue]"

#: src/http.c:2133
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"    Il file è già completamente scaricato; niente da fare.\n"
"\n"

#: src/http.c:2163
msgid "Length: "
msgstr "Lunghezza: "

#: src/http.c:2183
msgid "ignored"
msgstr "ignorato"

#: src/http.c:2254
#, c-format
msgid "Saving to: `%s'\n"
msgstr "Salvataggio in: \"%s\"\n"

#: src/http.c:2335
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Attenzione: i metacaratteri non sono supportati in HTTP.\n"

#: src/http.c:2382
msgid "Spider mode enabled. Check if remote file exists.\n"
msgstr "Modalità spider abilitata. Controllare se il file remoto esiste.\n"

#: src/http.c:2467
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Impossibile scrivere in \"%s\" (%s).\n"

#: src/http.c:2476
msgid "Unable to establish SSL connection.\n"
msgstr "Impossibile stabilire una connessione SSL.\n"

#: src/http.c:2484
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERRORE: redirezione (%d) senza posizione.\n"

# FIXME
#: src/http.c:2530
msgid "Remote file does not exist -- broken link!!!\n"
msgstr "Il file remoto non esiste -- collegamento rotto!!!\n"

#: src/http.c:2535
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERRORE %d: %s.\n"

#: src/http.c:2551
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Header Last-modified mancante -- date disattivate.\n"

#: src/http.c:2559
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Header Last-modified non valido -- data ignorata.\n"

# Perché "server file" e non "remote file"? C'è differenza?
#: src/http.c:2589
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"Il file del server è più vecchio del file locale \"%s\" -- scaricamento non "
"effettuato.\n"

#: src/http.c:2597
#, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr "Le dimensioni non coincidono (locale %s) -- scaricamento in corso.\n"

#: src/http.c:2604
msgid "Remote file is newer, retrieving.\n"
msgstr "Il file remoto è più recente, scaricamento in corso.\n"

#: src/http.c:2620
msgid ""
"Remote file exists and could contain links to other resources -- "
"retrieving.\n"
