"Content-Type: text/plain; charset=EUC-JP\n"
"Content-Transfer-Encoding: 8bit\n"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:147 src/http.c:346
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "%s:%hu に接続しています... "

#: src/ftp.c:169 src/ftp.c:411 src/http.c:363
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "%s:%hu への接続に失敗しました。\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:190 src/http.c:374
msgid "connected!\n"
msgstr "接続しました!\n"

#: src/ftp.c:191
#, c-format
msgid "Logging in as %s ... "
msgstr "%s としてログインしています... "

#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
msgid "Error in server response, closing control connection.\n"
msgstr "サーバの応答にエラーがあるので、接続を終了します。\n"

#: src/ftp.c:208
msgid "Error in server greeting.\n"
msgstr "サーバの初期応答にエラーがあります。\n"

#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
msgid "Write failed, closing control connection.\n"
msgstr "書き込みに失敗したので、接続を終了します。\n"

#: src/ftp.c:223
msgid "The server refuses login.\n"
msgstr "サーバがログインを拒否しました。\n"

#: src/ftp.c:230
msgid "Login incorrect.\n"
msgstr "ログインに失敗しました。\n"

#: src/ftp.c:237
msgid "Logged in!\n"
msgstr "ログインしました!\n"

#: src/ftp.c:270
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "`%c' は不明な種類なので、接続を終了します。\n"

#: src/ftp.c:283
msgid "done.  "
msgstr "完了しました。  "

#: src/ftp.c:289
msgid "==> CWD not needed.\n"
msgstr "==> CWD は必要ありません。\n"

#: src/ftp.c:317
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "`%s' というディレクトリはありません。\n\n"

#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1431
msgid "done.\n"
msgstr "完了しました。\n"

#. do not CWD
#: src/ftp.c:335
msgid "==> CWD not required.\n"
msgstr "==> CWD は必要ありません。\n"

#: src/ftp.c:369
msgid "Cannot initiate PASV transfer.\n"
msgstr "PASV転送の初期化ができません。\n"

#: src/ftp.c:373
msgid "Cannot parse PASV response.\n"
msgstr "PASVの応答を解析できません。\n"

#: src/ftp.c:387
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "%s:%hu への接続を試みています。\n"

#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
msgid "done.    "
msgstr "完了しました。    "

#: src/ftp.c:474
#, c-format
msgid "Bind error (%s).\n"
msgstr "バインドエラーです (%s)。\n"

#: src/ftp.c:490
msgid "Invalid PORT.\n"
msgstr "無効なポート番号です。\n"

#: src/ftp.c:537
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nRESTに失敗しました、最初から始めます。\n"

#: src/ftp.c:586
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "`%s' というファイルはありません。\n\n"

#: src/ftp.c:634
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "`%s' というファイルまたはディレクトリはありません。\n\n"

#: src/ftp.c:692 src/ftp.c:699
#, c-format
msgid "Length: %s"
msgstr "長さ: %s"

#: src/ftp.c:694 src/ftp.c:701
#, c-format
msgid " [%s to go]"
msgstr " [のこり %s]"

#: src/ftp.c:703
msgid " (unauthoritative)\n"
msgstr " (必ずしも正確ではありません)\n"

#: src/ftp.c:721
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s、接続を終了します。\n"

#: src/ftp.c:729
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - データ接続: %s; "

#: src/ftp.c:746
msgid "Control connection closed.\n"
msgstr "接続を終了します。\n"

#: src/ftp.c:764
msgid "Data transfer aborted.\n"
msgstr "データ転送を中断しました。\n"

#: src/ftp.c:830
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "ファイル `%s' はすでに存在するので、転送しません。\n"

#: src/ftp.c:896 src/http.c:922
#, c-format
msgid "(try:%2d)"
msgstr "(試行:%2d)"

#: src/ftp.c:955 src/http.c:1116
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' を保存しました [%ld]\n\n"

#: src/ftp.c:1001
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "一時ファイルをリストするために `%s' を使用します。\n"

#: src/ftp.c:1013
#, c-format
msgid "Removed `%s'.\n"
msgstr "`%s' を削除しました。\n"

#: src/ftp.c:1049
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "再帰する深さ %d が最大値を超過しています。深さは %d です。\n"

#: src/ftp.c:1096 src/http.c:1054
#, c-format
msgid "Local file `%s' is more recent, not retrieving.\n\n"
msgstr "ローカルファイル `%s' のほうが新しいので、転送しません。\n\n"

#: src/ftp.c:1102 src/http.c:1060
#, c-format
msgid "The sizes do not match (local %ld), retrieving.\n"
msgstr "大きさが合わないので(ローカルは %ld)、転送します。\n"

#: src/ftp.c:1119
msgid "Invalid name of the symlink, skipping.\n"
msgstr "不正なシンボリックリンク名なので、とばします。\n"

#: src/ftp.c:1136
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "すでに %s -> %s という正しいシンボリックリンクがあります\n\n"

#: src/ftp.c:1144
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "%s -> %s というシンボリックリンクを作成しています\n"

#: src/ftp.c:1155
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "シンボリックリンクに対応していないので、シンボリックリンク `%s' をとばします。\n"

#: src/ftp.c:1167
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "ディレクトリ `%s' をとばします。\n"

#: src/ftp.c:1176
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: 不明なまたは対応していないファイルの種類です。\n"

#: src/ftp.c:1193
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: 日付が壊れています。\n"

#: src/ftp.c:1213
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "深さが %d (最大 %d)なのでディレクトリを転送しません。\n"

#: src/ftp.c:1252
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "除外されているか含まれていないので `%s' に移動しません。\n"

#: src/ftp.c:1297
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "`%s' を除外します。\n"
