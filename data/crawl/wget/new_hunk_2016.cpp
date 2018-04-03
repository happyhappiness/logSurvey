"Link simbolico già esistente %s -> %s\n"
"\n"

#: src/ftp.c:1494
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Creazione del link simbolico %s -> %s\n"

#: src/ftp.c:1504
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Link simbolici non gestiti, link \"%s\" saltato.\n"

#: src/ftp.c:1516
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Directory \"%s\" saltata.\n"

#: src/ftp.c:1525
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tipo di file sconosciuto/non gestito.\n"

#: src/ftp.c:1552
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: timestamp danneggiato.\n"

#: src/ftp.c:1580
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ""
"Le directory non verranno scaricate perché la loro profondità è %d (max %"
"d).\n"

#: src/ftp.c:1630
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Non si discende nella directory \"%s\" perché è esclusa/non inclusa.\n"

#: src/ftp.c:1696 src/ftp.c:1710
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "\"%s\" rifiutato.\n"

#: src/ftp.c:1733
#, fuzzy, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Errore scrivendo in \"%s\": %s.\n"

#: src/ftp.c:1774
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Nessun corrispondenza con il modello \"%s\".\n"

#: src/ftp.c:1840
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Indice in formato HTML scritto in \"%s\" [%s].\n"

#: src/ftp.c:1845
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Indice in formato HTML scritto in \"%s\".\n"

#: src/host.c:348
msgid "Unknown host"
msgstr "Host sconosciuto"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr "Risoluzione del nome temporaneamente fallita"

#: src/host.c:354
msgid "Unknown error"
msgstr "Errore sconosciuto"

#: src/host.c:715
#, c-format
msgid "Resolving %s... "
msgstr "Risoluzione di %s... "

#: src/host.c:762
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "fallito: nessun indirizzo IPv4/IPv6 per l'host.\n"

#: src/host.c:785
msgid "failed: timed out.\n"
msgstr "fallito: tempo scaduto.\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: impossibile risolvere il link incompleto %s.\n"

#: src/html-url.c:696
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: URL non valido %s: %s\n"

#: src/http.c:368
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Scrittura della richiesta HTTP non riuscita: %s.\n"

#: src/http.c:737
msgid "No headers, assuming HTTP/0.9"
msgstr "Nessuna intestazione, si assume HTTP/0.9"

#: src/http.c:1417
msgid "Disabling SSL due to encountered errors.\n"
msgstr "SSL disabilitato a causa di errori.\n"

#: src/http.c:1570
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "File di dati POST \"%s\" mancante: %s\n"

#: src/http.c:1619
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Riutilizzo della connessione esistente a %s:%d.\n"

#: src/http.c:1687
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Lettura della risposta del proxy non riuscita: %s.\n"

#: src/http.c:1707
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Proxy tunneling non riuscito: %s"

#: src/http.c:1752
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s richiesta inviata, in attesa di risposta... "

#: src/http.c:1763
msgid "No data received.\n"
msgstr "Nessun dato ricevuto.\n"

#: src/http.c:1770
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Errore di lettura nelle intestazioni (%s).\n"

#: src/http.c:1816 src/http.c:2368
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ""
"Il file \"%s\" è già presente, non viene scaricato.\n"
"\n"

#: src/http.c:1969
msgid "Unknown authentication scheme.\n"
msgstr "Schema di autotentificazione sconosciuto.\n"

#: src/http.c:2000
msgid "Authorization failed.\n"
msgstr "Autorizzazione fallita.\n"

#: src/http.c:2014
msgid "Malformed status line"
msgstr "Riga di stato malformata"

#: src/http.c:2016
msgid "(no description)"
msgstr "(nessuna descrizione)"

#: src/http.c:2082
#, c-format
msgid "Location: %s%s\n"
msgstr "Posizione: %s%s\n"

#: src/http.c:2083 src/http.c:2193
msgid "unspecified"
msgstr "non specificato"

#: src/http.c:2084
msgid " [following]"
msgstr " [segue]"

#: src/http.c:2140
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"    Il file è già interamente scaricato; niente da fare.\n"
"\n"

#: src/http.c:2173
msgid "Length: "
msgstr "Lunghezza: "

#: src/http.c:2193
msgid "ignored"
msgstr "ignorato"

#: src/http.c:2264
#, c-format
msgid "Saving to: `%s'\n"
msgstr "Salvataggio in: \"%s\"\n"

#: src/http.c:2345
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Attenzione: i metacaratteri non sono supportati in HTTP.\n"

#: src/http.c:2412
msgid "Spider mode enabled. Check if remote file exists.\n"
msgstr "Modalità spider abilitata. Controllare se il file remoto esiste.\n"

#: src/http.c:2497
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Impossibile scrivere in \"%s\" (%s).\n"

#: src/http.c:2506
msgid "Unable to establish SSL connection.\n"
msgstr "Impossibile stabilire una connessione SSL.\n"

#: src/http.c:2514
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERRORE: redirezione (%d) senza posizione di destinazione.\n"

# FIXME
#: src/http.c:2560
msgid "Remote file does not exist -- broken link!!!\n"
msgstr "Il file remoto non esiste -- collegamento rotto!!!\n"

#: src/http.c:2565
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERRORE %d: %s.\n"

#: src/http.c:2581
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Intestazione Last-modified mancante -- timestamp disattivati.\n"

#: src/http.c:2589
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Intestazione Last-modified non valido -- timestamp ignorato.\n"

# Perché "server file" e non "remote file"? C'è differenza?
#: src/http.c:2619
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"Il file del server è più vecchio del file locale \"%s\" -- non viene "
"scaricato.\n"

#: src/http.c:2627
#, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr "Le dimensioni non coincidono (locale %s) -- scaricamento in corso.\n"

#: src/http.c:2634
msgid "Remote file is newer, retrieving.\n"
msgstr "Il file remoto è più recente, scaricamento in corso.\n"

#: src/http.c:2650
msgid ""
"Remote file exists and could contain links to other resources -- "
"retrieving.\n"
