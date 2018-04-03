"Υπάρχει ήδη ο ορθός σύνδεσμος %s -> %s\n"
"\n"

#: src/ftp.c:1533
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Δημιουργία συνδέσμου %s -> %s\n"

#: src/ftp.c:1543
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr "Δεν υποστηρίζονται σύνδεσμοι, παράκαμψη συνδέσμου `%s'.\n"

#: src/ftp.c:1555
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "Παράκαμψη καταλόγου `%s'.\n"

#: src/ftp.c:1564
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: άγνωστο/μη υποστηριζόμενο είδος αρχείου.\n"

#: src/ftp.c:1591
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: εσφαλμένη ημερομηνία αρχείου.\n"

#: src/ftp.c:1619
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Δεν θα ανακτηθούν κατάλογοι διότι το βάθος είναι %d (μέγιστο %d).\n"

#: src/ftp.c:1669
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr ""
"Δεν επεκτεινόμαστε στο `%s' διότι είναι εξαιρούμενο/μη-συμπεριλαμβανόμενο\n"

#: src/ftp.c:1735 src/ftp.c:1749
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "Απόρριψη του `%s'.\n"

#: src/ftp.c:1772
#, fuzzy, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Σφάλμα στην εγγραφή στο `%s': %s\n"

#: src/ftp.c:1814
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Δεν βρέθηκαν ταιριάσματα στη μορφή `%s'.\n"

#: src/ftp.c:1880
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "Γράφτηκε αρχείο καταλόγου σε HTML στο `%s' [%ld].\n"

#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "Γράφτηκε αρχείο καταλόγου σε HTML στο `%s'.\n"

#: src/host.c:348
#, fuzzy
msgid "Unknown host"
msgstr "Άγνωστο σφάλμα"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:354
msgid "Unknown error"
msgstr "Άγνωστο σφάλμα"

#: src/host.c:715
#, c-format
msgid "Resolving %s... "
msgstr "Εύρεση του %s... "

#: src/host.c:763
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:786
#, fuzzy
msgid "failed: timed out.\n"
msgstr "απέτυχε: %s.\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Αδύνατη η ανάλυση μη ολοκληρωμένου συνδέσμου %s.\n"

#: src/html-url.c:696
#, fuzzy, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: %s: Μη έγκυρη ρύθμιση `%s'.\n"

#: src/http.c:368
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Σφάλμα στην εγγραφή της αίτησης HTTP: %s.\n"

#: src/http.c:745
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1430
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1548
#, c-format
msgid "POST data file %s missing: %s\n"
msgstr ""

#: src/http.c:1632
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Χρήση ξανά της σύνδεσης στο %s:%hu.\n"

#: src/http.c:1701
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Σφάλμα στην εγγραφή της αίτησης HTTP: %s.\n"

#: src/http.c:1721
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1766
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Η αίτηση για %s στάλθηκε, αναμονή απάντησης... "

#: src/http.c:1777
#, fuzzy
msgid "No data received.\n"
msgstr "Δεν ελήφθησαν δεδομένα"

#: src/http.c:1784
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Σφάλμα ανάγνωσης (%s) στις κεφαλίδες.\n"

#: src/http.c:1831 src/http.c:2385
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
"\n"
msgstr "Το αρχείο `%s' υπάρχει ήδη, δεν επανακτάται.\n"

#: src/http.c:1985
msgid "Unknown authentication scheme.\n"
msgstr "Άγνωστο σχήμα αυθεντικοποίησης.\n"

#: src/http.c:2016
msgid "Authorization failed.\n"
msgstr "Η αυθεντικοποίηση απέτυχε.\n"

#: src/http.c:2030
msgid "Malformed status line"
msgstr "Εσφαλμένη γραμμή κατάστασης"

#: src/http.c:2032
msgid "(no description)"
msgstr "(χωρίς περιγραφή)"

#: src/http.c:2098
#, c-format
msgid "Location: %s%s\n"
msgstr "Τοποθεσία: %s%s\n"

#: src/http.c:2099 src/http.c:2209
msgid "unspecified"
msgstr "μη ορισμένο"

#: src/http.c:2100
msgid " [following]"
msgstr " [ακολουθεί]"

#: src/http.c:2156
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
