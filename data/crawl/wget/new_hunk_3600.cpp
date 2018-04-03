msgid "%s: option requires an argument -- %c\n"
msgstr "%s: izbira zahteva argument -- %c\n"

#: src/host.c:374
msgid "Host not found"
msgstr "Gostitelj ni bil najden"

#: src/host.c:376
msgid "Unknown error"
msgstr "Neznana napaka"

#. this is fatal
#: src/http.c:555
msgid "Failed to set up an SSL context\n"
msgstr "Vzpostavljanje konteksta SSL ni uspelo.\n"

#: src/http.c:561
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Ni bilo moè nalo¾iti certifikatov od %s\n"

#: src/http.c:565 src/http.c:573
msgid "Trying without the specified certificate\n"
msgstr "Posku¹am brez doloèenega certifikata\n"

#: src/http.c:569
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Ni bilo moè dobiti certifikatskega kljuèa od %s\n"

#: src/http.c:663 src/http.c:1593
msgid "Unable to establish SSL connection.\n"
msgstr "Povezave SSL ni bilo moè vzpostaviti.\n"

#: src/http.c:671
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Znova uporabljam povezavo z %s:%hu.\n"

#: src/http.c:861
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Napaka pri pisanju zahteve HTTP: %s.\n"

#: src/http.c:866
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s zahteva poslana, èakam odgovor... "

#: src/http.c:910
msgid "End of file while parsing headers.\n"
msgstr "Pri razèlenjevanju glave naletel na konec datoteke.\n"

#: src/http.c:920
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Napaka pri branju glave (%s).\n"

#: src/http.c:959
msgid "No data received"
msgstr "Brez sprejetih podatkov"

#: src/http.c:961
msgid "Malformed status line"
msgstr "Zmalièena statusna linija"

#: src/http.c:966
msgid "(no description)"
msgstr "(brez opisa)"

#: src/http.c:1089
msgid "Authorization failed.\n"
msgstr "Avtorizacija neuspe¹na.\n"

#: src/http.c:1096
msgid "Unknown authentication scheme.\n"
msgstr "Neznata metoda avtentifikacije.\n"

#: src/http.c:1136
#, c-format
msgid "Location: %s%s\n"
msgstr "Polo¾aj: %s%s\n"

#: src/http.c:1137 src/http.c:1269
msgid "unspecified"
msgstr "nedoloèen"

#: src/http.c:1138
msgid " [following]"
msgstr " [spremljam]"

#: src/http.c:1200
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    Datoteka je ¾e popolnoma prene¹ena; niè ni za storiti.\n\n"

#: src/http.c:1216
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
"Nadaljevani prenos za to datoteko ni uspel, kar se tepe z ,-c`.\n"
"Noèem prepisati obstojeèe datoteke ,%s`.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1259
msgid "Length: "
msgstr "Dol¾ina: "

#: src/http.c:1264
#, c-format
msgid " (%s to go)"
msgstr " (¹e %s)"

#: src/http.c:1269
msgid "ignored"
msgstr "prezrta"

#: src/http.c:1399
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Pozor: HTTP ne podpira d¾okerjev.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1417
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Datoteka `%s' ¾e obstaja, ne jemljem.\n"

#: src/http.c:1585
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Ne morem pisati v `%s' (%s).\n"

#: src/http.c:1602
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "NAPAKA: Preusmeritev (%d) brez nove lokacije.\n"

#: src/http.c:1630
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s NAPAKA %d: %s.\n"

#: src/http.c:1642
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Glava ,Last-Modified` manjka - izklapljam oznako èasa.\n"

#: src/http.c:1650
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Neveljavna glava `Last-Modified' -- ignoriram èasovno oznako.\n"

#: src/http.c:1673
#, c-format
msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
msgstr "Datoteka na stre¾niku ni novej¹a kot lokalna ,%s` -- ne prena¹amo.\n\n"

#: src/http.c:1680
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Velikosti se ne ujemata (lokalno %ld) -- prena¹amo.\n"

#: src/http.c:1684
msgid "Remote file is newer, retrieving.\n"
msgstr "Oddaljena datoteka je novej¹a, jemljem.\n"

#: src/http.c:1728
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - `%s' shranjen [%ld/%ld]\n\n"

#: src/http.c:1774
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Zveza zaprta z bajtom ¹t. %ld. "

#: src/http.c:1782
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - `%s' shranjen [%ld/%ld])\n\n"

#: src/http.c:1801
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Zveza zaprta z bajtom ¹t. %ld/%ld. "

#: src/http.c:1812
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Napaka pri branju na bajtu %ld (%s)."

#: src/http.c:1820
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Napaka pri èitanju na bajtu %ld/%ld (%s). "

#: src/init.c:349 src/netrc.c:267
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Ne morem prebrati %s (%s).\n"

#: src/init.c:367 src/init.c:373
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Napaka v %s na liniji %d.\n"

#: src/init.c:405
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Pozor: sistemska in uporabnikova wgetrc ka¾eta na `%s'.\n"

#: src/init.c:497
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: HRO©È: Neznani ukaz `%s', vrednost `%s'.\n"

#: src/init.c:529
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: Imenu ,%s` ni mogoèe pripisati naslova IP.\n"

#: src/init.c:559
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Prosim doloèite `on' ali `off'.\n"

#: src/init.c:603
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Prosim navedite ,always`, ,on`, ,off` ali ,never`.\n"

#: src/init.c:622 src/init.c:919 src/init.c:941 src/init.c:1005
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Neveljavna doloèitev `%s'\n"

#: src/init.c:775 src/init.c:797 src/init.c:819 src/init.c:845
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Neveljavna doloèitev `%s'\n"
