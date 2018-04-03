# Pesan Bahasa Indonesia untuk GNU wget
# Copyright (C) 2006 Free Software Foundation, Inc.
# This file is distributed under the same license as the wget package.
# Arif E. Nugroho <arif_endro@yahoo.com>, 2006.
#
msgid ""
msgstr ""
"Project-Id-Version: GNU wget 1.10.2\n"
"Report-Msgid-Bugs-To: \n"
"POT-Creation-Date: 2006-12-18 15:29-0500\n"
"PO-Revision-Date: 2006-12-24 22:00+0700\n"
"Last-Translator: Arif E. Nugroho <arif_endro@yahoo.com>\n"
"Language-Team: Indonesian <translation-team-id@lists.sourceforge.net>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=ISO-8859-1\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/connect.c:199
#, c-format
msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
msgstr "%s: tidak dapat meresolve alamat bind `%s'; mendisable bind.\n"

#: src/connect.c:271
#, c-format
msgid "Connecting to %s|%s|:%d... "
msgstr "Menghubungi %s|%s|:%d... "

#: src/connect.c:274
#, c-format
msgid "Connecting to %s:%d... "
msgstr "Menghubungi %s:%d... "

#: src/connect.c:335
msgid "connected.\n"
msgstr "terhubung.\n"

#: src/connect.c:347 src/host.c:789 src/host.c:818
#, c-format
msgid "failed: %s.\n"
msgstr "gagal: %s.\n"

#: src/convert.c:176
#, c-format
msgid "Converted %d files in %.*f seconds.\n"
msgstr "Mengubah %d files dalam %.*f detik.\n"

#: src/convert.c:202
#, c-format
msgid "Converting %s... "
msgstr "Mengubah %s... "

#: src/convert.c:215
msgid "nothing to do.\n"
msgstr "tidak ada yang bisa dilakukan.\n"

#: src/convert.c:223 src/convert.c:247
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "Tidak dapat mengubah links dalam %s: %s\n"

#: src/convert.c:238
#, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "Tidak dapat menghapus `%s': %s\n"

#: src/convert.c:447
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "Tidak dapat membackup %s sebagai %s: %s\n"

#: src/cookies.c:619
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Error dalam Set-Cookie, bagian `%s'"

#: src/cookies.c:643
#, c-format
msgid "Syntax error in Set-Cookie: %s at position %d.\n"
msgstr "Syntax error dalam Set-Cookie: %s pada posisi %d.\n"

#: src/cookies.c:881
#, c-format
msgid "Cookie coming from %s attempted to set domain to %s\n"
msgstr "Cookie datang dari %s mencoba untuk menset domain menjadi %s\n"

#: src/cookies.c:1328 src/cookies.c:1477
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Tidak dapat membuka file cookies `%s': %s\n"

#: src/cookies.c:1489
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Error menulis ke `%s': %s\n"

#: src/cookies.c:1492
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Error menutup `%s': %s\n"

#: src/ftp-ls.c:843
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Tipe listing tidak disupport, mencoba listing Unix parser.\n"

#: src/ftp-ls.c:889 src/ftp-ls.c:891
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Index dari/%s pada %s:%d"

#: src/ftp-ls.c:914
#, c-format
msgid "time unknown       "
msgstr "waktu tidak diketahui       "

#: src/ftp-ls.c:918
#, c-format
msgid "File        "
msgstr "File        "

#: src/ftp-ls.c:921
#, c-format
msgid "Directory   "
msgstr "Direktori   "

#: src/ftp-ls.c:924
#, c-format
msgid "Link        "
msgstr "LInk        "

#: src/ftp-ls.c:927
#, c-format
msgid "Not sure    "
msgstr "Tidak yakin    "

#: src/ftp-ls.c:945
#, c-format
msgid " (%s bytes)"
msgstr " (%s bytes)"

#: src/ftp.c:226
#, c-format
msgid "Length: %s"
msgstr "Besar: %s"

#: src/ftp.c:232 src/http.c:1861
#, c-format
msgid ", %s (%s) remaining"
msgstr ", %s (%s) tersisa"

#: src/ftp.c:236 src/http.c:1865
#, c-format
msgid ", %s remaining"
msgstr ", %s tersisa"

#: src/ftp.c:239
msgid " (unauthoritative)\n"
msgstr " (unauthoritative)\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:314
#, c-format
msgid "Logging in as %s ... "
msgstr "Masuk sebagai %s ... "

#: src/ftp.c:327 src/ftp.c:373 src/ftp.c:402 src/ftp.c:454 src/ftp.c:566
#: src/ftp.c:612 src/ftp.c:640 src/ftp.c:698 src/ftp.c:759 src/ftp.c:819
#: src/ftp.c:866
msgid "Error in server response, closing control connection.\n"
msgstr "Error dalam respon server, menutup kontrol koneksi.\n"

#: src/ftp.c:334
msgid "Error in server greeting.\n"
msgstr "Error dalam salam server.\n"

#: src/ftp.c:341 src/ftp.c:462 src/ftp.c:574 src/ftp.c:648 src/ftp.c:708
#: src/ftp.c:769 src/ftp.c:829 src/ftp.c:876
msgid "Write failed, closing control connection.\n"
msgstr "Gagal menulis, menutup kontrol koneksi.\n"

#: src/ftp.c:347
msgid "The server refuses login.\n"
msgstr "Server menolak untuk login.\n"

#: src/ftp.c:353
msgid "Login incorrect.\n"
msgstr "Login tidak benar.\n"

#: src/ftp.c:359
msgid "Logged in!\n"
msgstr "Logged in!\n"

#: src/ftp.c:381
msgid "Server error, can't determine system type.\n"
msgstr "Server error, tidak dapat menentukan tipe sistem.\n"

#: src/ftp.c:390 src/ftp.c:685 src/ftp.c:742 src/ftp.c:785
msgid "done.    "
msgstr "selesai.    "

#: src/ftp.c:442 src/ftp.c:591 src/ftp.c:624 src/ftp.c:849 src/ftp.c:895
msgid "done.\n"
msgstr "selesai.\n"

#: src/ftp.c:469
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Tipe `%c' tidak diketahui, menutup kontrol koneksi.\n"

#: src/ftp.c:481
msgid "done.  "
msgstr "selesai.   "

#: src/ftp.c:487
msgid "==> CWD not needed.\n"
msgstr "==> CWD tidak dibutuhkan.\n"

#: src/ftp.c:580
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Tidak ada direktori `%s'.\n"
"\n"

#. do not CWD
#: src/ftp.c:595
msgid "==> CWD not required.\n"
msgstr "==> CWD tidak diperlukan.\n"

#: src/ftp.c:654
msgid "Cannot initiate PASV transfer.\n"
msgstr "Tidak dapat menginitialisasi transfer PASV.\n"

#: src/ftp.c:658
msgid "Cannot parse PASV response.\n"
msgstr "Tidak dapat parse PASV respon.\n"

#: src/ftp.c:676
#, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr "tidak dapat menghubungi %s port %d: %s\n"

#: src/ftp.c:724
#, c-format
msgid "Bind error (%s).\n"
msgstr "Bind error (%s).\n"

#: src/ftp.c:730
msgid "Invalid PORT.\n"
msgstr "PORT tidak valid.\n"

#: src/ftp.c:776
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"REST gagal, memulai dari awal.\n"

#: src/ftp.c:837
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Tidak ada file `%s'.\n"
"\n"

#: src/ftp.c:884
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Tidak ada file atau direktori `%s'.\n"
"\n"

#. We cannot just invent a new name and use it (which is
#. what functions like unique_create typically do)
#. because we told the user we'd use this name.
#. Instead, return and retry the download.
#: src/ftp.c:946 src/http.c:1922
#, c-format
msgid "%s has sprung into existence.\n"
msgstr "%s memiliki sprung kedalam eksistensi.\n"

#: src/ftp.c:1008
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, menutup kontrol koneksi.\n"

#: src/ftp.c:1016
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Data koneksi: %s; "

#: src/ftp.c:1030
msgid "Control connection closed.\n"
msgstr "Koneksi kontrol ditutup.\n"

#: src/ftp.c:1048
msgid "Data transfer aborted.\n"
msgstr "Data transfer dibatalkan.\n"

#: src/ftp.c:1116
#, c-format
msgid "File `%s' already there; not retrieving.\n"
msgstr "File `%s' sudah ada disana; tidak diambil.\n"

#: src/ftp.c:1184 src/http.c:2145
#, c-format
msgid "(try:%2d)"
msgstr "(coba:%2d)"

#: src/ftp.c:1254 src/http.c:2422
#, c-format
msgid ""
"%s (%s) - `%s' saved [%s]\n"
"\n"
msgstr ""
"%s (%s) - `%s' disimpan [%s]\n"
"\n"

#: src/ftp.c:1296 src/main.c:948 src/recur.c:376 src/retr.c:844
#, c-format
msgid "Removing %s.\n"
msgstr "Menghapus %s.\n"

#: src/ftp.c:1338
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Menggunakan `%s' sebagai file listing sementara.\n"

#: src/ftp.c:1353
#, c-format
msgid "Removed `%s'.\n"
msgstr "Menghapus `%s'.\n"

#: src/ftp.c:1388
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Kedalaman recursion %d melebihi maksimum kedalaman %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1458
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "File remote tidak ada yang lebih baru dari file local `%s' -- tidak diambil.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1465
#, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr ""
"File remote lebih baru dari file local `%s' -- diambil.\n"
"\n"

#. Sizes do not match
#: src/ftp.c:1472
#, c-format
msgid ""
"The sizes do not match (local %s) -- retrieving.\n"
"\n"
msgstr ""
"Besar tidak cocok dengan (local %s) -- diambil.\n"
"\n"

#: src/ftp.c:1490
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Nama symlink tidak valid, dilewati.\n"

#: src/ftp.c:1507
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"Sudah memiliki symlink %s -> %s yang benar\n"
"\n"

#: src/ftp.c:1515
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Membuat symlink %s -> %s\n"

#: src/ftp.c:1525
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Symlink tidak disupport, dilewati symlink `%s'.\n"

#: src/ftp.c:1537
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Melewati direktori `%s'.\n"

#: src/ftp.c:1546
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tidak diketahui/tidak disupport tipe file.\n"

#: src/ftp.c:1573
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: time-stamp corrupt/rusak.\n"

#: src/ftp.c:1601
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Tidak akan mengambil dir karena kedalamannya %d (maksimal %d).\n"

#: src/ftp.c:1651
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Tidak turun ke `%s' karena ini di excluded/tidak dimasukkan.\n"

#: src/ftp.c:1717 src/ftp.c:1731
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Menolak `%s'.\n"

#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1777
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Tidak ada pola `%s' yang cocok.\n"

#: src/ftp.c:1843
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Menulis HTML-ized index ke `%s' [%s].\n"

#: src/ftp.c:1848
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Menulis HTML-ized index ke `%s'.\n"

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: opsi `%s' adalah opsi yang ambigu\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: opsi `--%s' tidak memperbolehkan sebuah argumen\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: opsi `%c%s' tidak memperbolehkan sebuah argumen\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: opsi `%s' membutuhkan sebuah argumen\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: opsi `--%s' tidak diketahui\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: opsi `%c%s' tidak diketahui\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: opsi illegal -- %c\n"

#: src/getopt.c:785
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: opsi -- %c tidak valid\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: opsi membutuhkan sebuah argumen -- %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: opsi `-W %s' adalah sebuah ambigu\n"

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: opsi `-W %s' tidak memperbolehkan sebuah argumen\n"

#: src/host.c:366
msgid "Unknown host"
msgstr "Host tidak diketahui"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:370
msgid "Temporary failure in name resolution"
msgstr "Resolusi nama untuk sementara gagal"

#: src/host.c:372
msgid "Unknown error"
msgstr "Kesalahan tidak diketahui"

#: src/host.c:751
#, c-format
msgid "Resolving %s... "
msgstr "Resolving %s... "

#: src/host.c:798
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "gagal: Tidak ada alamat IPv4/IPv6 untuk host.\n"

#: src/host.c:821
msgid "failed: timed out.\n"
msgstr "gagal: waktu habis.\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Tidak dapat menresolve link yang tidak komplit %s.\n"

#: src/html-url.c:705
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: URL tidak valid %s: %s\n"

#: src/http.c:373
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Gagal menulis permintaan HTTP: %s.\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr "Tidak ada headers, mengasumsikan HTTP/0.9"

#: src/http.c:1204
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Menonaktifkan SSL karena adanya errors.\n"

#: src/http.c:1374
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "POST data file `%s' hilang: %s\n"

#: src/http.c:1423
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Menggunakan koneksi yang sudah ada ke %s:%d.\n"

#: src/http.c:1492
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Gagal membaca respon proxy: %s\n"

#: src/http.c:1512
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Proxy tunneling gagal: %s"

#: src/http.c:1557
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Permintaan %s dikirimkan, menunggu respons... "

#: src/http.c:1568
msgid "No data received.\n"
msgstr "Tidak ada data yang diterima.\n"

#: src/http.c:1575
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Read error (%s) dalam headers.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1660
msgid "Unknown authentication scheme.\n"
msgstr "Skema authentifikasi tidak diketahui.\n"

#: src/http.c:1684
msgid "Authorization failed.\n"
msgstr "Authorisasi gagal.\n"

#: src/http.c:1698
msgid "Malformed status line"
msgstr "Status line salah format"

#: src/http.c:1700
msgid "(no description)"
msgstr "(tidak ada deskripsi)"

#: src/http.c:1763
#, c-format
msgid "Location: %s%s\n"
msgstr "Lokasi: %s%s\n"

#: src/http.c:1764 src/http.c:1871
msgid "unspecified"
msgstr "tidak dispesifikasikan"

#: src/http.c:1765
msgid " [following]"
msgstr " [mengikuti]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1821
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"     File sudah secara penuh diterima; tidak ada yang harus dilakukan lagi.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1851
msgid "Length: "
msgstr "Besar: "

#: src/http.c:1871
msgid "ignored"
msgstr "diabaikan"

#: src/http.c:2022
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Peringatan: wildcards tidak disupport dalam HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:2057
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ""
"File `%s' sudah ada; tidak diambil.\n"
"\n"

#: src/http.c:2247
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Tidak dapat menulis ke `%s' (%s).\n"

#. Another fatal error.
#: src/http.c:2254
msgid "Unable to establish SSL connection.\n"
msgstr "Tidak dapat membuat koneksi SSL.\n"

#: src/http.c:2263
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERROR: Redireksi (%d) tanpa lokasi.\n"

#: src/http.c:2293
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERROR %d: %s.\n"

#: src/http.c:2306
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Header yang paling akhir dimodifikasi hilang -- time-stamps dimatikan.\n"

#: src/http.c:2314
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "header yang paling akhir dimodifikasi tidak valid -- time-stamp diabaikan.\n"

#: src/http.c:2337
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"File server tidak ada yang lebih baru dari local file `%s' -- tidak diambil.\n"
"\n"

#: src/http.c:2345
#, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr "Besar tidak cocok (local %s) -- diambil.\n"

#: src/http.c:2350
msgid "Remote file is newer, retrieving.\n"
msgstr "File remote lebih baru, diambil.\n"

#: src/http.c:2390
#, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s]\n"
"\n"
msgstr ""
"%s (%s) - `%s' disimpan [%s/%s]\n"
"\n"

#: src/http.c:2447
#, c-format
msgid "%s (%s) - Connection closed at byte %s. "
msgstr "%s (%s) - Hubungan ditutup pada byte %s. "

#: src/http.c:2463
#, c-format
msgid "%s (%s) - Read error at byte %s (%s)."
msgstr "%s (%s) - Read error pada byte %s (%s)."

#: src/http.c:2473
#, c-format
msgid "%s (%s) - Read error at byte %s/%s (%s). "
msgstr "%s (%s) - Read error pada byte %s/%s (%s). "

#: src/init.c:368
#, c-format
msgid "%s: WGETRC points to %s, which doesn't exist.\n"
msgstr "%s: WGETRC menunjuk ke %s, dimana itu tidak ada.\n"

#: src/init.c:432 src/netrc.c:277
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Tidak dapat membaca %s (%s).\n"

#: src/init.c:450
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Error dalam %s pada baris %d.\n"

#: src/init.c:456
#, c-format
msgid "%s: Syntax error in %s at line %d.\n"
msgstr "%s: Syntax error dalam %s pada baris %d.\n"

#: src/init.c:461
#, c-format
msgid "%s: Unknown command `%s' in %s at line %d.\n"
msgstr "%s: Perintah tidak diketahui `%s' dalam %s pada baris %d.\n"

#: src/init.c:506
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Peringatan: Kedua sistem dan pengguna wgetrc menunjuk ke `%s'.\n"

#: src/init.c:660
#, c-format
msgid "%s: Invalid --execute command `%s'\n"
msgstr "%s: Invalid --execute command `%s'\n"

#: src/init.c:706
#, c-format
msgid "%s: %s: Invalid boolean `%s'; use `on' or `off'.\n"
msgstr "%s: %s: Boolean tidak valid `%s'; gunakan `on' atau `off'.\n"

#: src/init.c:758
#, c-format
msgid ""
"%s: %s: Invalid extended boolean `%s';\n"
"use one of `on', `off', `always', or `never'.\n"
msgstr ""
"%s: %s: Tidak valid extended boolean `%s';\n"
"gunakan salah satu dari `on', `off', `always', atau `newer'.\n"

#: src/init.c:776
#, c-format
msgid "%s: %s: Invalid number `%s'.\n"
msgstr "%s: %s: Nomor tidak valid `%s'.\n"

#: src/init.c:1007 src/init.c:1026
#, c-format
msgid "%s: %s: Invalid byte value `%s'\n"
msgstr "%s: %s: Nilai byte tidak valid `%s'\n"

#: src/init.c:1051
#, c-format
msgid "%s: %s: Invalid time period `%s'\n"
msgstr "%s: %s: Perioda waktu tidak valid `%s'\n"

#: src/init.c:1105 src/init.c:1195 src/init.c:1290 src/init.c:1315
#, c-format
msgid "%s: %s: Invalid value `%s'.\n"
msgstr "%s: %s: Nilai tidak valid `%s'.\n"

#: src/init.c:1142
#, c-format
msgid "%s: %s: Invalid header `%s'.\n"
msgstr "%s: %s: header tidak valid `%s'.\n"

#: src/init.c:1207
#, c-format
msgid "%s: %s: Invalid progress type `%s'.\n"
msgstr "%s: %s: Tipe progress tidak valid `%s'.\n"

#: src/init.c:1258
#, c-format
msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
msgstr "%s: %s: restriksi tidak valid `%s', gunakan `unix' atau `windows'.\n"

#: src/log.c:806
#, c-format
msgid ""
"\n"
"%s received, redirecting output to `%s'.\n"
msgstr ""
"\n"
"%s diterima, meneruskan output ke `%s'.\n"

#. Eek!  Opening the alternate log file has failed.  Nothing we
#. can do but disable printing completely.
#: src/log.c:816
#, c-format
msgid ""
"\n"
"%s received.\n"
msgstr ""
"\n"
"%s diterima.\n"

#: src/log.c:817
#, c-format
msgid "%s: %s; disabling logging.\n"
msgstr "%s: %s; mematikan logging.\n"

#: src/main.c:375
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Penggunaan: %s [OPSI]... [URL]...\n"

#: src/main.c:387
msgid ""
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"Argumen yang wajib untuk opsi panjang juga wajib untuk opsi yang pendek.\n"
"\n"

#: src/main.c:389
msgid "Startup:\n"
msgstr "Memulai:\n"

#: src/main.c:391
msgid "  -V,  --version           display the version of Wget and exit.\n"
msgstr "  -V,  --version           menampilkan versi dari Wget dan keluar.\n"

#: src/main.c:393
msgid "  -h,  --help              print this help.\n"
msgstr "  -h,  --help              menampilkan bantuan ini.\n"

#: src/main.c:395
msgid "  -b,  --background        go to background after startup.\n"
msgstr "  -b,  --background        pergi ke background setelah memulai.\n"

#: src/main.c:397
msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
msgstr "  -e,  --execute=COMMAND   menjalankan sebuah perintah `.wgetrc'-style.\n"

#: src/main.c:401
msgid "Logging and input file:\n"
msgstr "Logging dan input file:\n"

#: src/main.c:403
msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
msgstr "  -o,  --output-file=FILE     pesan log pada FILE.\n"

#: src/main.c:405
msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
msgstr "  -a,  --append-output=FILE  tambahkan pesan pada FILE.\n"

#: src/main.c:408
msgid "  -d,  --debug               print lots of debugging information.\n"
msgstr "  -d,  --debug               tampilkan banyak informasi debugging.\n"

#: src/main.c:411
msgid "  -q,  --quiet               quiet (no output).\n"
msgstr "  -q,  --quiet               diam (tidak ada output).\n"

#: src/main.c:413
msgid "  -v,  --verbose             be verbose (this is the default).\n"
msgstr "  -v,  --verbose             jadi verbose (ini yang default).\n"

#: src/main.c:415
msgid "  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
msgstr "   -nv, --no-verbose          matikan verboseness, tanpa menjadi quiet.\n"

#: src/main.c:417
msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
msgstr "  -i,  --input-file=FILE     download URLs yang ditemukan pada FILE.\n"

#: src/main.c:419
msgid "  -F,  --force-html          treat input file as HTML.\n"
msgstr "  -F,  --force-html          perlakukan input file sebagai HTML.\n"

#: src/main.c:421
msgid "  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
msgstr "  -B,  --base=URL            prepends URL pada link relatif dalam file -F -i.\n"

#: src/main.c:425
msgid "Download:\n"
msgstr "Download:\n"

#: src/main.c:427
msgid "  -t,  --tries=NUMBER            set number of retries to NUMBER (0 unlimits).\n"
msgstr "  -t,  --tries=NUMBER            set nomor mencoba ke NUMBER (0 untuk tidak terbatas).\n"

#: src/main.c:429
msgid "       --retry-connrefused       retry even if connection is refused.\n"
msgstr "       --retry-connrefused       coba lagi walaupun koneksi ditolak.\n"

#: src/main.c:431
msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
msgstr "  -O,  --output-document=FILE    tulis document pada FILE.\n"

#: src/main.c:433
msgid ""
"  -nc, --no-clobber              skip downloads that would download to\n"
"                                 existing files.\n"
msgstr ""
"  -nc, --no-clobber              skip downloads yang akan mendownload ke\n"
"                                 file yang sudah ada.\n"

#: src/main.c:436
msgid "  -c,  --continue                resume getting a partially-downloaded file.\n"
msgstr "  -c,  --continue                lanjutkan mengambil file yang terdownload  sebagian.\n"

#: src/main.c:438
msgid "       --progress=TYPE           select progress gauge type.\n"
msgstr "       --progress=TYPE           pilih tipe gauge progress.\n"

#: src/main.c:440
msgid ""
"  -N,  --timestamping            don't re-retrieve files unless newer than\n"
"                                 local.\n"
msgstr ""
"  -N,  --timestamping            jangan mengambil kembali file kecuali file\n"
"                                 lebih baru dari file local.\n"

#: src/main.c:443
msgid "  -S,  --server-response         print server response.\n"
msgstr "  -S,  --server-response         tampilkan respon server.\n"

#: src/main.c:445
msgid "       --spider                  don't download anything.\n"
msgstr "       --spider                  jangan mendownload apapun.\n"

#: src/main.c:447
msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
msgstr "  -T,  --timeout=SECONDS         set semua nilai timeout pada SECONDS.\n"

#: src/main.c:449
msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
msgstr "       --dns-timeout=SECS        set the DNS lookup timeout pada SECS.\n"

#: src/main.c:451
msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
msgstr "       --connect-timeout=SECS    set the connect timeout pada SECS.\n"

#: src/main.c:453
msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
msgstr "       --read-timeout=SECS       set the read timeout pada SECS.\n"

#: src/main.c:455
msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
msgstr "  -w,  --wait=SECONDS            tunggu SECONDS diantara pengambilan.\n"

#: src/main.c:457
msgid "       --waitretry=SECONDS       wait 1..SECONDS between retries of a retrieval.\n"
msgstr "       --waitretry=SECONDS       tunggu 1..SECONDS diantara pencobaan dari sebuah pengambilan.\n"

#: src/main.c:459
msgid "       --random-wait             wait from 0...2*WAIT secs between retrievals.\n"
msgstr "       --random-wait             tunggu dari 0...2*WAIT secs diantara pengambilan.\n"

#: src/main.c:461
msgid "  -Y,  --proxy                   explicitly turn on proxy.\n"
msgstr "  -Y,  --proxy                   secara eksplisit menggunakan proxy.\n"

#: src/main.c:463
msgid "       --no-proxy                explicitly turn off proxy.\n"
msgstr "       --no-proxy                secara eksplisit mematikan proxy.\n"

#: src/main.c:465
msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
msgstr "  -Q,  --quota=NUMBER            set pengambilan quota pada NUMBER.\n"

#: src/main.c:467
msgid "       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local host.\n"
msgstr "       --bind-address=ADDRESS    bind ke ADDRESS (hostname atau IP) pada local host.\n"

#: src/main.c:469
msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
msgstr "       --limit-rate=RATE         batasi kecepatan download ke RATE.\n"

#: src/main.c:471
msgid "       --no-dns-cache            disable caching DNS lookups.\n"
msgstr "       --no-dns-cache            matikan caching dari DNS lookups.\n"

#: src/main.c:473
msgid "       --restrict-file-names=OS  restrict chars in file names to ones OS allows.\n"
msgstr "       --restrict-file-names=OS  restrict karakter dalam nama file ke salah satu dari yang dibolehkan oleh OS.\n"

#: src/main.c:476
msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
msgstr "  -4,  --inet4-only              hanya menghubungi ke alamat IPv4 saja.\n"

#: src/main.c:478
msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
msgstr "  -6,  --inet6-only              hanya menghubungi ke alamat IPv6 saja.\n"

#: src/main.c:480
msgid ""
"       --prefer-family=FAMILY    connect first to addresses of specified family,\n"
"                                 one of IPv6, IPv4, or none.\n"
msgstr ""
"       --prefer-family=FAMILY    hubungi terlebih dahulu alamat dari family  yang dispesifikasikan,\n"
"                                 salah satu dari IPv6, IPv4 atau none.\n"

#: src/main.c:484
msgid "       --user=USER               set both ftp and http user to USER.\n"
msgstr "       --user=USER               set kedua ftp dan http user pada USER.\n"

#: src/main.c:486
msgid "       --password=PASS           set both ftp and http password to PASS.\n"
msgstr "       --password=PASS           set kedua ftp dan http password pada PASS.\n"

#: src/main.c:490
msgid "Directories:\n"
msgstr "Direktori:\n"

#: src/main.c:492
msgid "  -nd, --no-directories           don't create directories.\n"
msgstr "  -nd,  --no-directories          jangan membuat direktori.\n"

#: src/main.c:494
msgid "  -x,  --force-directories        force creation of directories.\n"
msgstr "  -x,  --force-directories        paksa pembuatan direktori.\n"

#: src/main.c:496
msgid "  -nH, --no-host-directories      don't create host directories.\n"
msgstr "  -nH, --no-host-directories      jangan buat host directories.\n"

#: src/main.c:498
msgid "       --protocol-directories     use protocol name in directories.\n"
msgstr "       --protocol-directories     gunakan nama protocol dalam direktori.\n"

#: src/main.c:500
msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
msgstr "  -P,  --directory-prefix=PREFIX  simpan file pada PREFIX/...\n"

#: src/main.c:502
msgid "       --cut-dirs=NUMBER          ignore NUMBER remote directory components.\n"
msgstr "       --cut-dirs=NUMBER           abaikan NUMBER remote komponen direktori.\n"

#: src/main.c:506
msgid "HTTP options:\n"
msgstr "Opsi HTTP:\n"

#: src/main.c:508
msgid "       --http-user=USER        set http user to USER.\n"
msgstr "       --http-user=USER        set http user pada USER.\n"

#: src/main.c:510
msgid "       --http-password=PASS    set http password to PASS.\n"
msgstr "       --http-password=PASS    set http password pada PASS.\n"

#: src/main.c:512
msgid "       --no-cache              disallow server-cached data.\n"
msgstr "       --nocache               dissallow server-cached data.\n"

#: src/main.c:514
msgid "  -E,  --html-extension        save HTML documents with `.html' extension.\n"
msgstr "  -E,  --html-extension        simpan HTML dokumen dengan ekstensi `.html'.\n"

#: src/main.c:516
msgid "       --ignore-length         ignore `Content-Length' header field.\n"
msgstr "       --ignore-length         abaikan `Content-Length' bagian header.\n"

#: src/main.c:518
msgid "       --header=STRING         insert STRING among the headers.\n"
msgstr "       --header=STRING         masukkan STRING dalam headers.\n"

#: src/main.c:520
msgid "       --proxy-user=USER       set USER as proxy username.\n"
msgstr "       --proxy-user=USER       set USER sebagai username proxy.\n"

#: src/main.c:522
msgid "       --proxy-password=PASS   set PASS as proxy password.\n"
msgstr "       --proxy-password=PASS   set PASS sebagai password proxy.\n"

#: src/main.c:524
msgid "       --referer=URL           include `Referer: URL' header in HTTP request.\n"
msgstr "       --referer=URL           masukkan `Referer: URL' header dalam HTTP request.\n"

#: src/main.c:526
msgid "       --save-headers          save the HTTP headers to file.\n"
msgstr "       --save-headers          simpan HTTP headers pada file.\n"

#: src/main.c:528
msgid "  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
msgstr "  -U,  --user-agent=AGENT      identifikasi sebagai AGEN daripada sebagai Wget/VERSION.\n"

#: src/main.c:530
msgid "       --no-http-keep-alive    disable HTTP keep-alive (persistent connections).\n"
msgstr "       --no-http-keep-alive    disable HTTP keep-alive (persistent koneksi).\n"

#: src/main.c:532
msgid "       --no-cookies            don't use cookies.\n"
msgstr "       --no-cookies            jangan menggunakan cookies.\n"

#: src/main.c:534
msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
msgstr "       --load-cookies=FILE     load cookies dari FILE sebelum session.\n"

#: src/main.c:536
msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
msgstr "       --save-cookies=FILE     simpan cookies pada FILE sesudah session.\n"

#: src/main.c:538
msgid "       --keep-session-cookies  load and save session (non-permanent) cookies.\n"
msgstr "       --keep-session-cookies  load dan simpan session (non-permanen) cookies.\n"

#: src/main.c:540
msgid "       --post-data=STRING      use the POST method; send STRING as the data.\n"
msgstr "       --post-data=STRING      gunakan metoda POST; kirim STRING sebagai data.\n"

#: src/main.c:542
msgid "       --post-file=FILE        use the POST method; send contents of FILE.\n"
msgstr "       --post-file=FILE        gunakan metoda POST; kirim isi dari FILE.\n"

#: src/main.c:547
msgid "HTTPS (SSL/TLS) options:\n"
msgstr "Opsi HTTPS (SSL/TLS):\n"

#: src/main.c:549
msgid ""
"       --secure-protocol=PR     choose secure protocol, one of auto, SSLv2,\n"
"                                SSLv3, and TLSv1.\n"
msgstr ""
"       --secure-protocol=PR     pilih secure protocolm salah satu dari auto,\n"
"                                SSLv2, SSLv3, dan TLSv1.\n"

#: src/main.c:552
msgid "       --no-check-certificate   don't validate the server's certificate.\n"
msgstr "       --no-check-certificate   jangan memvalidasi server certificate.\n"

#: src/main.c:554
msgid "       --certificate=FILE       client certificate file.\n"
msgstr "       --certificate=FILE       client certificate file.\n"

#: src/main.c:556
msgid "       --certificate-type=TYPE  client certificate type, PEM or DER.\n"
msgstr "       --certificate-type=TYPE  tipe sertifikate client, PEM atau DER.\n"

#: src/main.c:558
msgid "       --private-key=FILE       private key file.\n"
msgstr "       --private-key=FILE       private key file.\n"

#: src/main.c:560
msgid "       --private-key-type=TYPE  private key type, PEM or DER.\n"
msgstr "       --private-key-type=TYPE  tipe private key, PEM atau DER.\n"

#: src/main.c:562
msgid "       --ca-certificate=FILE    file with the bundle of CA's.\n"
msgstr "       --ca-certificate=FILE    file yang berisi CA's.\n"

#: src/main.c:564
msgid "       --ca-directory=DIR       directory where hash list of CA's is stored.\n"
msgstr "       --ca-directory=DIR       direktori dimana hash list dari CA's disimpan\n"

#: src/main.c:566
msgid "       --random-file=FILE       file with random data for seeding the SSL PRNG.\n"
msgstr "       --random-file=FILE       file dengan data acak untuk seeding SSL PRNG.\n"

#: src/main.c:568
msgid "       --egd-file=FILE          file naming the EGD socket with random data.\n"
msgstr "       --egd-file=FILE          penamaan file EGD socket dengan data random.\n"

#: src/main.c:573
msgid "FTP options:\n"
msgstr "Opsi FTP:\n"

#: src/main.c:575
msgid "       --ftp-user=USER         set ftp user to USER.\n"
msgstr "       --ftp-user=USER         set ftp user pada USER.\n"

#: src/main.c:577
msgid "       --ftp-password=PASS     set ftp password to PASS.\n"
msgstr "       --ftp-password=PASS     set ftp password pada PASS.\n"

#: src/main.c:579
msgid "       --no-remove-listing     don't remove `.listing' files.\n"
msgstr "       --no-remove-listing     jangan hapus file `.listing'.\n"

#: src/main.c:581
msgid "       --no-glob               turn off FTP file name globbing.\n"
msgstr "       --no-glob               matikan FTP nama file globbing.\n"

#: src/main.c:583
msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
msgstr "       --no-passive-ftp        disable the \"passive\" mode trasfer.\n"

#: src/main.c:585
msgid "       --retr-symlinks         when recursing, get linked-to files (not dir).\n"
msgstr "       --retr-symlinks         ketika berekursif, ambil linked-to files (bukan dir).\n"

#: src/main.c:587
msgid "       --preserve-permissions  preserve remote file permissions.\n"
msgstr "       --preserve-permissions  preserver remote file permissions.\n"

#: src/main.c:591
msgid "Recursive download:\n"
msgstr "Recursive download:\n"

#: src/main.c:593
msgid "  -r,  --recursive          specify recursive download.\n"
msgstr "  -r,  --recursive          spesifikasikan untuk mendownload rekursif.\n"

#: src/main.c:595
msgid "  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for infinite).\n"
msgstr "  -l,  --level=NUMBER      maksimum kedalaman rekursi (inf atau 0 untuk tak terhingga).\n"

#: src/main.c:597
msgid "       --delete-after       delete files locally after downloading them.\n"
msgstr "       --delete-after       delete files locally sesudah mendownloadnya.\n"

#: src/main.c:599
msgid "  -k,  --convert-links      make links in downloaded HTML point to local files.\n"
msgstr "  -k,  --conver-links       buat links dalam HTML yang didownload menunjuk ke file local.\n"

#: src/main.c:601
msgid "  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
msgstr "  -K,  --backup-converted   sebelum mengubah file X, backup sebagai X.orig.\n"

#: src/main.c:603
msgid "  -m,  --mirror             shortcut for -N -r -l inf --no-remove-listing.\n"
msgstr "  -m,  --mirror             shortcut untuk -N -r -l inf --no-remove-listing.\n"

#: src/main.c:605
msgid "  -p,  --page-requisites    get all images, etc. needed to display HTML page.\n"
msgstr "  -p,  --page-requisites    ambil semua gambar, dll. yang diperlukan untuk menampilkan file HTML.\n"

#: src/main.c:607
msgid "       --strict-comments    turn on strict (SGML) handling of HTML comments.\n"
msgstr "       --strict-comments    hidupkan strick (SGML) handling dari komentar HTML.\n"

#: src/main.c:611
msgid "Recursive accept/reject:\n"
msgstr "Recursive diterima/ditolak:\n"

#: src/main.c:613
msgid "  -A,  --accept=LIST               comma-separated list of accepted extensions.\n"
msgstr "  -A,  --accept=LIST               list yang dipisahkan oleh koma yang berisiekstensi yang diterima.\n"

#: src/main.c:615
msgid "  -R,  --reject=LIST               comma-separated list of rejected extensions.\n"
msgstr "  -R,  --reject=LIST               list yang dipisahkan oleh koma yang berisiekstensi yang ditolak.\n"

#: src/main.c:617
msgid "  -D,  --domains=LIST              comma-separated list of accepted domains.\n"
msgstr "  -D,  --domains=LIST              list yang dipisahkan oleh koma yang berisidomains yang dibolehkan.\n"

#: src/main.c:619
msgid "       --exclude-domains=LIST      comma-separated list of rejected domains.\n"
msgstr "       --exclude-domains=LIST      list yang dipisahkan oleh koma yang berisidomains yang direject/tolak.\n"

#: src/main.c:621
msgid "       --follow-ftp                follow FTP links from HTML documents.\n"
msgstr "       --follow-ftp                ikuti link FTP dari dokumen HTML.\n"

#: src/main.c:623
msgid "       --follow-tags=LIST          comma-separated list of followed HTML tags.\n"
msgstr "       --follow-tags=LIST          list yang dipisahkan oleh koma yang berisitag HTML yang diikuti\n"

#: src/main.c:625
msgid "       --ignore-tags=LIST          comma-separated list of ignored HTML tags.\n"
msgstr "       --ignore-tags=LIST          list yang dipisahkan oleh koma yang berisitag HTML yang diabaikan.\n"

#: src/main.c:627
msgid "  -H,  --span-hosts                go to foreign hosts when recursive.\n"
msgstr "  -H,  --span-hosts                pergi ke host asing ketika recursive.\n"

#: src/main.c:629
msgid "  -L,  --relative                  follow relative links only.\n"
msgstr "  -L,  --relative                  hanya mengikuti links relative saja.\n"

#: src/main.c:631
msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
msgstr "  -I,  --include-directories=LIST  list dari direktori yang dibolehkan.\n"

#: src/main.c:633
msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
msgstr "  -X,  --exclude-directories=LIST   list dari direktori yang diabaikan.\n"

#: src/main.c:635
msgid "  -np, --no-parent                 don't ascend to the parent directory.\n"
msgstr "  -np, --no-parent                 jangan merambah direktori atasnya.\n"

#: src/main.c:639
msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
msgstr "Laporkan bug dan saran kepada <bug-wget@gnu.org>.\n"

#: src/main.c:644
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, adalah sebuah non-interaktif network retriever.\n"

#: src/main.c:658
msgid "Copyright (C) 2005 Free Software Foundation, Inc.\n"
msgstr "Hak Cipta (C) 2005 Free Software Foundation, Inc.\n"

#: src/main.c:660
msgid ""
"This program is distributed in the hope that it will be useful,\n"
"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
"GNU General Public License for more details.\n"
msgstr ""
"Program ini didistribusikan dengan harapan akan berguna,\n"
"TIDAK TERDAPAT GARANSI; bahkan untuk PENJUALAN atau \n"
"KESESUIAN UNTUK TUJUAN TERTENTU. Lihat GNU General Public Licence\n"
"untuk informasi selengkapnya.\n"

#: src/main.c:665
msgid ""
"\n"
"Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
msgstr ""
"\n"
"Originalnya ditulis oleh Hrvoje Niksic <hniksic@xemacs.org>.\n"

#. #### Something nicer should be printed here -- similar to the
#. pre-1.5 `--help' page.
#: src/main.c:711 src/main.c:780 src/main.c:859
#, c-format
msgid "Try `%s --help' for more options.\n"
msgstr "Coba `%s --help' untuk informasi lebih lanjut.\n"

#: src/main.c:777
#, c-format
msgid "%s: illegal option -- `-n%c'\n"
msgstr "%s: illegal opsi -- `-n%c'\n"

#: src/main.c:830
#, c-format
msgid "Can't be verbose and quiet at the same time.\n"
msgstr "Tidak dapat verbose dan quiet pada waktu bersamaan.\n"

#: src/main.c:836
#, c-format
msgid "Can't timestamp and not clobber old files at the same time.\n"
msgstr "Tidak dapat timestamp dan tidak menclobber file lama pada waktu bersamaan.\n"

#: src/main.c:844
#, c-format
msgid "Cannot specify both --inet4-only and --inet6-only.\n"
msgstr "Tidak dapat menspesifikasikan berdua --inet4-only dan --inet6-only.\n"

#. No URL specified.
#: src/main.c:854
#, c-format
msgid "%s: missing URL\n"
msgstr "%s: hilang URL\n"

#: src/main.c:963
#, c-format
msgid "No URLs found in %s.\n"
msgstr "Tidak ada URLs yang ditemukan dalam %s.\n"

#: src/main.c:972
#, c-format
msgid ""
"\n"
"FINISHED --%s--\n"
"Downloaded: %s bytes in %d files\n"
msgstr ""
"\n"
"SELESAI --%s--\n"
"Terdownload: %s bytes dalam %d files\n"

#: src/main.c:979
#, c-format
msgid "Download quota (%s bytes) EXCEEDED!\n"
msgstr "Download quota (%s bytes) DILEWATI!\n"

#: src/mswindows.c:112
#, c-format
msgid "Continuing in background.\n"
msgstr "Melanjutkan di background.\n"

#: src/mswindows.c:304
#, c-format
msgid "Continuing in background, pid %lu.\n"
msgstr "Melanjutkan di background, pid %lu.\n"

#: src/mswindows.c:306 src/utils.c:351
#, c-format
msgid "Output will be written to `%s'.\n"
msgstr "Output akan ditulis pada `%s'.\n"

#: src/mswindows.c:474 src/mswindows.c:481
#, c-format
msgid "%s: Couldn't find usable socket driver.\n"
msgstr "%s: Tidak dapat mencari driver socket yang berguna.\n"

#: src/netrc.c:385
#, c-format
msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
msgstr "%s: %s:%d: peringatan: \"%s\" token terlihat sebelum nama mesin lainnya\n"

#: src/netrc.c:416
#, c-format
msgid "%s: %s:%d: unknown token \"%s\"\n"
msgstr "%s: %s:%d: token tidak diketahui \"%s\"\n"

#: src/netrc.c:480
#, c-format
msgid "Usage: %s NETRC [HOSTNAME]\n"
msgstr "Penggunaan: %s NETRC [HOSTNAME]\n"

#: src/netrc.c:490
#, c-format
msgid "%s: cannot stat %s: %s\n"
msgstr "%s: tidak dapat melihat statistik %s: %s\n"

#. Still not random enough, presumably because neither /dev/random
#. nor EGD were available.  Try to seed OpenSSL's PRNG with libc
#. PRNG.  This is cryptographically weak and defeats the purpose
#. of using OpenSSL, which is why it is highly discouraged.
#: src/openssl.c:121
msgid "WARNING: using a weak random seed.\n"
msgstr "PERINGATAN: menggunakan nilai random yang lemah.\n"

#: src/openssl.c:181
msgid "Could not seed PRNG; consider using --random-file.\n"
msgstr "Tidak dapat seed PRNG; pertimbangkan menggunakan --random-file.\n"

#. If the user has specified --no-check-cert, we still want to warn
#. him about problems with the server's certificate.
#: src/openssl.c:423
msgid "ERROR"
msgstr "ERROR"

#: src/openssl.c:423
msgid "WARNING"
msgstr "PERINGATAN"

#: src/openssl.c:431
#, c-format
msgid "%s: No certificate presented by %s.\n"
msgstr "%s: Tidak ada certificate yang di berikan oleh %s.\n"

#: src/openssl.c:462
#, c-format
msgid "%s: Certificate verification error for %s: %s\n"
msgstr "%s: Verifikasi Certificate salah untuk %s: %s\n"

#: src/openssl.c:489
#, c-format
msgid "%s: certificate common name `%s' doesn't match requested host name `%s'.\n"
msgstr "%s: certificate common name `%s' tidak cocok dengan yang diberikan oleh hostname `%s'.\n"

#: src/openssl.c:502
#, c-format
msgid "To connect to %s insecurely, use `--no-check-certificate'.\n"
msgstr "Untuk menghubungi %s secara tidak secure, gunakan `--no-check-certificate'.\n"

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
"%*s[ melewatkan %dK ]"

#: src/progress.c:410
#, c-format
msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
msgstr "spesifikasi dot style `%s' tidak valid; meninggalkan tanpa mengubahnya.\n"

#. If no clock was found, it means that clock_getres failed for
#. the realtime clock.
#: src/ptimer.c:176
#, c-format
msgid "Cannot get REALTIME clock frequency: %s\n"
msgstr "Tidak dapat memperoleh REALTIME clock frequency: %s\n"

#: src/recur.c:377
#, c-format
msgid "Removing %s since it should be rejected.\n"
msgstr "Menghapus %s karena ini seharusnya direject.\n"

#: src/res.c:394
#, c-format
msgid "Cannot open %s: %s"
msgstr "Tidak dapat membuka %s: %s"

#: src/res.c:544
msgid "Loading robots.txt; please ignore errors.\n"
msgstr "Menload file robot.txt; tolong hiraukan kesalahan.\n"

#: src/retr.c:645
#, c-format
msgid "Error parsing proxy URL %s: %s.\n"
msgstr "Salah dalam parsing proxy URL %s: %s.\n"

#: src/retr.c:653
#, c-format
msgid "Error in proxy URL %s: Must be HTTP.\n"
msgstr "Salah dalam proxy URL %s: Harus berupa HTTP.\n"

#: src/retr.c:740
#, c-format
msgid "%d redirections exceeded.\n"
msgstr "%d redirections exceeded.\n"

#: src/retr.c:865
msgid ""
"Giving up.\n"
"\n"
msgstr ""
"Menyerah.\n"
"\n"

#: src/retr.c:865
msgid ""
"Retrying.\n"
"\n"
msgstr ""
"Mencoba lagi.\n"
"\n"

#: src/url.c:626
msgid "No error"
msgstr "Tidak ada kesalahan"

#: src/url.c:628
msgid "Unsupported scheme"
msgstr "Skema tidak disupport"

#: src/url.c:630
msgid "Invalid host name"
msgstr "Host name tidak valid"

#: src/url.c:632
msgid "Bad port number"
msgstr "Nomor port tidak baik"

#: src/url.c:634
msgid "Invalid user name"
msgstr "User name tidak valid"

#: src/url.c:636
msgid "Unterminated IPv6 numeric address"
msgstr "Alamat numerik IPv6 tidak diselesaikan"

#: src/url.c:638
msgid "IPv6 addresses not supported"
msgstr "Pengalamatan IPv6 tidak disupport"

#: src/url.c:640
msgid "Invalid IPv6 numeric address"
msgstr "Alamat numerik IPv6 tidak valid"

#. parent, no error
#: src/utils.c:349
#, c-format
msgid "Continuing in background, pid %d.\n"
msgstr "Melanjutkan di background, pid %d.\n"

#: src/utils.c:397
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr "Gagal untuk meng-unlink symlink `%s': %s\n"

#: src/xmalloc.c:72
#, c-format
msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
msgstr "%s: %s: Gagal untuk mengalokasikan %ld bytes; kehabisan memori.\n"

#~ msgid "%s (%s) - Connection closed at byte %s/%s. "
#~ msgstr "%s (%s) - Hubungan ditutup pada byte %s/%s. "