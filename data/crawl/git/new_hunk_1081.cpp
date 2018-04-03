
 * "git gui" l10n to Portuguese.

 * When given an abbreviated object name that is not (or more
   realistically, "no longer") unique, we gave a fatal error
   "ambiguous argument".  This error is now accompanied by hints that
   lists the objects that begins with the given prefix.  During the
   course of development of this new feature, numerous minor bugs were
   uncovered and corrected, the most notable one of which is that we
   gave "short SHA1 xxxx is ambiguous." twice without good reason.

 * "git log rev^..rev" is an often-used revision range specification
   to show what was done on a side branch merged at rev.  This has
   gained a short-hand "rev^-1".  In general "rev^-$n" is the same as
   "^rev^$n rev", i.e. what has happened on other branches while the
   history leading to nth parent was looking the other way.

 * In recent versions of cURL, GSSAPI credential delegation is
   disabled by default due to CVE-2011-2192; introduce a configuration
   to selectively allow enabling this.
   (merge 26a7b23429 ps/http-gssapi-cred-delegation later to maint).


Performance, Internal Implementation, Development Support etc.

