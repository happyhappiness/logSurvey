"Ja hi ha un enllaç simbòlic correcte %s -> %s\n"
"\n"

#: src/ftp.c:1493
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "S'està creant l'enllaç simbòlic %s -> %s\n"

#: src/ftp.c:1503
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "No es suporten enllaços simbòlics; s'omet l'enllaç «%s».\n"

#: src/ftp.c:1515
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "S'està ometent el directori «%s».\n"

#: src/ftp.c:1524
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tipus de fitxer desconegut o no suportat.\n"

#: src/ftp.c:1551
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: la marca de temps és corrupta..\n"

#: src/ftp.c:1579
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "No es descarregaran directoris ja que la profunditat és %d (max %d).\n"

#: src/ftp.c:1629
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "No es descendeix a «%s» ja que està exclòs, o no inclòs.\n"

#: src/ftp.c:1695 src/ftp.c:1709
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "S'està rebutjant «%s».\n"

#: src/ftp.c:1757
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Cap coincidència amb el patró «%s».\n"

#: src/ftp.c:1823
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "S'ha escrit un índex HTMLitzat a «%s» [%s].\n"

#: src/ftp.c:1828
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "S'ha escrit un índex HTMLitzat a «%s».\n"

#: src/host.c:347
msgid "Unknown host"
msgstr "Servidor desconegut"

#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr "S'ha produït un error temporal en la resolució de noms"

#: src/host.c:353
msgid "Unknown error"
msgstr "S'ha produït un error desconegut"

#: src/host.c:714
#, c-format
msgid "Resolving %s... "
msgstr "S'està resolent %s... "

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "error: No hi ha adreces IPv4/IPv6 per al servidor.\n"

#: src/host.c:784
msgid "failed: timed out.\n"
msgstr "error: s'ha exhaurit el temps.\n"

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: No s'ha pogut resoldre l'enllaç incomplet %s.\n"

#: src/html-url.c:695
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: L'URL %s no és vàlid: %s\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "S'ha produït un error en escriure la petició HTTP: %s.\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr "No hi ha capçaleres, s'assumeix HTTP/0.9"

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr "S'està inhabilitant SSL a causa dels errors trobats.\n"

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "Manca el fitxer de dades POST «%s»: %s\n"

#: src/http.c:1615
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "S'està reutilitzant la connexió a %s:%d.\n"

#: src/http.c:1683
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr ""
"S'ha produït un error en llegir la resposta del servidor intermediari: %s\n"

#: src/http.c:1703
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Ha fallat la tunelització del servidor intermediari: %s"

#: src/http.c:1748
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s: s'ha enviat la petició, s'està esperant una resposta..."

#: src/http.c:1759
msgid "No data received.\n"
msgstr "No s'ha rebut cap dada\n"

#: src/http.c:1766
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "S'ha produït un error de lectura (%s) a les capçaleres.\n"

#: src/http.c:1812
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ""
"El fitxer «%s» ja existeix, no es descarrega.\n"
"\n"

#: src/http.c:1965
msgid "Unknown authentication scheme.\n"
msgstr "L'esquema d'autenticació és desconegut.\n"

#: src/http.c:1996
msgid "Authorization failed.\n"
msgstr "Ha fallat l'autorització.\n"

#: src/http.c:2010
msgid "Malformed status line"
msgstr "La línia d'estat és malformada"

#: src/http.c:2012
msgid "(no description)"
msgstr "(sense descripció)"

#: src/http.c:2075
#, c-format
msgid "Location: %s%s\n"
msgstr "Ubicació: %s%s\n"

# és femení: ubicació/mida. eac
#: src/http.c:2076 src/http.c:2183
msgid "unspecified"
msgstr "no especificada"

#: src/http.c:2077
msgid " [following]"
msgstr " [es segueix]"

#: src/http.c:2133
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"    El fitxer ja s'ha descarregat totalment; res a fer.\n"
"\n"

#: src/http.c:2163
msgid "Length: "
msgstr "Mida: "

#: src/http.c:2183
msgid "ignored"
msgstr "s'ignora"

#: src/http.c:2254
#, fuzzy, c-format
msgid "Saving to: `%s'\n"
msgstr "S'està ometent el directori «%s».\n"

#: src/http.c:2335
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Avís: En HTTP no es suporten patrons.\n"

#: src/http.c:2382
msgid "Spider mode enabled. Check if remote file exists.\n"
msgstr ""

#: src/http.c:2467
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "No s'ha pogut escriure a «%s» (%s).\n"

#: src/http.c:2476
msgid "Unable to establish SSL connection.\n"
msgstr "No s'ha pogut establir la connexió SSL.\n"

#: src/http.c:2484
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERROR: Redirecció (%d) sense ubicació.\n"

#: src/http.c:2530
msgid "Remote file does not exist -- broken link!!!\n"
msgstr ""

#: src/http.c:2535
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERROR: %d %s.\n"

#: src/http.c:2551
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Falta la capçalera Last-modified -- s'han inhabilitat les marques de temps.\n"

#: src/http.c:2559
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Capçalera Last-modified no vàlida -- s'omet la marca de temps.\n"

#: src/http.c:2589
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr "El fitxer remot no és més nou que el local «%s» -- no es descarrega.\n"

#: src/http.c:2597
#, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr ""
"Les mides dels fitxers no coincideixen (local %s) -- s'està descarregant.\n"

#: src/http.c:2604
msgid "Remote file is newer, retrieving.\n"
msgstr "El fitxer remot és més nou, s'està descarregant.\n"

#: src/http.c:2620
#, fuzzy
msgid ""
"Remote file exists and could contain links to other resources -- "
"retrieving.\n"
"\n"
msgstr ""
"El fitxer remot és més nou que el local «%s» -- s'està descarregant.\n"
"\n"

#: src/http.c:2625
#, fuzzy
msgid ""
"Remote file exists but does not contain any link -- not retrieving.\n"
"\n"
msgstr "El fitxer remot no és més nou que el local «%s» -- no es descarrega.\n"

#: src/http.c:2633
#, fuzzy
msgid ""
"Remote file exists but recursion is disabled -- not retrieving.\n"
"\n"
msgstr "El fitxer remot no és més nou que el local «%s» -- no es descarrega.\n"

#: src/http.c:2685
#, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s]\n"
