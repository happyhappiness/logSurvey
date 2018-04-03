msgid "%s: option requires an argument -- %c\n"
msgstr "%s: flaggan behöver ett argument -- %c\n"

#: src/host.c:374
msgid "Host not found"
msgstr "Servern kunde inte hittas"

#: src/host.c:376
msgid "Unknown error"
msgstr "Okänt fel"

#. this is fatal
#: src/http.c:554
msgid "Failed to set up an SSL context\n"
msgstr "Misslyckades med att ställa in ett SSL-sammanhang\n"

#: src/http.c:560
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Misslyckades med att läsa in certifikat från %s\n"

#: src/http.c:564 src/http.c:572
msgid "Trying without the specified certificate\n"
msgstr "Försöker utan det angivna certifikatet\n"

#: src/http.c:568
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Misslyckades med att få tag i certifikatnyckel från %s\n"

#: src/http.c:662 src/http.c:1592
msgid "Unable to establish SSL connection.\n"
msgstr "Kan inte etablera en SSL-anslutning.\n"

#: src/http.c:670
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Återanvänder anslutning till %s:%hu.\n"

#: src/http.c:860
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Misslyckades med att skriva HTTP-begäran: %s.\n"

#: src/http.c:865
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s-begäran skickad, väntar på svar... "

#: src/http.c:909
msgid "End of file while parsing headers.\n"
msgstr "Filslut vid genomsökning av huvuden.\n"

#: src/http.c:919
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Läsfel (%s) i huvuden.\n"

#: src/http.c:958
msgid "No data received"
msgstr "Ingen data mottagen"

#: src/http.c:960
msgid "Malformed status line"
msgstr "Felaktig statusrad"

#: src/http.c:965
msgid "(no description)"
msgstr "(ingen beskrivning)"

#: src/http.c:1088
msgid "Authorization failed.\n"
msgstr "Auktorisering misslyckades.\n"

#: src/http.c:1095
msgid "Unknown authentication scheme.\n"
msgstr "Okänd autentiseringsmetod.\n"

#: src/http.c:1135
#, c-format
msgid "Location: %s%s\n"
msgstr "Adress: %s%s\n"

#: src/http.c:1136 src/http.c:1268
msgid "unspecified"
msgstr "ospecifierat"

#: src/http.c:1137
msgid " [following]"
msgstr " [följande]"

#: src/http.c:1199
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    Filen är redan fullständigt hämtad, inget att göra.\n\n"

#: src/http.c:1215
#, c-format
msgid ""
"\n"
"The server does not support continued downloads, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
"Servern stöder inte återupptagna hämtningar, vilket är i konflikt med \"-c\".\n"
"Vägrar att klippa existerande filen \"%s\".\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1258
msgid "Length: "
msgstr "Längd: "

#: src/http.c:1263
#, c-format
msgid " (%s to go)"
msgstr " (%s kvar)"

#: src/http.c:1268
msgid "ignored"
msgstr "ignorerad"

#: src/http.c:1398
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varning: jokertecken stöds inte i HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1416
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Filen \"%s\" finns redan där, hämtar inte.\n"

#: src/http.c:1584
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kan inte skriva till \"%s\" (%s).\n"

#: src/http.c:1601
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEL: Omdirigering (%d) utan adress.\n"

#: src/http.c:1629
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEL %d: %s.\n"

#: src/http.c:1641
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "\"Last-modified\"-huvud saknas -- tidsstämplar avstängda.\n"

#: src/http.c:1649
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "\"Last-modified\"-huvudet ogiltigt -- tidsstämpel ignorerad.\n"

#: src/http.c:1672
#, c-format
msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
msgstr "Filen på servern är inte nyare än lokala filen \"%s\" -- hämtar inte.\n\n"

#: src/http.c:1679
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Storlekarna stämmer inte överens (lokal %ld) -- hämtar.\n"

#: src/http.c:1683
msgid "Remote file is newer, retrieving.\n"
msgstr "Filen på fjärrsystemet är nyare, hämtar.\n"

#: src/http.c:1727
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - \"%s\" sparad [%ld/%ld]\n\n"

#: src/http.c:1773
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Förbindelse stängd vid byte %ld. "

#: src/http.c:1781
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - \"%s\" sparad [%ld/%ld])\n\n"

#: src/http.c:1800
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Förbindelsen stängd vid byte %ld/%ld. "

#: src/http.c:1811
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Läsfel vid byte %ld (%s)."

#: src/http.c:1819
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Läsfel vid byte %ld/%ld (%s). "

#: src/init.c:348 src/netrc.c:267
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Kan inte läsa %s (%s).\n"

#: src/init.c:366 src/init.c:372
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Fel i %s vid rad %d.\n"

#: src/init.c:404
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Varning: Både systemets och användarens wgetrc pekar till \"%s\".\n"

#: src/init.c:496
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: PROGRAMFEL: kommandot \"%s\" är okänt, värde \"%s\".\n"

#: src/init.c:528
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: Kan inte konvertera \"%s\" till en IP-adress.\n"

#: src/init.c:558
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Ange \"on\" eller \"off\".\n"

#: src/init.c:602
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Ange \"always\", \"on\", \"off\" eller \"never\".\n"

#: src/init.c:621 src/init.c:918 src/init.c:940 src/init.c:1004
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Specifikationen \"%s\" är ogiltig.\n"

#: src/init.c:774 src/init.c:796 src/init.c:818 src/init.c:844
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Specifikationen \"%s\" är ogiltig\n"

#: src/main.c:119
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Användning: %s [FLAGGA]... [URL]...\n"

#: src/main.c:127
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, en icke-interaktiv nätverkshämtare.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:132
msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
msgstr "\nObligatoriska argument till långa flaggor är obligatoriska även för de korta.\n\n"

#: src/main.c:136
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
