"Downloaded: %s bytes in %d files\n"
msgstr ""
"\n"
"ΤΕΡΜΑΤΙΣΜΟΣ  --%s--\n"
"Μεταφορτώθηκαν: %s byte σε %d αρχεία\n"

#: src/main.c:978
#, c-format
msgid "Download quota (%s bytes) EXCEEDED!\n"
msgstr ""
"Το όριο χώρου στο δίσκο για αρχεία από μεταφορτώσεις (%s bytes) έχει "
"ΞΕΠΕΡΑΣΤΕΪ!\n"

#: src/mswindows.c:235
#, c-format
msgid "Continuing in background.\n"
msgstr "Εκτέλεση στο παρασκήνιο.\n"

#: src/mswindows.c:427
#, fuzzy, c-format
msgid "Continuing in background, pid %lu.\n"
msgstr ""
"Συνέχιση στο παρασκήνιο, ταυτότητα διεργασίας (pid) %d.\n"
"\n"

#: src/mswindows.c:429 src/utils.c:348
#, c-format
msgid "Output will be written to `%s'.\n"
msgstr "Η έξοδος θα γραφτεί στο `%s'.\n"

#: src/mswindows.c:597 src/mswindows.c:604
#, c-format
msgid "%s: Couldn't find usable socket driver.\n"
msgstr "%s: Αδυναμία εύρεσης έγκυρου οδηγού δικτύου.\n"

#: src/netrc.c:385
#, c-format
msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
msgstr ""
"%s: %s:%d: προειδοποίηση: το τμήμα \"%s\" εμφανίζεται πριν από τα ονόματα "
"των μηχανημάτων\n"

#: src/netrc.c:416
#, c-format
msgid "%s: %s:%d: unknown token \"%s\"\n"
msgstr "%s: %s:%d: άγνωστος τελεσταίος \"%s\"\n"

#: src/netrc.c:480
#, c-format
msgid "Usage: %s NETRC [HOSTNAME]\n"
msgstr "Χρήση: %s NETRC [ΟΝΟΜΑ ΜΗΧΑΝΗΜΑΤΟΣ]\n"

#: src/netrc.c:490
#, c-format
msgid "%s: cannot stat %s: %s\n"
msgstr "%s: αδυναμία πρόσβασης στο %s: %s\n"

#. Still not random enough, presumably because neither /dev/random
#. nor EGD were available.  Try to seed OpenSSL's PRNG with libc
#. PRNG.  This is cryptographically weak and defeats the purpose
#. of using OpenSSL, which is why it is highly discouraged.
#: src/openssl.c:121
msgid "WARNING: using a weak random seed.\n"
msgstr ""

#: src/openssl.c:181
#, fuzzy
msgid "Could not seed PRNG; consider using --random-file.\n"
msgstr "Αδύνατη η αρχικοποίηση της PRNG της OpenSSL· απενεργοποίηση του SSL.\n"

#. If the user has specified --no-check-cert, we still want to warn
#. him about problems with the server's certificate.
#: src/openssl.c:419
msgid "ERROR"
msgstr ""

#: src/openssl.c:419
msgid "WARNING"
msgstr ""

#: src/openssl.c:427
#, c-format
msgid "%s: No certificate presented by %s.\n"
msgstr ""

#: src/openssl.c:458
#, c-format
msgid "%s: Certificate verification error for %s: %s\n"
msgstr ""

#: src/openssl.c:485
#, c-format
msgid ""
"%s: certificate common name `%s' doesn't match requested host name `%s'.\n"
msgstr ""

#: src/openssl.c:498
#, c-format
msgid "To connect to %s insecurely, use `--no-check-certificate'.\n"
msgstr ""

#. Align the [ skipping ... ] line with the dots.  To do
#. that, insert the number of spaces equal to the number of
#. digits in the skipped amount in K.
#: src/progress.c:243
#, c-format
msgid ""
"\n"
"%*s[ skipping %dK ]"
msgstr ""
"\n"
"%*s[ παράκαμψη %dK ]"

#: src/progress.c:410
#, c-format
msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
msgstr "Μη έγκυρη ρύθμιση στυλ τελείας `%s'· παραμένει χωρίς αλλαγή.\n"

#: src/recur.c:377
#, c-format
msgid "Removing %s since it should be rejected.\n"
msgstr "Διαγραφή του %s αφού θα έπρεπε να απορριφθεί.\n"

#: src/res.c:544
msgid "Loading robots.txt; please ignore errors.\n"
msgstr ""
"Ανάγνωση του robots.txt; παρακαλώ αγνοείστε τυχόν μηνύματα σφαλμάτων.\n"

#: src/retr.c:645
#, c-format
msgid "Error parsing proxy URL %s: %s.\n"
msgstr "Σφάλμα στην ανάλυση του URL του διαμεσολαβητή %s: %s.\n"

#: src/retr.c:653
#, c-format
msgid "Error in proxy URL %s: Must be HTTP.\n"
msgstr "Σφάλμα στο URL διαμεσολαβητή %s: Πρέπει να είναι HTTP.\n"

#: src/retr.c:738
#, c-format
msgid "%d redirections exceeded.\n"
msgstr "Υπέρβαση %d επανακατευθύνσεων.\n"

#: src/retr.c:863
msgid ""
"Giving up.\n"
"\n"
msgstr ""
"Εγκαταλείπω.\n"
"\n"

#: src/retr.c:863
msgid ""
"Retrying.\n"
"\n"
msgstr ""
"Προσπάθεια ξανά.\n"
"\n"

#: src/url.c:626
#, fuzzy
msgid "No error"
msgstr "¶γνωστο σφάλμα"

#: src/url.c:628
msgid "Unsupported scheme"
msgstr ""

#: src/url.c:630
msgid "Empty host"
msgstr ""

#: src/url.c:632
msgid "Bad port number"
msgstr ""

#: src/url.c:634
#, fuzzy
msgid "Invalid user name"
msgstr "Μη έγκυρο όνομα εξυπηρετητή"

#: src/url.c:636
msgid "Unterminated IPv6 numeric address"
msgstr ""

#: src/url.c:638
msgid "IPv6 addresses not supported"
msgstr ""

#: src/url.c:640
msgid "Invalid IPv6 numeric address"
msgstr ""

#. parent, no error
#: src/utils.c:346
#, c-format
msgid "Continuing in background, pid %d.\n"
msgstr ""
"Συνέχιση στο παρασκήνιο, ταυτότητα διεργασίας (pid) %d.\n"
"\n"

#: src/utils.c:394
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr "Αποτυχία διαγραφής συμβολικού συνδέσμου `%s': %s\n"

#: src/xmalloc.c:72
#, c-format
msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
msgstr ""

#~ msgid "Failed to set up an SSL context\n"
#~ msgstr "Αποτυχία δημιουργίας περιβάλλοντος SSL\n"

#~ msgid "Failed to load certificates from %s\n"
#~ msgstr "Αποτυχία φόρτωσης πιστοποιητικών από %s\n"

#~ msgid "Trying without the specified certificate\n"
#~ msgstr "Προσπάθεια χωρίς το καθορισμένο πιστοποιητικό\n"

#~ msgid "Failed to get certificate key from %s\n"
#~ msgstr "Αποτυχία λήψης κλειδιού πιστοποιητικού από %s\n"

#~ msgid "Syntax error in Set-Cookie at character `%c'.\n"
#~ msgstr "Συνακτικό σφάλμα στο Set-Cookie στο χαρακτήρα `%c'.\n"

#~ msgid ""
#~ "\n"
#~ "REST failed; will not truncate `%s'.\n"
#~ msgstr ""
#~ "\n"
#~ "Αποτυχία της REST· δε θα επανακτηθεί το `%s'.\n"

#~ msgid " [%s to go]"
#~ msgstr " [%s για πέρας]"

#~ msgid "Host not found"
#~ msgstr "Ο διακομιστής δε βρέθηκε"

#~ msgid "End of file while parsing headers.\n"
#~ msgstr "Τέλος αρχείου ενώ γινόταν επεξεργασία των κεφαλίδων.\n"

#~ msgid ""
#~ "\n"
#~ "Continued download failed on this file, which conflicts with `-c'.\n"
#~ "Refusing to truncate existing file `%s'.\n"
#~ "\n"
#~ msgstr ""
#~ "\n"
#~ "Η συνέχιση της ανάκτησης απέτυχε για αυτό το αρχείο, που συγκρούεται με "
#~ "το `-c'.\n"
#~ "¶ρνηση εγγραφής πάνω στο υπάρχο αρχείο `%s'.\n"

#~ msgid " (%s to go)"
#~ msgstr " (%s μέχρι πέρας)"

#~ msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
#~ msgstr "%s: %s: Δεν είναι δυνατή η μετατροπή του `%s' σε διεύθυνση IP.\n"

#~ msgid ""
#~ "Startup:\n"
#~ "  -V,  --version           display the version of Wget and exit.\n"
#~ "  -h,  --help              print this help.\n"
#~ "  -b,  --background        go to background after startup.\n"
#~ "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
#~ "\n"
#~ msgstr ""
#~ "Έναρξη:\n"
#~ "  -V,  --version           εμφάνιση της έκδοσης του Wget και έξοδος.\n"
#~ "  -h,  --help              εμφάνιση της βοήθειας αυτής.\n"
#~ "  -b,  --background        αποστολή στο παρασκήνιο μετά την έναρξη.\n"
#~ "  -e,  --execute=ΕΝΤΟΛΗ    εκτέλεση μιας εντολής μορφής `.wgetrc'.\n"
#~ "\n"

#~ msgid ""
#~ "Logging and input file:\n"
#~ "  -o,  --output-file=FILE     log messages to FILE.\n"
#~ "  -a,  --append-output=FILE   append messages to FILE.\n"
#~ "  -d,  --debug                print debug output.\n"
#~ "  -q,  --quiet                quiet (no output).\n"
#~ "  -v,  --verbose              be verbose (this is the default).\n"
#~ "  -nv, --non-verbose          turn off verboseness, without being quiet.\n"
#~ "  -i,  --input-file=FILE      download URLs found in FILE.\n"
#~ "  -F,  --force-html           treat input file as HTML.\n"
#~ "  -B,  --base=URL             prepends URL to relative links in -F -i "
#~ "file.\n"
#~ "       --sslcertfile=FILE     optional client certificate.\n"
#~ "       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n"
#~ "       --egd-file=FILE        file name of the EGD socket.\n"
#~ "\n"
#~ msgstr ""
#~ "Καταγραφή·και·αρχείο·εισόδου:\n"
#~ "  -o,  --output-file=ΑΡΧΕΙΟ   καταγραφή·μηνυμάτων·στο·ΑΡΧΕΙΟ.\n"
#~ "  -a,  --append-output=ΑΡΧΕΙΟ προσθήκη·μηνυμάτων·στο·ΑΡΧΕΙΟ.\n"
#~ "  -d,  --debug                εμφάνιση·πληροφοριών·εκσφαλμάτωσης.\n"
#~ "  -q,  --quiet                σιωπηλά·(χωρίς·έξοδο).\n"
#~ "  -v,  --verbose              περιφραστικά·(εξ'·ορισμού·ρύθμιση).\n"
#~ "  -nv, --non-verbose          απενεργοποίηση·περιφραστικότητας,"
#~ "·χωρίς·να·είναι·και·σιωπηλό.\n"
#~ "  -i,  --input-file=ΑΡΧΕΙΟ    ανάγνωση·URL·από·το·ΑΡΧΕΙΟ.\n"
#~ "  -F,  --force-html           "
#~ "μεταχείριση·αρχείου·εισόδου·ως·αρχείο·HTML.\n"
#~ "  -B,  --base=URL             "
#~ "προσθέτει·το·URL·στους·σχετικούς·συνδέσμους·στο·-F·-i·αρχείο.\n"
#~ "       --sslcertfile=ΑΡΧΕΙΟ   προαιρετικό·πιστοποιητικό·πελάτη.\n"
#~ "       --sslcertkey=ΑΡΧΕΙΟ    προαιρετικό αρχείο κλειδιού για αυτό το "
#~ "πιστοποιητικό.\n"
#~ "       --egd-file=ΑΡΧΕΙΟ      όνομα αρχείου για τον υποδοχέα EGD.\n"
#~ "\n"

#~ msgid ""
#~ "Download:\n"
#~ "       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local "
#~ "host.\n"
#~ "  -t,  --tries=NUMBER           set number of retries to NUMBER (0 "
#~ "unlimits).\n"
#~ "  -O   --output-document=FILE   write documents to FILE.\n"
#~ "  -nc, --no-clobber             don't clobber existing files or use .# "
#~ "suffixes.\n"
#~ "  -c,  --continue               resume getting a partially-downloaded "
#~ "file.\n"
#~ "       --progress=TYPE          select progress gauge type.\n"
#~ "  -N,  --timestamping           don't re-retrieve files unless newer than "
#~ "local.\n"
#~ "  -S,  --server-response        print server response.\n"
#~ "       --spider                 don't download anything.\n"
#~ "  -T,  --timeout=SECONDS        set the read timeout to SECONDS.\n"
#~ "  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
#~ "       --waitretry=SECONDS      wait 1...SECONDS between retries of a "
#~ "retrieval.\n"
#~ "       --random-wait            wait from 0...2*WAIT secs between "
#~ "retrievals.\n"
#~ "  -Y,  --proxy=on/off           turn proxy on or off.\n"
#~ "  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
#~ "       --limit-rate=RATE        limit download rate to RATE.\n"
#~ "\n"
#~ msgstr ""
#~ "Μεταφόρτωση:\n"
#~ "       --bind-address=ΔΙΕΥΘΥΝΣΗ σύνδεση στη ΔΙΕΥΘΥΝΣΗ (όνομα συστήματος ή "
#~ "IP) στο τοπικό σύστημα.\n"
#~ "  -t,  --tries=ΑΡΙΘΜΟΣ          ορισμός του αριθμού των προσπαθειών σε "
#~ "ΑΡΙΘΜΟΣ (0 για χωρίς όριο).\n"
#~ "  -O   --output-document=ΑΡΧΕΙΟ εγγραφή εγγράφων στο ΑΡΧΕΙΟ.\n"
#~ "  -nc, --no-clobber             να μην αλλαχτούν τα ονόματα υπαρχόντων "
#~ "αρχείων ή να δοθούν καταλήξεις .#.\n"
#~ "  -c,  --continue               συνέχιση ανάκτησης υπάρχοντος αρχείου.\n"
#~ "       --progress=ΜΟΡΦΗ         επιλογή της μορφής εμφάνισης της προόδου "
#~ "ανάκτησης.\n"
#~ "  -N,  --timestamping           αποφυγή ανάκτησης αρχείων παλαιότερων των "
#~ "τοπικών.\n"
#~ "  -S,  --server-response        εμφάνιση αποκρίσεων του διακομιστή.\n"
#~ "       --spider                 αποφυγή ανάκτησης οποιουδήποτε αρχείου.\n"
#~ "  -T,  --timeout=ΔΕΥΤΕΡΟΛΕΠΤΑ   ορισμός χρονικού ορίου ανάκτησης σε "
#~ "ΔΕΥΤΕΡΟΛΕΠΤΑ.\n"
#~ "  -w,  --wait=ΔΕΥΤΕΡΟΛΕΠΤΑ      αναμονή ΔΕΥΤΕΡΟΛΕΠΤΑ μεταξύ ανακτήσεων.\n"
#~ "       --waitretry=ΔΕΥΤΕΡΟΛΕΠΤΑ αναμονή 1...ΔΕΥΤΕΡΟΛΕΠΤΑ μεταξύ "
#~ "προσπαθειών ανάκτησης.\n"
#~ "       --random-wait            αναμονή από 0...2*ΚΑΘΥΣΤΕΡΗΣΗ "
#~ "δευτερόλεπτα μεταξύ ανακτήσεων.\n"
#~ "  -Y,  --proxy=on/off           ρύθμιση χρήσης διαμεσολαβητή σε ενεργό "
#~ "(on) ή ανενεργό (off).\n"
#~ "  -Q,  --quota=ΑΡΙΘΜΟΣ          ορισμός ορίου συνολικού μεγέθους αρχείων "
#~ "προς ανάκτηση σε ΑΡΙΘΜΟ.\n"
#~ "       --limit-rate=ΡΥΘΜΟΣ      περιορισμός του ρυθμού ανάκτησης σε "
#~ "ΡΥΘΜΟΣ.\n"
#~ "\n"

#~ msgid ""
#~ "Directories:\n"
#~ "  -nd  --no-directories            don't create directories.\n"
#~ "  -x,  --force-directories         force creation of directories.\n"
#~ "  -nH, --no-host-directories       don't create host directories.\n"
#~ "  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
#~ "       --cut-dirs=NUMBER           ignore NUMBER remote directory "
#~ "components.\n"
#~ "\n"
#~ msgstr ""
#~ "Κατάλογοι:\n"
#~ "  -nd  --no-directories            αποφυγή δημιουργίας καταλόγων.\n"
#~ "  -x,  --force-directories         υποχρεωτική δημιουργία καταλόγων.\n"
#~ "  -nH, --no-host-directories       αποφυγή δημιουργίας host directories.\n"
#~ "  -P,  --directory-prefix=ΠΡΟΘΕΜΑ  αποθήκευση αρχείων στο ΠΡΟΘΕΜΑ/...\n"
#~ "       --cut-dirs=ΑΡΙΘΜΟΣ          αγνόηση ΑΡΙΘΜΟΣ στοιχείων "
#~ "απομακρυσμένων καταλόγων\n"
#~ "\n"

#~ msgid ""
#~ "HTTP options:\n"
#~ "       --http-user=USER      set http user to USER.\n"
#~ "       --http-passwd=PASS    set http password to PASS.\n"
#~ "  -C,  --cache=on/off        (dis)allow server-cached data (normally "
#~ "allowed).\n"
#~ "  -E,  --html-extension      save all text/html documents with .html "
#~ "extension.\n"
#~ "       --ignore-length       ignore `Content-Length' header field.\n"
#~ "       --header=STRING       insert STRING among the headers.\n"
#~ "       --proxy-user=USER     set USER as proxy username.\n"
#~ "       --proxy-passwd=PASS   set PASS as proxy password.\n"
#~ "       --referer=URL         include `Referer: URL' header in HTTP "
#~ "request.\n"
#~ "  -s,  --save-headers        save the HTTP headers to file.\n"
#~ "  -U,  --user-agent=AGENT    identify as AGENT instead of Wget/VERSION.\n"
#~ "       --no-http-keep-alive  disable HTTP keep-alive (persistent "
#~ "connections).\n"
#~ "       --cookies=off         don't use cookies.\n"
#~ "       --load-cookies=FILE   load cookies from FILE before session.\n"
#~ "       --save-cookies=FILE   save cookies to FILE after session.\n"
#~ "\n"
#~ msgstr ""
#~ "Επιλογές HTTP:\n"
#~ "       --http-user=ΧΡΗΣΤΗΣ   ορισμός χρήστη http σε ΧΡΗΣΤΗ.\n"
#~ "       --http-passwd=ΚΩΔΙΚΟΣ ορισμός κωδικού χρήστη http σε ΚΩΔΙΚΟΣ.\n"
#~ "  -C,  --cache=on/off        αποτροπή/χρήση δεδομένων του διαμεσολαβητή "
#~ "(κανονικά επιτρέπεται).\n"
#~ "  -E,  --html-extension      αποθήκευση όλων των εγγράφων text/html με "
#~ "κατάληξη .html.\n"
#~ "       --ignore-length       αγνόηση του πεδίου `Content-Length' της "
#~ "κεφαλίδας.\n"
#~ "       --header=ΑΛΦΑΡΙΘΜΗΤΙΚΟ  εισαγωγή του ΑΛΦΑΡΙΘΜΗΤΙΚΟ στην κεφαλίδα.\n"
#~ "       --proxy-user=ΧΡΗΣΤΗΣ  ορισμός του ΧΡΗΣΤΗΣ για χρήστη του "
#~ "διαμεσολαβητή.\n"
#~ "       --proxy-passwd=ΚΩΔΙΚΟΣ  ορισμός του ΚΩΔΙΚΟΣ για κωδικός στο "
#~ "διαμεσολαβητή.\n"
#~ "       --referer=URL         χρήση κεφαλίδας `Referer: URL' στην αίτηση "
#~ "HTTP.\n"
#~ "  -s,  --save-headers        αποθήκευση των HTTP κεφαλίδων σε αρχείο.\n"
#~ "  -U,  --user-agent=ΠΡΑΚΤΟΡΑΣ χρήση του ΠΡΑΚΤΟΡΑΣ αντί του Wget/ΕΚΔΟΣΗ.\n"
#~ "       --no-http-keep-alive  απενεργοποίηση του HTTP keep-alive "
#~ "(συνδέσεις διαρκείας).\n"
#~ "       --cookies=off         να μη γίνει χρήση των cookies.\n"
#~ "       --load-cookies=ΑΡΧΕΙΟ φόρτωση cookies από το ΑΡΧΕΙΟ πριν τη "
#~ "συνεδρία.\n"
#~ "       --save-cookies=ΑΡΧΕΙΟ αποθήκευση των cookies στο ΑΡΧΕΙΟ μετά τη "
#~ "συνεδρία.\n"
#~ "\n"

#~ msgid ""
#~ "FTP options:\n"
#~ "  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
#~ "  -g,  --glob=on/off           turn file name globbing on or off.\n"
#~ "       --passive-ftp           use the \"passive\" transfer mode.\n"
#~ "       --retr-symlinks         when recursing, get linked-to files (not "
#~ "dirs).\n"
#~ "\n"
#~ msgstr ""
#~ "Επιλογές FTP:\n"
#~ "  -nr, --dont-remove-listing να μη διαγραφούν τα αρχεία `.listing'.\n"
#~ "  -g,  --glob=on/off         (απ)ενεργοποίηση ταιριάσματος ονομάτων "
#~ "αρχείων.\n"
#~ "       --passive-ftp         χρήση κατάστασης μεταφοράς \"passive\" για "
#~ "το FTP.\n"
#~ "       --retr-symlinks       κατά την αναδρομική ανάκτηση, λήψη "
#~ "αναφερόμενων αρχείων (όχι κατάλογοι).\n"
#~ "\n"

#~ msgid ""
#~ "Recursive retrieval:\n"
#~ "  -r,  --recursive          recursive web-suck -- use with care!\n"
#~ "  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
#~ "infinite).\n"
#~ "       --delete-after       delete files locally after downloading them.\n"
#~ "  -k,  --convert-links      convert non-relative links to relative.\n"
#~ "  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
#~ "  -m,  --mirror             shortcut option equivalent to -r -N -l inf -"
#~ "nr.\n"
#~ "  -p,  --page-requisites    get all images, etc. needed to display HTML "
#~ "page.\n"
#~ "\n"
#~ msgstr ""
#~ "Αναδρομική ανάκτηση:\n"
#~ "  -r,  --recursive             αναδρομική ανάκτηση -- χρήση με σύνεση!\n"
#~ "  -l,  --level=ΑΡΙΘΜΟΣ         μέγιστο βάθος αναδρομής (`inf' ή 0 για "
#~ "απεριόριστο).\n"
#~ "       --delete-after          διαγραφή αρχείων τοπικά μετά τη "
#~ "μεταφόρτωσή τους.\n"
#~ "  -k,  --convert-links         μετατροπή μη-σχετικών συνδέσμων σε "
#~ "σχετικούς.\n"
#~ "  -K,  --backup-converted      πριν τη μετατροπή του αρχείου Χ, διατήρηση "
#~ "αντιγράφου ασφαλείας X.orig.\n"
#~ "  -m,  --mirror                σύντομη επιλογή, ισοδύναμη με -r -N -l inf "
#~ "-nr.\n"
#~ "  -p,  --page-requisites       λήψη όλων των εικόνων, κλπ. που "
#~ "απαιτούνται για την εμφάνιση σελίδας HTML.\n"
#~ "\n"

#~ msgid ""
#~ "Recursive accept/reject:\n"
#~ "  -A,  --accept=LIST                comma-separated list of accepted "
#~ "extensions.\n"
#~ "  -R,  --reject=LIST                comma-separated list of rejected "
#~ "extensions.\n"
#~ "  -D,  --domains=LIST               comma-separated list of accepted "
#~ "domains.\n"
#~ "       --exclude-domains=LIST       comma-separated list of rejected "
#~ "domains.\n"
#~ "       --follow-ftp                 follow FTP links from HTML "
#~ "documents.\n"
#~ "       --follow-tags=LIST           comma-separated list of followed HTML "
#~ "tags.\n"
#~ "  -G,  --ignore-tags=LIST           comma-separated list of ignored HTML "
#~ "tags.\n"
#~ "  -H,  --span-hosts                 go to foreign hosts when recursive.\n"
#~ "  -L,  --relative                   follow relative links only.\n"
#~ "  -I,  --include-directories=LIST   list of allowed directories.\n"
#~ "  -X,  --exclude-directories=LIST   list of excluded directories.\n"
#~ "  -np, --no-parent                  don't ascend to the parent "
#~ "directory.\n"
#~ "\n"
#~ msgstr ""
#~ "Αναδρομική αποδοχή/απόρριψη:\n"
#~ "  -A,  --accept=ΛΙΣΤΑ               λίστα διαχωριζόμενη με κόμμα από "
#~ "αποδεκτές καταλήξεις.\n"
#~ "  -R,  --reject=ΛΙΣΤΑ               λίστα διαχωριζόμενη με κόμμα από μη-"
#~ "αποδεκτές καταλήξεις.\n"
#~ "  -D,  --domains=ΛΙΣΤΑ              λίστα διαχωριζόμενη με κόμμα από "
#~ "αποδεκτά επιθήματα.\n"
#~ "       --exclude-domains=ΛΙΣΤΑ      λίστα διαχωριζόμενη με κόμμα από μη-"
#~ "αποδεκτά επιθήματα.\n"
#~ "       --follow-ftp                 ακολούθηση συνδέσμων FTP από έγγραφα "
#~ "HTML.\n"
#~ "       --follow-tags=ΛΙΣΤΑ          λίστα διαχωριζόμενη με κόμμα με "
#~ "συνδέσμους που έχουν ακολουθηθεί.\n"
#~ "  -G,  --ignore-tags=ΛΙΣΤΑ          λίστα διαχωριζόμενη με κόμμα με "
#~ "συνδέσμους που έχουν αγνοηθεί.\n"
#~ "  -H,  --span-hosts                 επίσκεψη και ξένων διακομιστών κατά "
#~ "την αναδρομή.\n"
#~ "  -L,  --relative                   ακολούθηση μόνο σχετικών URL.\n"
#~ "  -I,  --include-directories=ΛΙΣΤΑ  λίστα επιτρεπτών καταλόγων.\n"
#~ "  -X,  --exclude-directories=ΛΙΣΤΑ  λίστα μη-επιτρεπτών καταλόγων.\n"
#~ "  -np, --no-parent                  απενεργοποίηση πρόσβασης και στο "
#~ "γονικό κατάλογο.\n"
#~ "\n"

#~ msgid "%s: debug support not compiled in.\n"
#~ msgstr ""
#~ "%s: η υποστήριξη εκσφαλμάτωσης δεν έχει συμπεριληφθεί στη μεταγλώττιση.\n"

#~ msgid "%s: %s: invalid command\n"
#~ msgstr "%s: %s: μη έγκυρη εντολή\n"

#~ msgid "Starting WinHelp %s\n"
#~ msgstr "Εκκίνηση του WinHelp %s\n"

#~ msgid "Could not find proxy host.\n"
#~ msgstr "Αδυναμία εύρεσης διαμεσολαβητή.\n"

#~ msgid "%s: Redirection cycle detected.\n"
#~ msgstr "%s: Ανιχνεύτηκε κυκλική επανακατεύθυνση.\n"

#~ msgid "%s: %s: Not enough memory.\n"
#~ msgstr "%s: %s: Δεν υπάρχει αρκετή μνήμη.\n"

#~ msgid "Connection to %s:%hu refused.\n"
#~ msgstr "Σύνδεση με %s:%hu δεν επετράπει.\n"

#~ msgid "%s: Cannot determine user-id.\n"
#~ msgstr "%s: Δεν είναι δυνατή η αναγνώριση της ταυτότητας χρήστη.\n"

#~ msgid "%s: Warning: uname failed: %s\n"
#~ msgstr "%s: Προειδοποίηση: η uname απέτυχε: %s\n"

#~ msgid "%s: Warning: gethostname failed\n"
#~ msgstr "%s: Προειδοποίηση: η gethostname απέτυχε\n"

#~ msgid "%s: Warning: cannot determine local IP address.\n"
#~ msgstr ""
#~ "%s: Προειδοποίηση: δεν είναι δυνατή η ανάγνωση της τοπικής διεύθυνσης "
#~ "IP.\n"

#~ msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
#~ msgstr ""
#~ "%s: Προειδοποίηση: δεν είναι δυνατή η ανάγνωση της τοπικής διεύθυνσης "
#~ "IP.\n"

#~ msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
#~ msgstr ""
#~ "%s: Προειδοποίηση: η ανάστροφη αναζήτηση της τοπικής διεύθυνσης δεν "
#~ "παρήγαγε το FDQN!\n"

#~ msgid "%s: Out of memory.\n"
#~ msgstr "%s: Η μνήμη εξαντλήθηκε.\n"

#~ msgid ""
#~ "\n"
