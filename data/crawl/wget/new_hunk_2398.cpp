#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1753
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Tidak ada pola `%s' yang cocok.\n"

#: src/ftp.c:1819
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Menulis HTML-ized index ke `%s' [%s].\n"

#: src/ftp.c:1824
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Menulis HTML-ized index ke `%s'.\n"

#: src/getopt.c:670
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: opsi `%s' adalah opsi yang ambigu\n"

#: src/getopt.c:695
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: opsi `--%s' tidak memperbolehkan sebuah argumen\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: opsi `%c%s' tidak memperbolehkan sebuah argumen\n"

#: src/getopt.c:718 src/getopt.c:891
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: opsi `%s' membutuhkan sebuah argumen\n"

#. --option
#: src/getopt.c:747
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: opsi `--%s' tidak diketahui\n"

#. +option or -option
#: src/getopt.c:751
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: opsi `%c%s' tidak diketahui\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:777
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: opsi illegal -- %c\n"

#: src/getopt.c:780
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: opsi -- %c tidak valid\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:810 src/getopt.c:940
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: opsi membutuhkan sebuah argumen -- %c\n"

#: src/getopt.c:857
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: opsi `-W %s' adalah sebuah ambigu\n"

#: src/getopt.c:875
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: opsi `-W %s' tidak memperbolehkan sebuah argumen\n"

#: src/host.c:347
msgid "Unknown host"
msgstr "Host tidak diketahui"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr "Resolusi nama untuk sementara gagal"

#: src/host.c:353
msgid "Unknown error"
msgstr "Kesalahan tidak diketahui"

#: src/host.c:714
#, c-format
msgid "Resolving %s... "
msgstr "Resolving %s... "

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "gagal: Tidak ada alamat IPv4/IPv6 untuk host.\n"

#: src/host.c:784
msgid "failed: timed out.\n"
msgstr "gagal: waktu habis.\n"

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Tidak dapat menresolve link yang tidak komplit %s.\n"

#: src/html-url.c:695
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: URL tidak valid %s: %s\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Gagal menulis permintaan HTTP: %s.\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr "Tidak ada headers, mengasumsikan HTTP/0.9"

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Menonaktifkan SSL karena adanya errors.\n"

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "POST data file `%s' hilang: %s\n"

#: src/http.c:1615
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Menggunakan koneksi yang sudah ada ke %s:%d.\n"

#: src/http.c:1684
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Gagal membaca respon proxy: %s\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Proxy tunneling gagal: %s"

#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Permintaan %s dikirimkan, menunggu respons... "

#: src/http.c:1760
msgid "No data received.\n"
msgstr "Tidak ada data yang diterima.\n"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Read error (%s) dalam headers.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ""
"File `%s' sudah ada; tidak diambil.\n"
"\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "Skema authentifikasi tidak diketahui.\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "Authorisasi gagal.\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "Status line salah format"

#: src/http.c:2013
msgid "(no description)"
msgstr "(tidak ada deskripsi)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "Lokasi: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "tidak dispesifikasikan"

#: src/http.c:2078
msgid " [following]"
msgstr " [mengikuti]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
