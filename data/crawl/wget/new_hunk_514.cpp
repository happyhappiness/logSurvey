"Ja hi ha un enllaç simbòlic correcte %s -> %s\n"
"\n"

#: src/ftp.c:1788
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "S'està creant l'enllaç simbòlic %s -> %s\n"

#: src/ftp.c:1798
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr "No es suporten enllaços simbòlics; s'omet l'enllaç «%s».\n"

#: src/ftp.c:1810
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "S'està ometent el directori «%s».\n"

#: src/ftp.c:1819
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tipus de fitxer desconegut o no suportat.\n"

#: src/ftp.c:1856
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: la marca de temps és corrupta..\n"

#: src/ftp.c:1878
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "No es baixaran els directoris ja que la profunditat és %d (max %d).\n"

#: src/ftp.c:1928
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "No es descendeix a «%s» ja que està exclòs, o no inclòs.\n"

#: src/ftp.c:1994 src/ftp.c:2008
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "S'està rebutjant «%s».\n"

#: src/ftp.c:2031
#, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "S'ha produït un error en comparar %s amb %s: %s\n"

#: src/ftp.c:2073
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Cap coincidència amb el patró «%s».\n"

#: src/ftp.c:2144
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "S'ha escrit un índex HTMLitzat a «%s» [%s].\n"

#: src/ftp.c:2149
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "S'ha escrit un índex HTMLitzat a «%s».\n"

#: src/gnutls.c:219 src/openssl.c:495
msgid "ERROR"
msgstr "ERROR"

#: src/gnutls.c:219 src/openssl.c:495
msgid "WARNING"
msgstr "AVÍS"

#: src/gnutls.c:225 src/openssl.c:504
#, c-format
msgid "%s: No certificate presented by %s.\n"
msgstr "%s: %s no ha presentat cap certificat.\n"

#: src/gnutls.c:233
#, fuzzy, c-format
msgid "%s: The certificate of %s is not trusted.\n"
msgstr "%s: %s no ha presentat cap certificat.\n"

#: src/gnutls.c:239
#, c-format
msgid "%s: The certificate of %s hasn't got a known issuer.\n"
msgstr ""

#: src/gnutls.c:245
#, fuzzy, c-format
msgid "%s: The certificate of %s has been revoked.\n"
msgstr "  El certificat ha caducat.\n"

#: src/gnutls.c:259
#, c-format
msgid "Error initializing X509 certificate: %s\n"
msgstr ""

#: src/gnutls.c:268
#, fuzzy
msgid "No certificate found\n"
msgstr "%s: %s no ha presentat cap certificat.\n"

#: src/gnutls.c:275
#, fuzzy, c-format
msgid "Error parsing certificate: %s\n"
msgstr ""
"S'ha produït un error en analitzar la URL del servidor intermediari %s: %s.\n"

#: src/gnutls.c:282
#, fuzzy
msgid "The certificate has not yet been activated\n"
msgstr "  El certificat encara no és vàlid.\n"

#: src/gnutls.c:287
#, fuzzy
msgid "The certificate has expired\n"
msgstr "  El certificat ha caducat.\n"

#: src/gnutls.c:293
#, fuzzy, c-format
msgid "The certificate's owner does not match hostname '%s'\n"
msgstr ""
"%s: el nom comú «%s» del certificat no concorda amb el nom del servidor "
"demanat «%s».\n"

#: src/host.c:358
msgid "Unknown host"
msgstr "Servidor desconegut"

#: src/host.c:362
msgid "Temporary failure in name resolution"
msgstr "S'ha produït un error temporal en la resolució de noms"

#: src/host.c:364
msgid "Unknown error"
msgstr "S'ha produït un error desconegut"

#: src/host.c:737
#, c-format
msgid "Resolving %s... "
msgstr "S'està resolent %s... "

#: src/host.c:789
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "error: No hi ha adreces IPv4/IPv6 per al servidor.\n"

#: src/host.c:812
msgid "failed: timed out.\n"
msgstr "error: s'ha exhaurit el temps.\n"

#: src/html-url.c:286
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: No s'ha pogut resoldre l'enllaç incomplet %s.\n"

#: src/html-url.c:762
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: L'URL %s no és vàlid: %s\n"

#: src/http.c:377
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "S'ha produït un error en escriure la petició HTTP: %s.\n"

#: src/http.c:754
msgid "No headers, assuming HTTP/0.9"
msgstr "No hi ha capçaleres, s'assumeix HTTP/0.9"

#: src/http.c:1456
msgid "Disabling SSL due to encountered errors.\n"
msgstr "S'està inhabilitant SSL a causa dels errors trobats.\n"

#: src/http.c:1576
#, fuzzy, c-format
msgid "POST data file %s missing: %s\n"
msgstr "Manca el fitxer de dades POST «%s»: %s\n"

#: src/http.c:1660
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "S'està reutilitzant la connexió a %s:%d.\n"

#: src/http.c:1729
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr ""
"S'ha produït un error en llegir la resposta del servidor intermediari: %s\n"

#: src/http.c:1750
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Ha fallat la tunelització del servidor intermediari: %s"

#: src/http.c:1795
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s: s'ha enviat la petició, s'està esperant una resposta..."

#: src/http.c:1806
msgid "No data received.\n"
msgstr "No s'ha rebut cap dada\n"

#: src/http.c:1813
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "S'ha produït un error de lectura (%s) a les capçaleres.\n"

#: src/http.c:1884
msgid "Unknown authentication scheme.\n"
msgstr "L'esquema d'autenticació és desconegut.\n"

#: src/http.c:1918
msgid "Authorization failed.\n"
msgstr "Ha fallat l'autorització.\n"

#: src/http.c:1956 src/http.c:2466
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
