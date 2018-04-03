"Lien symbolique d�j� correct %s -> %s\n"
"\n"

#: src/ftp.c:1788
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Cr�ation du lien symbolique %s -> %s\n"

#: src/ftp.c:1798
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr "Lien symbolique non support�, escamotage du lien � %s �.\n"

#: src/ftp.c:1810
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "R�pertoire � %s � escamot�.\n"

#: src/ftp.c:1819
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: type de fichier inconnu ou non support�.\n"

#: src/ftp.c:1856
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: horodatage corrompu.\n"

#: src/ftp.c:1878
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ""
"Les r�pertoires ne seront pas r�cup�r�s, la profondeur %d d�passe le maximum "
"%d.\n"

#: src/ftp.c:1928
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "%s n'a pas �t� parcouru puisqu'il est exclu ou non inclus.\n"

#: src/ftp.c:1994 src/ftp.c:2008
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "Rejet de � %s �.\n"

#: src/ftp.c:2031
#, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Erreur - %s ne correspond pas � %s : %s\n"

#: src/ftp.c:2073
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Pas de concordance avec le patron � %s �.\n"

#: src/ftp.c:2144
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "Index �crit sous forme HTML dans � %s � [%s].\n"

#: src/ftp.c:2149
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "Index �crit sous forme HTML dans � %s �.\n"

#: src/gnutls.c:219 src/openssl.c:495
msgid "ERROR"
msgstr "ERREUR"

#: src/gnutls.c:219 src/openssl.c:495
msgid "WARNING"
msgstr "AVERTISSEMENT"

#: src/gnutls.c:225 src/openssl.c:504
#, c-format
msgid "%s: No certificate presented by %s.\n"
msgstr "%s: pas de certificat pr�sent� par %s.\n"

#: src/gnutls.c:233
#, fuzzy, c-format
msgid "%s: The certificate of %s is not trusted.\n"
msgstr "%s: pas de certificat pr�sent� par %s.\n"

#: src/gnutls.c:239
#, c-format
msgid "%s: The certificate of %s hasn't got a known issuer.\n"
msgstr ""

#: src/gnutls.c:245
#, fuzzy, c-format
msgid "%s: The certificate of %s has been revoked.\n"
msgstr "  Le certificat �mis a expir�.\n"

#: src/gnutls.c:259
#, c-format
msgid "Error initializing X509 certificate: %s\n"
msgstr ""

#: src/gnutls.c:268
#, fuzzy
msgid "No certificate found\n"
msgstr "%s: pas de certificat pr�sent� par %s.\n"

#: src/gnutls.c:275
#, fuzzy, c-format
msgid "Error parsing certificate: %s\n"
msgstr "Erreur d'analyse syntaxique du proxy URL %s: %s\n"

#: src/gnutls.c:282
#, fuzzy
msgid "The certificate has not yet been activated\n"
msgstr "  Certificat �mis non encore valide.\n"

#: src/gnutls.c:287
#, fuzzy
msgid "The certificate has expired\n"
msgstr "  Le certificat �mis a expir�.\n"

#: src/gnutls.c:293
#, fuzzy, c-format
msgid "The certificate's owner does not match hostname '%s'\n"
msgstr ""
"%s: le nom commun du certificat `%s' ne concorde par avec le nom de l'h�te "
"demand� `%s'.\n"

#: src/host.c:358
msgid "Unknown host"
msgstr "H�te inconnu"

#: src/host.c:362
msgid "Temporary failure in name resolution"
msgstr "Echec temporaire dans la r�solution de nom"

#: src/host.c:364
msgid "Unknown error"
msgstr "ERREUR inconnue"

#: src/host.c:737
#, c-format
msgid "Resolving %s... "
msgstr "R�solution de %s... "

#: src/host.c:789
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "�chec: pas d'adresse IPv4/IPv6 pour l'h�te.\n"

#: src/host.c:812
msgid "failed: timed out.\n"
msgstr "�chec: d�lai d'attente expir�\n"

#: src/html-url.c:286
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: impossible de r�soudre le lien incomplet %s.\n"

#: src/html-url.c:762
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: URL non valide %s: %s\n"

#: src/http.c:377
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Echec d'�criture de la requ�te HTTP: %s.\n"

#: src/http.c:754
msgid "No headers, assuming HTTP/0.9"
msgstr "Pas d'ent�te, HTTP/0.9 assum�"

#: src/http.c:1456
msgid "Disabling SSL due to encountered errors.\n"
msgstr "D�sactivation SSL en raison des erreurs rencontr�s.\n"

#: src/http.c:1576
#, fuzzy, c-format
msgid "POST data file %s missing: %s\n"
msgstr "Fichier de donn�es POST `%s' est manquant: %s\n"

#: src/http.c:1660
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "R�utilisation de la connexion existante vers %s:%d.\n"

#: src/http.c:1729
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "�CHEC de lecture de la r�ponse proxy: %s.\n"

#: src/http.c:1750
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "�chec de tunnel proxy: %s"

#: src/http.c:1795
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "requ�te %s transmise, en attente de la r�ponse..."

#: src/http.c:1806
msgid "No data received.\n"
msgstr "Aucune donn�e re�ue.\n"

#: src/http.c:1813
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ERREUR de lecture (%s) de l'en-t�te.\n"

#: src/http.c:1884
msgid "Unknown authentication scheme.\n"
msgstr "Sch�ma d'authentification inconnu.\n"

#: src/http.c:1918
msgid "Authorization failed.\n"
msgstr "�CHEC d'autorisation.\n"

#: src/http.c:1956 src/http.c:2466
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
