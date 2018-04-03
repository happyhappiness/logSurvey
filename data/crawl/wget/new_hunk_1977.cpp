"Ja hi ha un enllaç simbòlic correcte %s -> %s\n"
"\n"

#: src/ftp.c:1494
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "S'està creant l'enllaç simbòlic %s -> %s\n"

#: src/ftp.c:1504
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "No es suporten enllaços simbòlics; s'omet l'enllaç «%s».\n"

#: src/ftp.c:1516
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "S'està ometent el directori «%s».\n"

#: src/ftp.c:1525
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tipus de fitxer desconegut o no suportat.\n"

#: src/ftp.c:1552
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: la marca de temps és corrupta..\n"

#: src/ftp.c:1580
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "No es baixaran els directoris ja que la profunditat és %d (max %d).\n"

#: src/ftp.c:1630
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "No es descendeix a «%s» ja que està exclòs, o no inclòs.\n"

#: src/ftp.c:1696 src/ftp.c:1710
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "S'està rebutjant «%s».\n"

#: src/ftp.c:1733
#, fuzzy, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "S'ha produït un error en escriure a «%s»: %s\n"

#: src/ftp.c:1774
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Cap coincidència amb el patró «%s».\n"

#: src/ftp.c:1840
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "S'ha escrit un índex HTMLitzat a «%s» [%s].\n"

#: src/ftp.c:1845
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "S'ha escrit un índex HTMLitzat a «%s».\n"

#: src/host.c:348
msgid "Unknown host"
msgstr "Servidor desconegut"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr "S'ha produït un error temporal en la resolució de noms"

#: src/host.c:354
msgid "Unknown error"
msgstr "S'ha produït un error desconegut"

#: src/host.c:715
#, c-format
msgid "Resolving %s... "
msgstr "S'està resolent %s... "

#: src/host.c:762
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "error: No hi ha adreces IPv4/IPv6 per al servidor.\n"

#: src/host.c:785
msgid "failed: timed out.\n"
msgstr "error: s'ha exhaurit el temps.\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: No s'ha pogut resoldre l'enllaç incomplet %s.\n"

#: src/html-url.c:696
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: L'URL %s no és vàlid: %s\n"

#: src/http.c:368
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "S'ha produït un error en escriure la petició HTTP: %s.\n"

#: src/http.c:737
msgid "No headers, assuming HTTP/0.9"
msgstr "No hi ha capçaleres, s'assumeix HTTP/0.9"

#: src/http.c:1417
msgid "Disabling SSL due to encountered errors.\n"
msgstr "S'està inhabilitant SSL a causa dels errors trobats.\n"

#: src/http.c:1570
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "Manca el fitxer de dades POST «%s»: %s\n"

#: src/http.c:1619
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "S'està reutilitzant la connexió a %s:%d.\n"

#: src/http.c:1687
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr ""
"S'ha produït un error en llegir la resposta del servidor intermediari: %s\n"

#: src/http.c:1707
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Ha fallat la tunelització del servidor intermediari: %s"

#: src/http.c:1752
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s: s'ha enviat la petició, s'està esperant una resposta..."

#: src/http.c:1763
msgid "No data received.\n"
msgstr "No s'ha rebut cap dada\n"

#: src/http.c:1770
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "S'ha produït un error de lectura (%s) a les capçaleres.\n"

#: src/http.c:1816 src/http.c:2368
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ""
"El fitxer «%s» ja existeix, no es baixa.\n"
"\n"

#: src/http.c:1969
msgid "Unknown authentication scheme.\n"
msgstr "L'esquema d'autenticació és desconegut.\n"

#: src/http.c:2000
msgid "Authorization failed.\n"
msgstr "Ha fallat l'autorització.\n"

#: src/http.c:2014
msgid "Malformed status line"
msgstr "La línia d'estat és malformada"

#: src/http.c:2016
msgid "(no description)"
msgstr "(sense descripció)"

#: src/http.c:2082
#, c-format
msgid "Location: %s%s\n"
msgstr "Ubicació: %s%s\n"

# és femení: ubicació/mida. eac
#: src/http.c:2083 src/http.c:2193
msgid "unspecified"
msgstr "no especificada"

#: src/http.c:2084
msgid " [following]"
msgstr " [es segueix]"

#: src/http.c:2140
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"    El fitxer ja s'ha baixat totalment; res a fer.\n"
"\n"

#: src/http.c:2173
msgid "Length: "
msgstr "Mida: "

#: src/http.c:2193
msgid "ignored"
msgstr "s'ignora"

#: src/http.c:2264
#, c-format
msgid "Saving to: `%s'\n"
msgstr "S'està desant a: «%s»\n"

#: src/http.c:2345
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Avís: En HTTP no es suporten patrons.\n"

#: src/http.c:2412
msgid "Spider mode enabled. Check if remote file exists.\n"
msgstr "Mode aranya habilitat. Comprova si el fitxer remot existeix.\n"

#: src/http.c:2497
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "No s'ha pogut escriure a «%s» (%s).\n"

#: src/http.c:2506
msgid "Unable to establish SSL connection.\n"
msgstr "No s'ha pogut establir la connexió SSL.\n"

#: src/http.c:2514
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERROR: Redirecció (%d) sense ubicació.\n"

#: src/http.c:2560
msgid "Remote file does not exist -- broken link!!!\n"
msgstr "El fitxer remot no existeix -- enllaç trencat!\n"

#: src/http.c:2565
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERROR: %d %s.\n"

#: src/http.c:2581
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Falta la capçalera Last-modified -- s'han inhabilitat les marques de temps.\n"

#: src/http.c:2589
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Capçalera Last-modified no vàlida -- s'omet la marca de temps.\n"

#: src/http.c:2619
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"El fitxer remot no és més nou que el local «%s» -- no es baixa.\n"
"\n"

#: src/http.c:2627
#, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr "Les mides dels fitxers no coincideixen (local %s) -- s'està baixant.\n"

#: src/http.c:2634
msgid "Remote file is newer, retrieving.\n"
msgstr "El fitxer remot és més nou, s'està baixant.\n"

#: src/http.c:2650
msgid ""
"Remote file exists and could contain links to other resources -- "
"retrieving.\n"
"\n"
msgstr ""
"El fitxer remot existeix i pot contenir enllaços a altres recursos -- s'està "
"obtenint.\n"
"\n"

#: src/http.c:2655
msgid ""
"Remote file exists but does not contain any link -- not retrieving.\n"
"\n"
msgstr ""
"El fitxer remot existeix però no conté cap enllaç -- no s'obté.\n"
"\n"

#: src/http.c:2663
msgid ""
"Remote file exists but recursion is disabled -- not retrieving.\n"
"\n"
msgstr ""
"El fitxer remot existeix, però la recursió és inhabilitada -- no es baixa.\n"

#: src/http.c:2715
#, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s]\n"
