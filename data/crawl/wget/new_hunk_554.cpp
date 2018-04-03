"Sudah memiliki symlink %s -> %s yang benar\n"
"\n"

#: src/ftp.c:1788
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Membuat symlink %s -> %s\n"

#: src/ftp.c:1798
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr "Symlink tidak disupport, dilewati symlink `%s'.\n"

#: src/ftp.c:1810
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "Melewati direktori `%s'.\n"

#: src/ftp.c:1819
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tidak diketahui/tidak disupport tipe file.\n"

#: src/ftp.c:1856
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: time-stamp corrupt/rusak.\n"

#: src/ftp.c:1878
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Tidak akan mengambil dir karena kedalamannya %d (maksimal %d).\n"

#: src/ftp.c:1928
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "Tidak turun ke `%s' karena ini di excluded/tidak dimasukkan.\n"

#: src/ftp.c:1994 src/ftp.c:2008
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "Menolak `%s'.\n"

#: src/ftp.c:2031
#, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Gagal mencocokan %s dengan %s: %s\n"

#: src/ftp.c:2073
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Tidak ada pola `%s' yang cocok.\n"

#: src/ftp.c:2144
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "Menulis HTML-ized index ke `%s' [%s].\n"

#: src/ftp.c:2149
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "Menulis HTML-ized index ke `%s'.\n"

#: src/gnutls.c:219 src/openssl.c:495
msgid "ERROR"
msgstr "ERROR"

#: src/gnutls.c:219 src/openssl.c:495
msgid "WARNING"
msgstr "PERINGATAN"

#: src/gnutls.c:225 src/openssl.c:504
#, c-format
msgid "%s: No certificate presented by %s.\n"
msgstr "%s: Tidak ada certificate yang di berikan oleh %s.\n"

#: src/gnutls.c:233
#, fuzzy, c-format
msgid "%s: The certificate of %s is not trusted.\n"
msgstr "%s: Tidak ada certificate yang di berikan oleh %s.\n"

#: src/gnutls.c:239
#, c-format
msgid "%s: The certificate of %s hasn't got a known issuer.\n"
msgstr ""

#: src/gnutls.c:245
#, fuzzy, c-format
msgid "%s: The certificate of %s has been revoked.\n"
msgstr "  Sertifikat yang diterbikan telah expired.\n"

#: src/gnutls.c:259
#, c-format
msgid "Error initializing X509 certificate: %s\n"
msgstr ""

#: src/gnutls.c:268
#, fuzzy
msgid "No certificate found\n"
msgstr "%s: Tidak ada certificate yang di berikan oleh %s.\n"

#: src/gnutls.c:275
#, fuzzy, c-format
msgid "Error parsing certificate: %s\n"
msgstr "Salah dalam parsing proxy URL %s: %s.\n"

#: src/gnutls.c:282
#, fuzzy
msgid "The certificate has not yet been activated\n"
msgstr "  Sertifikat yang diterbitkan tidak sah.\n"

#: src/gnutls.c:287
#, fuzzy
msgid "The certificate has expired\n"
msgstr "  Sertifikat yang diterbikan telah expired.\n"

#: src/gnutls.c:293
#, fuzzy, c-format
msgid "The certificate's owner does not match hostname '%s'\n"
msgstr ""
"%s: certificate common name `%s' tidak cocok dengan yang diberikan oleh "
"hostname `%s'.\n"

#: src/host.c:358
msgid "Unknown host"
msgstr "Host tidak diketahui"

#: src/host.c:362
msgid "Temporary failure in name resolution"
msgstr "Resolusi nama untuk sementara gagal"

#: src/host.c:364
msgid "Unknown error"
msgstr "Kesalahan tidak diketahui"

#: src/host.c:737
#, c-format
msgid "Resolving %s... "
msgstr "Resolving %s... "

#: src/host.c:789
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "gagal: Tidak ada alamat IPv4/IPv6 untuk host.\n"

#: src/host.c:812
msgid "failed: timed out.\n"
msgstr "gagal: waktu habis.\n"

#: src/html-url.c:286
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Tidak dapat menresolve link yang tidak komplit %s.\n"

#: src/html-url.c:762
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: URL tidak valid %s: %s\n"

#: src/http.c:377
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Gagal menulis permintaan HTTP: %s.\n"

#: src/http.c:754
msgid "No headers, assuming HTTP/0.9"
msgstr "Tidak ada headers, mengasumsikan HTTP/0.9"

#: src/http.c:1456
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Menonaktifkan SSL karena adanya errors.\n"

#: src/http.c:1576
#, fuzzy, c-format
msgid "POST data file %s missing: %s\n"
msgstr "POST data file `%s' hilang: %s\n"

#: src/http.c:1660
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Menggunakan koneksi yang sudah ada ke %s:%d.\n"

#: src/http.c:1729
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Gagal membaca balasan proxy: %s\n"

#: src/http.c:1750
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Proxy tunneling gagal: %s"

#: src/http.c:1795
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Permintaan %s dikirimkan, menunggu balasan... "

#: src/http.c:1806
msgid "No data received.\n"
msgstr "Tidak ada data yang diterima.\n"

#: src/http.c:1813
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Read error (%s) dalam headers.\n"

#: src/http.c:1884
msgid "Unknown authentication scheme.\n"
msgstr "Skema authentifikasi tidak diketahui.\n"

#: src/http.c:1918
msgid "Authorization failed.\n"
msgstr "Authorisasi gagal.\n"

#: src/http.c:1956 src/http.c:2466
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
