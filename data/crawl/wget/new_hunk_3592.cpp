#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.7.1-pre1\n"
"POT-Creation-Date: 2001-06-03 15:27+0200\n"
"PO-Revision-Date: 2001-08-17 16:29+0900\n"
"Last-Translator: Hiroshi Takekawa <takekawa@sr3.t.u-tokyo.ac.jp>\n"
"Language-Team: Japanese <ja@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=EUC-JP\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/cookies.c:588
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Set-Cookieのフィールド `%s' に間違いがあります。"

#: src/cookies.c:612
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Set-Cookie の文字 `%c' の部分に文法エラーがあります。\n"

#: src/cookies.c:620
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Set-Cookie:が途中で終ってしまっていて文法エラーになっています。\n"

#: src/cookies.c:1352
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "クッキーファイル `%s' を開けませんでした: %s\n"

#: src/cookies.c:1364
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "`%s' へ書き込めません: %s\n"

#: src/cookies.c:1368
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "`%s' を閉じる際にエラーが発生しました: %s\n"

#: src/ftp-ls.c:787
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "サポートしていないリスト形式です、UNIX形式と見て解釈してみます。\n"

#: src/ftp-ls.c:832 src/ftp-ls.c:834
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "/%s (%s:%d 上)の見出し(index)です"

#: src/ftp-ls.c:856
msgid "time unknown       "
msgstr "時間が不明です       "

#: src/ftp-ls.c:860
msgid "File        "
msgstr "ファイル        "

#: src/ftp-ls.c:863
msgid "Directory   "
msgstr "ディレクトリ   "

#: src/ftp-ls.c:866
msgid "Link        "
msgstr "リンク        "

#: src/ftp-ls.c:869
msgid "Not sure    "
msgstr "不確実    "

#: src/ftp-ls.c:887
#, c-format
msgid " (%s bytes)"
msgstr " (%s バイト)"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:150 src/http.c:624
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "%s:%hu に接続しています... "

#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "%s:%hu への接続は拒否されました。\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:193 src/http.c:652
msgid "connected!\n"
msgstr "接続しました!\n"

#: src/ftp.c:194
#, c-format
msgid "Logging in as %s ... "
msgstr "%s としてログインしています... "

#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
msgid "Error in server response, closing control connection.\n"
msgstr "サーバの応答にエラーがあるので、接続を終了します。\n"

#: src/ftp.c:211
msgid "Error in server greeting.\n"
msgstr "サーバの初期応答にエラーがあります。\n"

#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
msgid "Write failed, closing control connection.\n"
msgstr "書き込みに失敗したので、接続を終了します。\n"

#: src/ftp.c:226
msgid "The server refuses login.\n"
msgstr "サーバがログインを拒否しました。\n"

#: src/ftp.c:233
msgid "Login incorrect.\n"
msgstr "ログインに失敗しました。\n"

#: src/ftp.c:240
msgid "Logged in!\n"
msgstr "ログインしました!\n"

#: src/ftp.c:265
msgid "Server error, can't determine system type.\n"
msgstr "サーバエラーで、システムがなにか判別できません。\n"

#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
msgid "done.    "
msgstr "完了しました。    "

#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
msgid "done.\n"
msgstr "完了しました。\n"

#: src/ftp.c:353
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "`%c' は不明な種類なので、接続を終了します。\n"

#: src/ftp.c:366
msgid "done.  "
msgstr "完了しました。  "

#: src/ftp.c:372
msgid "==> CWD not needed.\n"
msgstr "==> CWD は必要ありません。\n"

#: src/ftp.c:445
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "`%s' というディレクトリはありません。\n\n"

#. do not CWD
#: src/ftp.c:463
msgid "==> CWD not required.\n"
msgstr "==> CWD は必要ありません。\n"

#: src/ftp.c:497
msgid "Cannot initiate PASV transfer.\n"
msgstr "PASV転送の初期化ができません。\n"

#: src/ftp.c:501
msgid "Cannot parse PASV response.\n"
msgstr "PASVの応答を解析できません。\n"

#: src/ftp.c:515
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "%s:%hu への接続を試みます。\n"

#: src/ftp.c:602
#, c-format
msgid "Bind error (%s).\n"
msgstr "バインドエラーです (%s)。\n"

#: src/ftp.c:618
msgid "Invalid PORT.\n"
msgstr "無効なポート番号です。\n"

#: src/ftp.c:671
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST が失敗しました。`%s' を切りつめはしません。\n"

#: src/ftp.c:678
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nRESTに失敗しました、最初から始めます。\n"

#: src/ftp.c:727
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "`%s' というファイルはありません。\n\n"

#: src/ftp.c:775
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "`%s' というファイルまたはディレクトリはありません。\n\n"

#: src/ftp.c:859 src/ftp.c:867
#, c-format
msgid "Length: %s"
msgstr "長さ: %s"

#: src/ftp.c:861 src/ftp.c:869
#, c-format
msgid " [%s to go]"
msgstr " [のこり %s]"

#: src/ftp.c:871
msgid " (unauthoritative)\n"
msgstr " (確証はありません)\n"

#: src/ftp.c:898
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s、接続を終了します。\n"

#: src/ftp.c:906
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - データ接続: %s; "

#: src/ftp.c:923
msgid "Control connection closed.\n"
msgstr "制御用の接続を切断します。\n"

#: src/ftp.c:941
msgid "Data transfer aborted.\n"
msgstr "データ転送を中断しました。\n"

#: src/ftp.c:1005
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "ファイル `%s' はすでに存在するので、取得しません。\n"

#: src/ftp.c:1075 src/http.c:1502
#, c-format
msgid "(try:%2d)"
msgstr "(試行:%2d)"

#: src/ftp.c:1139 src/http.c:1753
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' を保存しました [%ld]\n\n"

#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
#, c-format
msgid "Removing %s.\n"
msgstr "%s を削除しました。\n"

#: src/ftp.c:1221
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "一時ファイルをリストするために `%s' を使用します。\n"

#: src/ftp.c:1233
#, c-format
msgid "Removed `%s'.\n"
msgstr "`%s' を削除しました。\n"

#: src/ftp.c:1269
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "再帰する深さ %d が最大値を超過しています。深さは %d です。\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1330
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "サーバ側のファイルよりローカルのファイル `%s' の方が新しいか同じなので取得しません。\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1337
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "サーバ側のファイルの方がローカルのファイル `%s' より新しいので取得します。\n\n"

#. Sizes do not match
#: src/ftp.c:1344
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "サイズが合わないので(ローカルは %ld)、取得します。\n\n"

#: src/ftp.c:1361
msgid "Invalid name of the symlink, skipping.\n"
msgstr "不正なシンボリックリンク名なので、とばします。\n"

#: src/ftp.c:1378
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "すでに %s -> %s という正しいシンボリックリンクがあります\n\n"

#: src/ftp.c:1386
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "%s -> %s というシンボリックリンクを作成しています\n"

#: src/ftp.c:1397
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "シンボリックリンクに対応していないので、シンボリックリンク `%s' をとばします。\n"

#: src/ftp.c:1409
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "ディレクトリ `%s' をとばします。\n"

#: src/ftp.c:1418
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: 不明なまたは対応していないファイルの種類です。\n"

#: src/ftp.c:1445
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: 日付が壊れています。\n"

#: src/ftp.c:1466
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "深さが %d (最大 %d)なのでディレクトリを転送しません。\n"

#: src/ftp.c:1512
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "除外されているか含まれていないので `%s' に移動しません。\n"

#: src/ftp.c:1559
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "`%s' を除外します。\n"
