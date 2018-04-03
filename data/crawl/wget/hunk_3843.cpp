 #. that there can be valid reasons for the local host
 #. name not to be an FQDN, so I've decided to remove the
 #. annoying warning.
-#: src/host.c:511
+#: src/host.c:473
 #, c-format
 msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
-msgstr "%s: Advarsel: fikk ikke FQDN fra tilbake-oppslag for lokal IP-adresse!\n"
+msgstr ""
+"%s: Advarsel: fikk ikke FQDN fra tilbake-oppslag for lokal IP-adresse!\n"
 
-#: src/host.c:539
+#: src/host.c:501
 msgid "Host not found"
 msgstr "Tjener ikke funnet"
 
-#: src/host.c:541
+#: src/host.c:503
 msgid "Unknown error"
 msgstr "Ukjent feil"
 
-#: src/html.c:439 src/html.c:441
-#, c-format
-msgid "Index of /%s on %s:%d"
-msgstr "Indeks for /%s på %s:%d"
-
-#: src/html.c:463
-msgid "time unknown       "
-msgstr "ukjent tid         "
-
-#: src/html.c:467
-msgid "File        "
-msgstr "Fil         "
-
-#: src/html.c:470
-msgid "Directory   "
-msgstr "Katalog     "
-
-#: src/html.c:473
-msgid "Link        "
-msgstr "Link        "
-
-#: src/html.c:476
-msgid "Not sure    "
-msgstr "Usikker     "
+#: src/http.c:621 src/http.c:1433
+msgid "Unable to establish SSL connection.\n"
+msgstr ""
 
-#: src/html.c:494
-#, c-format
-msgid " (%s bytes)"
-msgstr " (%s bytes)"
+#: src/http.c:629
+#, fuzzy, c-format
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "Vil prøve å kontakte %s:%hu.\n"
 
-#: src/http.c:492
-msgid "Failed writing HTTP request.\n"
+#: src/http.c:805
+#, fuzzy, c-format
+msgid "Failed writing HTTP request: %s.\n"
 msgstr "Feil ved sending av HTTP-forespørsel.\n"
 
-#: src/http.c:497
+#: src/http.c:810
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s forespørsel sendt, mottar topptekster... "
 
-#: src/http.c:536
+#: src/http.c:854
 msgid "End of file while parsing headers.\n"
 msgstr "Filslutt funnet ved lesing av topptekster.\n"
 
-#: src/http.c:547
+#: src/http.c:865
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Lesefeil (%s) i topptekster.\n"
 
-#: src/http.c:587
+#: src/http.c:905
 msgid "No data received"
 msgstr "Ingen data mottatt"
 
-#: src/http.c:589
+#: src/http.c:907
 msgid "Malformed status line"
 msgstr "Feil i statuslinje"
 
-#: src/http.c:594
+#: src/http.c:912
 msgid "(no description)"
 msgstr "(ingen beskrivelse)"
 
-#. If we have tried it already, then there is not point
-#. retrying it.
-#: src/http.c:678
+#: src/http.c:1030
 msgid "Authorization failed.\n"
 msgstr "Autorisasjon mislyktes\n"
 
-#: src/http.c:685
+#: src/http.c:1037
 msgid "Unknown authentication scheme.\n"
 msgstr "Ukjent autorisasjons-protokoll.\n"
 
-#: src/http.c:748
+#: src/http.c:1127
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Sted: %s%s\n"
 
-#: src/http.c:749 src/http.c:774
+#: src/http.c:1128 src/http.c:1153
 msgid "unspecified"
 msgstr "uspesifisert"
 
-#: src/http.c:750
+#: src/http.c:1129
 msgid " [following]"
 msgstr " [omdirigert]"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:764
+#: src/http.c:1143
 msgid "Length: "
 msgstr "Lengde: "
 
-#: src/http.c:769
+#: src/http.c:1148
 #, c-format
 msgid " (%s to go)"
 msgstr " (%s igjen)"
 
-#: src/http.c:774
+#: src/http.c:1153
 msgid "ignored"
 msgstr "ignoreres"
 
-#: src/http.c:857
+#: src/http.c:1254
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Advarsel: jokertegn ikke støttet i HTTP.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:872
+#: src/http.c:1275
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "Filen «%s» hentes ikke, fordi den allerede eksisterer.\n"
 
-#: src/http.c:978
+#: src/http.c:1425
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Kan ikke skrive til «%s» (%s).\n"
 
-#: src/http.c:988
+#: src/http.c:1443
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "FEIL: Omdirigering (%d) uten nytt sted.\n"
 
-#: src/http.c:1011
+#: src/http.c:1468
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s FEIL %d: %s.\n"
 
-#: src/http.c:1023
+#: src/http.c:1481
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "Last-modified topptekst mangler -- tidsstempling slås av.\n"
 
-#: src/http.c:1031
+#: src/http.c:1489
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr "Last-modified topptekst ugyldig -- tidsstempel ignoreres.\n"
 
-#: src/http.c:1064
+#: src/http.c:1524
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Fil på tjener er nyere - hentes.\n"
 
-#: src/http.c:1098
+#: src/http.c:1559
 #, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
-msgstr "%s (%s) - «%s» lagret [%ld/%ld]\n\n"
+msgid ""
+"%s (%s) - `%s' saved [%ld/%ld]\n"
+"\n"
+msgstr ""
+"%s (%s) - «%s» lagret [%ld/%ld]\n"
+"\n"
 
-#: src/http.c:1130
+#: src/http.c:1607
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld. "
 msgstr "%s (%s) - Forbindelse brutt ved byte %ld. "
 
-#: src/http.c:1138
+#: src/http.c:1615
 #, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
-msgstr "%s (%s) - «%s» lagret [%ld/%ld]\n\n"
+msgid ""
+"%s (%s) - `%s' saved [%ld/%ld])\n"
+"\n"
+msgstr ""
+"%s (%s) - «%s» lagret [%ld/%ld]\n"
+"\n"
 
-#: src/http.c:1150
+#: src/http.c:1635
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld/%ld. "
 msgstr "%s (%s) - Forbindelse brutt ved byte %ld/%ld. "
 
-#: src/http.c:1161
+#: src/http.c:1646
 #, c-format
 msgid "%s (%s) - Read error at byte %ld (%s)."
 msgstr "%s (%s) - Lesefeil ved byte %ld (%s)."
 
-#: src/http.c:1169
+#: src/http.c:1654
 #, c-format
 msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
 msgstr "%s (%s) - Lesefeil ved byte %ld/%ld (%s)."
 
-#: src/init.c:312 src/netrc.c:250
+#: src/init.c:332 src/netrc.c:261
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr "%s: Kan ikke lese %s (%s).\n"
 
-#: src/init.c:333 src/init.c:339
+#: src/init.c:350 src/init.c:356
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: Feil i %s på linje %d.\n"
 
-#: src/init.c:370
+#: src/init.c:387
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
 msgstr "%s: Advarsel: Både systemets og brukerens wgetrc peker til «%s».\n"
 
-#: src/init.c:458
+#: src/init.c:479
 #, c-format
 msgid "%s: BUG: unknown command `%s', value `%s'.\n"
 msgstr "%s: Ukjent kommando «%s», verdi «%s».\n"
 
-#: src/init.c:485
+#: src/init.c:501
+#, fuzzy, c-format
+msgid "%s: Out of memory.\n"
+msgstr "%s: %s: Ikke nok minne.\n"
+
+#: src/init.c:507
+#, fuzzy, c-format
+msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
+msgstr "%s: Advarsel: feil fra tilbake-oppslag for lokal IP-adresse.\n"
+
+#: src/init.c:535
 #, c-format
 msgid "%s: %s: Please specify on or off.\n"
 msgstr "%s: %s: Vennligst spesifiser «on» eller «off».\n"
 
-#: src/init.c:503 src/init.c:760 src/init.c:782 src/init.c:855
+#: src/init.c:579
+#, fuzzy, c-format
+msgid "%s: %s: Please specify always, on, off, or never.\n"
+msgstr "%s: %s: Vennligst spesifiser «on» eller «off».\n"
+
+#: src/init.c:598 src/init.c:855 src/init.c:877 src/init.c:941
 #, c-format
 msgid "%s: %s: Invalid specification `%s'.\n"
 msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"
 
-#: src/init.c:616 src/init.c:638 src/init.c:660 src/init.c:686
+#: src/init.c:711 src/init.c:733 src/init.c:755 src/init.c:781
 #, c-format
 msgid "%s: Invalid specification `%s'\n"
 msgstr "%s: Ugyldig spesifikasjon «%s»\n"
 
-#: src/main.c:101
+#: src/main.c:119
 #, c-format
 msgid "Usage: %s [OPTION]... [URL]...\n"
 msgstr "Bruk: %s [FLAGG]... [URL]...\n"
 
-#: src/main.c:109
+#: src/main.c:127
 #, c-format
 msgid "GNU Wget %s, a non-interactive network retriever.\n"
 msgstr "GNU Wget %s, en ikke-interaktiv informasjonsagent.\n"
 
 #. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
 #. don't bitch.  Also, it makes translation much easier.
-#: src/main.c:114
-msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
+#: src/main.c:132
+msgid ""
+"\n"
+"Mandatory arguments to long options are mandatory for short options too.\n"
+"\n"
 msgstr ""
 "\n"
 "Obligatoriske argumenter til lange flagg er obligatoriske også \n"
 "for korte.\n"
 "\n"
 
-#: src/main.c:117
+#: src/main.c:135
+#, fuzzy
 msgid ""
 "Startup:\n"
 "  -V,  --version           display the version of Wget and exit.\n"
 "  -h,  --help              print this help.\n"
 "  -b,  --background        go to background after startup.\n"
-"  -e,  --execute=COMMAND   execute a `.wgetrc' command.\n"
+"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
 "\n"
 msgstr ""
 "Oppstart:\n"
