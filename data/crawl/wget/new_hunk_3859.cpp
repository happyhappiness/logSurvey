#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:473
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""
"%s: Varovanie: reverzné vyhµadanie lokálnej adresy nevrátilo plné\n"
"                kvalifikované meno!\n"

#: src/host.c:501
msgid "Host not found"
msgstr "Hostiteµ nebol nájdený"

#: src/host.c:503
msgid "Unknown error"
msgstr "Neznáma chyba"

#: src/http.c:621 src/http.c:1433
msgid "Unable to establish SSL connection.\n"
msgstr ""

# , c-format
#: src/http.c:629
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Pokúsim sa spoji» s %s:%hu.\n"

#: src/http.c:805
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Po¾iadavku HTTP nebolo mo¾né odosla».\n"

# , c-format
#: src/http.c:810
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s po¾iadavka odoslaná, èakám na odpoveï ... "

#: src/http.c:854
msgid "End of file while parsing headers.\n"
msgstr "Hlavièka nie je úplná.\n"

# , c-format
#: src/http.c:865
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Chyba (%s) pri èítaní hlavièiek.\n"

#: src/http.c:905
msgid "No data received"
msgstr "Nepri¹li ¾iadne dáta"

#: src/http.c:907
msgid "Malformed status line"
msgstr "Odpoveï serveru má skomolený stavový riadok"

#: src/http.c:912
msgid "(no description)"
msgstr "(¾iadny popis)"

#: src/http.c:1030
msgid "Authorization failed.\n"
msgstr "Autorizácia zlyhala.\n"

#: src/http.c:1037
msgid "Unknown authentication scheme.\n"
msgstr "Server po¾aduje neznámy spôsob autentifikácie.\n"

# , c-format
#: src/http.c:1127
#, c-format
msgid "Location: %s%s\n"
msgstr "Presmerované na: %s%s\n"

#: src/http.c:1128 src/http.c:1153
msgid "unspecified"
msgstr "neudané"

#: src/http.c:1129
msgid " [following]"
msgstr " [nasledujem]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1143
msgid "Length: "
msgstr "Då¾ka:  "

# , c-format
#: src/http.c:1148
#, c-format
msgid " (%s to go)"
msgstr " (ostáva %s)"

#: src/http.c:1153
msgid "ignored"
msgstr "je ignorovaná"

#: src/http.c:1254
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varovanie: HTTP nepodporuje ¾olíkové znaky.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1275
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Súbor `%s' sa nebude prená¹a», je u¾ tu.\n"

# , c-format
#: src/http.c:1425
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nemo¾no zapísa» do `%s' (%s).\n"

# , c-format
#: src/http.c:1443
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "CHYBA: Presmerovanie (%d) bez udanej novej adresy.\n"

# , c-format
#: src/http.c:1468
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s CHYBA %d: %s.\n"

#: src/http.c:1481
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Nebudú sa pou¾íva» èasové razítka (`time-stamps'), preto¾e hlavièka\n"
"\"Last-modified\" v odpovedi serveru chýba.\n"

#: src/http.c:1489
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Ignorujem èasové razítko súboru (`time-stamp'), preto¾e hlavièka \n"
"\"Last-modified\" obsahuje neplatné údaje.\n"

#: src/http.c:1524
msgid "Remote file is newer, retrieving.\n"
msgstr "Vzdialený súbor má nov¹í dátum, prená¹am.\n"

# , c-format
#: src/http.c:1559
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' ulo¾ený [%ld/%ld]\n"
"\n"

# , c-format
#: src/http.c:1607
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Spojenie uzatvorené na byte %ld. "

# , c-format
#: src/http.c:1615
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - `%s' ulo¾ené [%ld/%ld])\n"
"\n"

# , c-format
#: src/http.c:1635
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Spojenie uzatvorené na byte %ld/%ld. "

# , c-format
#: src/http.c:1646
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Chyba pri èítaní dát na byte %ld (%s)."

# , c-format
#: src/http.c:1654
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Chyba pri èítaní dát na byte %ld/%ld (%s). "

# , c-format
#: src/init.c:332 src/netrc.c:261
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Nemo¾no preèíta» %s (%s).\n"

# , c-format
#: src/init.c:350 src/init.c:356
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Chyba v %s na riadku %d.\n"

# , c-format
#: src/init.c:387
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: Varovanie: Globálne aj u¾ívateµské wgetrc sú zhodne ulo¾ené v `%s'.\n"

# , c-format
#: src/init.c:479
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: Chyba: Neznámy príkaz `%s', hodnota `%s'.\n"

# , c-format
#: src/init.c:501
#, fuzzy, c-format
msgid "%s: Out of memory.\n"
msgstr "%s: %s: Nie je dos» pamäte.\n"

#: src/init.c:507
#, fuzzy, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: Varovanie: lokálna IP adresa nemá reverzný záznam v DNS.\n"

# , c-format
#: src/init.c:535
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Zadajte prosím `on' alebo `off'.\n"

# , c-format
#: src/init.c:579
#, fuzzy, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Zadajte prosím `on' alebo `off'.\n"

# , c-format
#: src/init.c:598 src/init.c:855 src/init.c:877 src/init.c:941
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Neplatná ¹pecifikácia `%s'\n"

# , c-format
#: src/init.c:711 src/init.c:733 src/init.c:755 src/init.c:781
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Neplatná ¹pecifikácia `%s'\n"

# , c-format
#: src/main.c:119
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Pou¾itie: %s [PREPÍNAÈ]... [URL]...\n"

# , c-format
#: src/main.c:127
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, program pre neinteraktívne s»ahovanie súborov.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:132
msgid ""
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Argumenty, povinné pri dlhých prepínaèoch, sú povinné aj pre krátke verzie\n"
"prepínaèov.\n"
"\n"

#: src/main.c:135
#, fuzzy
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
"  -h,  --help              print this help.\n"
"  -b,  --background        go to background after startup.\n"
"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
"\n"
msgstr ""
"Zaèátek:\n"
"  -V,  --version           vypí¹e informáciu o verzii programu Wget a "
"skonèí\n"
"  -h,  --help              vypí¹e túto nápovedu a skonèí\n"
"  -b,  --background        po spustení pokraèuje v behu na pozadí\n"
"  -e,  --execute=PRÍKAZ    vykonaj príkaz `.wgetrc'\n"
"\n"

# , fuzzy
#: src/main.c:141
#, fuzzy
msgid ""
"Logging and input file:\n"
"  -o,  --output-file=FILE     log messages to FILE.\n"
