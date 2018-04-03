"Már létezik a(z) %s -> %s helyes szimbolikus link\n"
"\n"

#: src/ftp.c:1533
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Létrehozom a(z) %s -> %s szimbolikus linket\n"

#: src/ftp.c:1543
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr ""
"A szimbolikus linkek nem támogatottak, a(z) „%s” szimbolikus linket "
"kihagyom.\n"

#: src/ftp.c:1555
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "A(z) „%s” könyvtárat kihagyom.\n"

#: src/ftp.c:1564
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: ismeretlen/nem támogatott fájltípus.\n"

#: src/ftp.c:1591
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: sérült időpecsét.\n"

#: src/ftp.c:1619
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Könyvtárakat nem töltöm le, mivel a mélység %d (max %d).\n"

#: src/ftp.c:1669
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "Nem lépek be a következőbe: „%s”, mert ki van zárva/nincs kijelölve.\n"

#: src/ftp.c:1735 src/ftp.c:1749
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "A következő visszautasítva: „%s”.\n"

#: src/ftp.c:1772
#, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Hiba %s és %s illesztésekor: %s\n"

#: src/ftp.c:1814
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Nincs találat a(z) „%s” mintához .\n"

#: src/ftp.c:1880
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "A HTML-esített index kiírva a(z) „%s” [%s] fájlba.\n"

#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "A HTML-esített index kiírva a(z) „%s” fájlba.\n"

#: src/host.c:348
msgid "Unknown host"
msgstr "Ismeretlen kiszolgáló"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr "Átmeneti névfeloldási hiba"

#: src/host.c:354
msgid "Unknown error"
msgstr "Ismeretlen hiba"

#: src/host.c:715
#, c-format
msgid "Resolving %s... "
msgstr "%s feloldása... "

#: src/host.c:763
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "meghiúsult: nem található IPv4/IPv6 cím a géphez.\n"

#: src/host.c:786
msgid "failed: timed out.\n"
msgstr "meghiúsult: időtúllépés.\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: nem oldható fel a hiányos %s hivatkozás.\n"

#: src/html-url.c:696
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: Érvénytelen URL: %s: %s.\n"

#: src/http.c:368
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "A HTTP kérés írása meghiúsult: %s.\n"

#: src/http.c:745
msgid "No headers, assuming HTTP/0.9"
msgstr "Nincsenek fejlécek, HTTP/0.9 feltételezése"

#: src/http.c:1430
msgid "Disabling SSL due to encountered errors.\n"
msgstr "A tapasztalt hibák miatt az SSL letiltásra kerül.\n"

#: src/http.c:1548
#, fuzzy, c-format
msgid "POST data file %s missing: %s\n"
msgstr "A(z) „%s” POST adatfájl hiányzik: %s\n"

#: src/http.c:1632
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Újrahasználom a kapcsolatot a következőhöz: %s:%d.\n"

#: src/http.c:1701
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "A proxy válasz olvasása meghiúsult: %s\n"

#: src/http.c:1721
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "A proxy alagutazás meghiúsult: %s"

#: src/http.c:1766
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s kérés elküldve, várom a választ... "

#: src/http.c:1777
msgid "No data received.\n"
msgstr "Nem érkezett adat.\n"

#: src/http.c:1784
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Olvasási hiba (%s) a fejlécekben.\n"

#: src/http.c:1831 src/http.c:2385
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
