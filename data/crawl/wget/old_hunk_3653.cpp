msgid "%s: option requires an argument -- %c\n"
msgstr "%s: võti nõuab argumenti -- %c\n"

#: src/host.c:438
#, c-format
msgid "%s: Cannot determine user-id.\n"
msgstr "%s: Ei suuda tuvastada kasutaja id'd.\n"

#: src/host.c:450
#, c-format
msgid "%s: Warning: uname failed: %s\n"
msgstr "%s: Hoiatus: uname ebaõnnestus %s\n"

#: src/host.c:462
#, c-format
msgid "%s: Warning: gethostname failed\n"
msgstr "%s: Hoiatus: gethostname ebaõnnestus\n"

#: src/host.c:490
#, c-format
msgid "%s: Warning: cannot determine local IP address.\n"
msgstr "%s: Hoiatus: ei suuda tuvastada lokaalset IP aadressi.\n"

#: src/host.c:504
#, c-format
msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
msgstr "%s: Hoiatus: ei saa lokaalse IP aadressi reversit.\n"

#. This gets ticked pretty often.  Karl Berry reports
#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:517
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr "%s: Hoiatus: lokaalse aadressi revers ei anna FQDN!\n"

#: src/host.c:545
msgid "Host not found"
msgstr "Hosti ei leitud"

#: src/host.c:547
msgid "Unknown error"
msgstr "Tundmatu viga"

#: src/html.c:615 src/html.c:617
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "/%s indeks serveris %s:%d"

#: src/html.c:639
msgid "time unknown       "
msgstr "tundmatu aeg       "

#: src/html.c:643
msgid "File        "
msgstr "Fail        "

#: src/html.c:646
msgid "Directory   "
msgstr "Kataloog    "

#: src/html.c:649
msgid "Link        "
msgstr "Viide       "

#: src/html.c:652
msgid "Not sure    "
msgstr "Pole kindel "

#: src/html.c:670
#, c-format
msgid " (%s bytes)"
msgstr " (%s baiti)"

#: src/http.c:508
msgid "Failed writing HTTP request.\n"
msgstr "HTTP päringu kirjutamine ebaõnnestus.\n"

#: src/http.c:512
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s päring saadetud, ootan vastust... "

#: src/http.c:551
msgid "End of file while parsing headers.\n"
msgstr "Päiste analüüsil sain faili lõpu teate.\n"

#: src/http.c:562
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Päiste lugemise viga (%s).\n"

#: src/http.c:602
msgid "No data received"
msgstr "Andmeid ei saanudki"

#: src/http.c:604
msgid "Malformed status line"
msgstr "Katkine staatuse rida"

#: src/http.c:609
msgid "(no description)"
msgstr "(kirjeldus puudub)"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:693
msgid "Authorization failed.\n"
msgstr "Autoriseerimine ebaõnnestus.\n"

#: src/http.c:700
msgid "Unknown authentication scheme.\n"
msgstr "Tundmatu autentimis skeem.\n"

#: src/http.c:783
#, c-format
msgid "Location: %s%s\n"
msgstr "Asukoht: %s%s\n"

#: src/http.c:784 src/http.c:809
msgid "unspecified"
msgstr "määramata"

#: src/http.c:785
msgid " [following]"
msgstr " [järgnev]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:799
msgid "Length: "
msgstr "Pikkus: "

#: src/http.c:804
#, c-format
msgid " (%s to go)"
msgstr " (%s veel)"

#: src/http.c:809
msgid "ignored"
msgstr "ignoreerin"

#: src/http.c:912
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Hoiatus: HTTP ei toeta jokkereid.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:933
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Fail `%s' on juba olemas, ei tõmba.\n"

#: src/http.c:1099
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Ei saa kirjutada faili `%s' (%s).\n"

#: src/http.c:1110
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "VIGA: Ümbersuunamine (%d) ilma asukohata.\n"

#: src/http.c:1135
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s VIGA %d: %s.\n"

#: src/http.c:1148
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified päist pole -- ei kasuta aja-stampe.\n"

#: src/http.c:1156
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified päis on vigane -- ignoreerin aja-stampi.\n"

#: src/http.c:1191
msgid "Remote file is newer, retrieving.\n"
msgstr "Kauge fail on uuem, laen alla.\n"

#: src/http.c:1226
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' salvestatud [%ld/%ld]\n"
"\n"

#: src/http.c:1274
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Ühendus suletud baidil %ld. "

#: src/http.c:1282
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - `%s' salvestatud [%ld/%ld])\n"
"\n"

#: src/http.c:1302
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Ühendus suletud baidil %ld/%ld. "

#: src/http.c:1313
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Lugemise viga baidil %ld (%s)."

#: src/http.c:1321
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Lugemise viga baidil %ld/%ld (%s). "

#: src/init.c:329 src/netrc.c:260
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: %s ei saa lugeda (%s).\n"

#: src/init.c:347 src/init.c:353
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Viga %s's real %d.\n"

#: src/init.c:384
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Hoiatus: Nii süsteemne kui kasutaja wgetrc on `%s'.\n"

#: src/init.c:476
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: BUG: tundmatu käsklus`%s', väärtus `%s'.\n"

#: src/init.c:498
#, c-format
msgid "%s: Out of memory.\n"
msgstr "%s: Mälu ei jätku.\n"

#: src/init.c:504
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: `%s' ei õnnestu teisendada IP aadressiks.\n"

#: src/init.c:532
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Palun kasuta `on' või `off'.\n"

#: src/init.c:576
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Palun kasuta `always', `on', `off' või `never'.\n"

#: src/init.c:595 src/init.c:852 src/init.c:874 src/init.c:938
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s %s: Vigane spetsifikatsioon `%s'.\n"

#: src/init.c:708 src/init.c:730 src/init.c:752 src/init.c:778
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Vigane spetsifikatsioon `%s'\n"

#: src/main.c:105
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Kasuta: %s [VÕTI]... [URL]...\n"

#: src/main.c:113
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, mitte-interaktiivne võrgu imeja.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:118
msgid ""
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Kohustuslikud argumendid pikkadele võtmetele\n"
"on kohustuslikud ka lühikestele võtmetele.\n"
"\n"

#: src/main.c:121
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
