"Lien symbolique déjà correct %s -> %s\n"
"\n"

#: src/ftp.c:1533
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Création du lien symbolique %s -> %s\n"

#: src/ftp.c:1543
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr "Lien symbolique non supporté, escamotage du lien « %s ».\n"

#: src/ftp.c:1555
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "Répertoire « %s » escamoté.\n"

#: src/ftp.c:1564
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: type de fichier inconnu ou non supporté.\n"

#: src/ftp.c:1591
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: tampon date-heure corrompu.\n"

#: src/ftp.c:1619
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ""
"Les répertoires ne seront pas récupérés, la profondeur %d dépasse le maximum "
"%d.\n"

#: src/ftp.c:1669
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "%s n'a pas été parcouru puisqu'il est exclu ou non inclus.\n"

#: src/ftp.c:1735 src/ftp.c:1749
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "Rejet de « %s ».\n"

#: src/ftp.c:1772
#, fuzzy, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Ne peut écrire dans « %s »: %s\n"

#: src/ftp.c:1814
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Pas de concordance avec le patron « %s ».\n"

#: src/ftp.c:1880
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "Index HTML-isé écrit dans « %s » [%s].\n"

#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "Index HTML-isé écrit dans « %s ».\n"

#: src/host.c:348
msgid "Unknown host"
msgstr "Hôte inconnu"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr "?chec temporaire dans la résolution du nom"

#: src/host.c:354
msgid "Unknown error"
msgstr "ERREUR inconnue"

#: src/host.c:715
#, c-format
msgid "Resolving %s... "
msgstr "Résolution de %s... "

#: src/host.c:763
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "échec: pas d'adresses IPv4/IPv6 pour l'hôte.\n"

#: src/host.c:786
msgid "failed: timed out.\n"
msgstr "échec: expiration de la minuterie\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: ne peut résoudre le lien incomplet %s.\n"

#: src/html-url.c:696
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: URL invalide %s: %s\n"

#: src/http.c:368
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "ÉCHEC d'écriture de la requête HTTP: %s.\n"

#: src/http.c:745
msgid "No headers, assuming HTTP/0.9"
msgstr "Pas d'en-tête, HTTP/0.9 assumé"

#: src/http.c:1430
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Désactivation SSL en raison des erreurs rencontrés.\n"

#: src/http.c:1548
#, fuzzy, c-format
msgid "POST data file %s missing: %s\n"
msgstr "Fichier de données POST `%s' est manquant: %s\n"

#: src/http.c:1632
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Réutilisation de la connexion existante vers %s:%d.\n"

#: src/http.c:1701
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "ÉCHEC de lecture de la réponse proxy: %s.\n"

#: src/http.c:1721
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Échec du tunneling proxy: %s"

#: src/http.c:1766
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "requête %s transmise, en attente de la réponse..."

#: src/http.c:1777
msgid "No data received.\n"
msgstr "Aucune donnée reçue.\n"

#: src/http.c:1784
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ERREUR de lecture (%s) de l'en-tête.\n"

#: src/http.c:1831 src/http.c:2385
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
