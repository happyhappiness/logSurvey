#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1819
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Ingenting passer med mønsteret «%s».\n"

#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Skrev HTML-formattert indeks til «%s» [%ld].\n"

#: src/ftp.c:1890
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Skrev HTML-formattert indeks til «%s».\n"

#. Still not enough randomness, most likely because neither
#. /dev/random nor EGD were available.  Resort to a simple and
#. stupid method -- seed OpenSSL's PRNG with libc PRNG.  This is
#. cryptographically weak, but people who care about strong
#. cryptography should install /dev/random (default on Linux) or
#. specify their own source of randomness anyway.
#: src/gen_sslfunc.c:109
msgid "Warning: using a weak random seed.\n"
msgstr ""

#: src/gen_sslfunc.c:166
msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
msgstr ""

#: src/gen_sslfunc.c:223
msgid "Warning: validation of server certificate not possible!\n"
msgstr ""

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: flagget «%s» er tvetydig\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: flagget «--%s» tillater ikke argumenter\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: flagget «%c%s» tillater ikke argumenter\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: flagget «%s» krever et argument\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: ukjent flagg «--%s»\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: ukjent flagg «%c%s»\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: ugyldig flagg -- %c\n"

#: src/getopt.c:785
#, fuzzy, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: ugyldig flagg -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: flagget krever et argument -- %c\n"

#: src/getopt.c:862
#, fuzzy, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: flagget «%s» er tvetydig\n"

#: src/getopt.c:880
#, fuzzy, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: flagget «--%s» tillater ikke argumenter\n"

#: src/host.c:368
#, fuzzy
msgid "Unknown host"
msgstr "Ukjent feil"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:372
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:374
msgid "Unknown error"
msgstr "Ukjent feil"

#: src/host.c:748
#, fuzzy, c-format
msgid "Resolving %s... "
msgstr "Fjerner %s.\n"

#: src/host.c:792 src/host.c:839
#, c-format
msgid "failed: %s.\n"
msgstr ""

#: src/host.c:801
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:842
msgid "failed: timed out.\n"
msgstr ""

#: src/html-url.c:297
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr ""

#: src/http.c:349 src/http.c:1504
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Feil ved sending av HTTP-forespørsel.\n"

#: src/http.c:663
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#. this is fatal
#: src/http.c:1151
msgid "Failed to set up an SSL context\n"
msgstr ""

#: src/http.c:1156
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr ""

#: src/http.c:1159 src/http.c:1166
msgid "Trying without the specified certificate\n"
msgstr ""

#: src/http.c:1163
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr ""

#: src/http.c:1382
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Vil prøve å kontakte %s:%hu.\n"

#: src/http.c:1434
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "Feil ved sending av HTTP-forespørsel.\n"

#: src/http.c:1443
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Feil ved sending av HTTP-forespørsel.\n"

#: src/http.c:1463
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1510
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s forespørsel sendt, mottar topptekster... "

#: src/http.c:1521
#, fuzzy
msgid "No data received.\n"
msgstr "Ingen data mottatt"

#: src/http.c:1528
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lesefeil (%s) i topptekster.\n"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:1595
msgid "Authorization failed.\n"
msgstr "Autorisasjon mislyktes\n"

#: src/http.c:1609
msgid "Unknown authentication scheme.\n"
msgstr "Ukjent autorisasjons-protokoll.\n"

#: src/http.c:1634
msgid "Malformed status line"
msgstr "Feil i statuslinje"

#: src/http.c:1636
msgid "(no description)"
msgstr "(ingen beskrivelse)"

#: src/http.c:1700
#, c-format
msgid "Location: %s%s\n"
msgstr "Sted: %s%s\n"

#: src/http.c:1701 src/http.c:1801
msgid "unspecified"
msgstr "uspesifisert"

#: src/http.c:1702
msgid " [following]"
msgstr " [omdirigert]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1751
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1781
msgid "Length: "
msgstr "Lengde: "

#: src/http.c:1801
msgid "ignored"
msgstr "ignoreres"

#: src/http.c:1943
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Advarsel: jokertegn ikke støttet i HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1978
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Filen «%s» hentes ikke, fordi den allerede eksisterer.\n"

#: src/http.c:2165
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kan ikke skrive til «%s» (%s).\n"

#: src/http.c:2174
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:2184
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEIL: Omdirigering (%d) uten nytt sted.\n"

#: src/http.c:2216
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEIL %d: %s.\n"

#: src/http.c:2229
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified topptekst mangler -- tidsstempling slås av.\n"

#: src/http.c:2237
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified topptekst ugyldig -- tidsstempel ignoreres.\n"

#: src/http.c:2260
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:2268
#, fuzzy, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr "Filstørrelsene er forskjellige (local %ld), hentes.\n"

#: src/http.c:2273
msgid "Remote file is newer, retrieving.\n"
msgstr "Fil på tjener er nyere - hentes.\n"

#: src/http.c:2315
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s]\n"
"\n"
msgstr ""
"%s (%s) - «%s» lagret [%ld/%ld]\n"
"\n"

#: src/http.c:2372
#, fuzzy, c-format
msgid "%s (%s) - Connection closed at byte %s. "
msgstr "%s (%s) - Forbindelse brutt ved byte %ld. "

#: src/http.c:2381
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s])\n"
"\n"
msgstr ""
"%s (%s) - «%s» lagret [%ld/%ld]\n"
"\n"

#: src/http.c:2407
#, fuzzy, c-format
msgid "%s (%s) - Connection closed at byte %s/%s. "
msgstr "%s (%s) - Forbindelse brutt ved byte %ld/%ld. "

#: src/http.c:2421
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s (%s)."
msgstr "%s (%s) - Lesefeil ved byte %ld (%s)."

#: src/http.c:2431
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s/%s (%s). "
msgstr "%s (%s) - Lesefeil ved byte %ld/%ld (%s)."

#: src/init.c:342
#, c-format
msgid "%s: WGETRC points to %s, which doesn't exist.\n"
msgstr ""

#: src/init.c:395 src/netrc.c:277
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Kan ikke lese %s (%s).\n"

#: src/init.c:413 src/init.c:419
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Feil i %s på linje %d.\n"

#: src/init.c:451
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Advarsel: Både systemets og brukerens wgetrc peker til «%s».\n"

#: src/init.c:595
#, fuzzy, c-format
msgid "%s: Invalid --execute command `%s'\n"
msgstr "%s: Ugyldig spesifikasjon «%s»\n"

#: src/init.c:631
#, fuzzy, c-format
msgid "%s: %s: Invalid boolean `%s', use `on' or `off'.\n"
msgstr "%s: %s: Vennligst spesifiser «on» eller «off».\n"

#: src/init.c:674
#, fuzzy, c-format
msgid "%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"
msgstr "%s: %s: Vennligst spesifiser «on» eller «off».\n"

#: src/init.c:693
#, fuzzy, c-format
msgid "%s: %s: Invalid number `%s'.\n"
msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"

#: src/init.c:926 src/init.c:945
#, fuzzy, c-format
msgid "%s: %s: Invalid byte value `%s'\n"
msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"

#: src/init.c:970
#, fuzzy, c-format
msgid "%s: %s: Invalid time period `%s'\n"
msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"

#: src/init.c:1037
#, fuzzy, c-format
msgid "%s: %s: Invalid header `%s'.\n"
msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"

#: src/init.c:1083
#, fuzzy, c-format
msgid "%s: %s: Invalid progress type `%s'.\n"
msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"

#: src/init.c:1134
#, fuzzy, c-format
msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"

#: src/init.c:1175
#, fuzzy, c-format
msgid "%s: %s: Invalid value `%s'.\n"
msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"

#: src/log.c:777
#, fuzzy, c-format
msgid ""
"\n"
"%s received, redirecting output to `%s'.\n"
msgstr "%s mottatt, omdirigerer utskrifter til «%%s».\n"

#. Eek!  Opening the alternate log file has failed.  Nothing we
#. can do but disable printing completely.
#: src/log.c:787
#, fuzzy, c-format
msgid ""
"\n"
"%s received.\n"
msgstr "Ingen data mottatt"

#: src/log.c:788
#, c-format
msgid "%s: %s; disabling logging.\n"
msgstr ""

#: src/main.c:363
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Bruk: %s [FLAGG]... [URL]...\n"

#: src/main.c:375
#, fuzzy
msgid ""
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
