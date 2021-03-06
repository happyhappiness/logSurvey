/*
 * squid_ldap_match: lookup group membership in LDAP
 * 
 * Author: Flavio Pescuma <flavio@marasystems.com>
 *         MARA Systems AB, Sweden
 *
 * Based on squid_ldap_auth by Glen Newton
 * 
 * Dependencies: You need to get the OpenLDAP libraries
 * from http://www.openldap.org
 * 
 * License: squid_ldap_match is free software; you can redistribute it 
 * and/or modify it under the terms of the GNU General Public License 
 * as published by the Free Software Foundation; either version 2, 
 * or (at your option) any later version.
 *
 * Changes:
 * Version 2.0
 * 2002-01-22: Henrik Nordstrom <hno@marasystems.com>
 *		Added optional third query argument for search RDN
 * 2002-01-22: Henrik Nordstrom <hno@marasystems.com>
 *		Removed unused options, and fully changed name
 *		to squid_ldap_match.
 * Version 1.0
 * 2001-07-17: Flavio Pescuma <flavio@marasystems.com>
 *		Using the main function from squid_ldap_auth
 *		wrote squid_ldap_match. This program replaces 
 *		the %a and %v (ldapfilter.conf) from the filter 
 *		template supplied with -f with the two arguments 
 *		sent by squid. Returns OK if the ldap_search 
 *		using the composed filter succeeds.
 *
 * OLD Change: (from squid_ldap_auth.c)
 * 2001-05-02: Henrik Nordstrom <hno@squid-cache.org>
 *             - Support newer OpenLDAP 2.x libraries using the
 *	         revised Internet Draft API which unfortunately
 *               is not backwards compatible with RFC1823..
 * 2001-04-15: Henrik Nordstrom <hno@squid-cache.org>
 *             - Added command line option for basedn
 *             - Added the ability to search for the user DN
 * 2001-04-16: Henrik Nordstrom <hno@squid-cache.org>
 *             - Added -D binddn -w bindpasswd.
 * 2001-04-17: Henrik Nordstrom <hno@squid-cache.org>
 *             - Added -R to disable referrals
 *             - Added -a to control alias dereferencing
 * 2001-04-17: Henrik Nordstrom <hno@squid-cache.org>
 *             - Added -u, DN username attribute name
 * 2001-04-18: Henrik Nordstrom <hno@squid-cache.org>
 *             - Allow full filter specifications in -f
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <lber.h>
#include <ldap_cdefs.h>
#include <ldap.h>

/* Change this to your search base */
static char *basedn;
static char *searchfilter = NULL;
static char *binddn = NULL;
static char *bindpasswd = NULL;
static int searchscope = LDAP_SCOPE_SUBTREE;
static int persistent = 0;
static int noreferrals = 0;
static int debug = 0;
static int aliasderef = LDAP_DEREF_NEVER;

static int searchLDAP(LDAP * ld, char *group, char *user, char *grouprdn);

/* Yuck.. we need to glue to different versions of the API */

#if defined(LDAP_API_VERSION) && LDAP_API_VERSION > 1823
static int squid_ldap_errno(LDAP *ld)
{
    int err = 0;
    ldap_get_option(ld, LDAP_OPT_ERROR_NUMBER, &err);
    return err;
}
static void squid_ldap_set_aliasderef(LDAP *ld, int deref)
{
    ldap_set_option(ld, LDAP_OPT_DEREF, &deref);
}
static void squid_ldap_set_referrals(LDAP *ld, int referrals)
{
    int *value = referrals ? LDAP_OPT_ON : LDAP_OPT_OFF;
    ldap_set_option(ld, LDAP_OPT_REFERRALS, value);
}
#else
static int squid_ldap_errno(LDAP *ld)
{
    return ld->ld_errno;
}
static void squid_ldap_set_aliasderef(LDAP *ld, int deref)
{
    ld->ld_deref = deref;
}
static void squid_ldap_set_referrals(LDAP *ld, int referrals)
{
    if (referrals)
	ld->ld_options |= ~LDAP_OPT_REFERRALS;
    else
	ld->ld_options &= ~LDAP_OPT_REFERRALS;
}
#endif

int
main(int argc, char **argv)
{
    char buf[256];
    char *user, *group, *grouprdn;
    char *ldapServer;
    LDAP *ld = NULL;
    int tryagain,rc;

    setbuf(stdout, NULL);

    while (argc > 2 && argv[1][0] == '-') {
	char *value = "";
	char option = argv[1][1];
	switch(option) {
	case 'p':
	case 'R':
	    break;
	default:
	    if (strlen(argv[1]) > 2) {
		value = argv[1]+2;
	    } else {
		value = argv[2];
		argv++;
		argc--;
	    }
	    break;
	}
	argv++;
	argc--;
	switch(option) {
	case 'b':
		basedn = value;
		break;
	case 'f':
		searchfilter = value;
		break;
	case 's':
		if (strcmp(value, "base") == 0)
		    searchscope = LDAP_SCOPE_BASE;
		else if (strcmp(value, "one") == 0)
		    searchscope = LDAP_SCOPE_ONELEVEL;
		else if (strcmp(value, "sub") == 0)
		    searchscope = LDAP_SCOPE_SUBTREE;
		else {
		    fprintf(stderr, "squid_ldap_match: ERROR: Unknown search scope '%s'\n", value);
		    exit(1);
		}
		break;
	case 'a':
		if (strcmp(value, "never") == 0)
		    aliasderef = LDAP_DEREF_NEVER;
		else if (strcmp(value, "always") == 0)
		    aliasderef = LDAP_DEREF_ALWAYS;
		else if (strcmp(value, "search") == 0)
		    aliasderef = LDAP_DEREF_SEARCHING;
		else if (strcmp(value, "find") == 0)
		    aliasderef = LDAP_DEREF_FINDING;
		else {
		    fprintf(stderr, "squid_ldap_match: ERROR: Unknown alias dereference method '%s'\n", value);
		    exit(1);
		}
		break;
	case 'D':
		binddn = value;
		break;
	case 'w':
		bindpasswd = value;
		break;
	case 'p':
		persistent = !persistent;
		break;
	case 'R':
		noreferrals = !noreferrals;
		break;
	case 'd':
		debug = 1;
		break;
	default:
		fprintf(stderr, "squid_ldap_match: ERROR: Unknown command line option '%c'\n", option);
		exit(1);
	}
    }

    if (!basedn || !searchfilter || argc != 2) {
	fprintf(stderr, "Usage: squid_ldap_match [options] ldap_server_name\n\n");
	fprintf(stderr, "\t-b basedn (REQUIRED)\tbase dn under where to search\n");
	fprintf(stderr, "\t-f filter (REQUIRED)\tsearch filter pattern\n");
	fprintf(stderr, "\t-s base|one|sub\t\tsearch scope\n");
	fprintf(stderr, "\t-D binddn\t\tDN to bind as to perform searches\n");
	fprintf(stderr, "\t-w bindpasswd\t\tpassword for binddn\n");
	fprintf(stderr, "\t-p\t\t\tpersistent LDAP connection\n");
	fprintf(stderr, "\t-R\t\t\tdo not follow referrals\n");
	fprintf(stderr, "\t-a never|always|search|find\n\t\t\t\twhen to dereference aliases\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "\tIf you need to bind as a user to perform searches then use the\n\t-D binddn -w bindpasswd options\n\n");
	exit(1);
    }

    ldapServer = (char *) argv[1];

    while (fgets(buf, 256, stdin) != NULL) {
	user = strtok(buf, " \n\r");
	group = strtok(NULL, " \n\r");
	grouprdn = strtok(NULL, " \n\r");

	if (!user || !group) {
	    printf("ERR\n");
	    continue;
	}

	tryagain = 1;
recover:
	if (ld == NULL) {
	    if ((ld = ldap_init(ldapServer, LDAP_PORT)) == NULL) {
		fprintf(stderr, "\nUnable to connect to LDAP server:%s port:%d\n",
		    ldapServer, LDAP_PORT);
		exit(1);
	    }
	    squid_ldap_set_referrals(ld, !noreferrals);
	    squid_ldap_set_aliasderef(ld, aliasderef);
	}
	rc = ldap_simple_bind_s(ld, binddn, bindpasswd);
	if (rc != LDAP_SUCCESS) {
	    fprintf(stderr, "squid_ldap_match: WARNING, could not bind to binddn '%s'\n", ldap_err2string(rc));
	    exit(1);
	}
	if (debug) printf("Binding OK\n");
	if (searchLDAP(ld, group, user, grouprdn) != 0) {
	    if (tryagain) {
		tryagain = 0;
		ldap_unbind(ld);
		ld = NULL;
		goto recover;
	    }
	    printf("ERR\n");
	} else {
	    printf("OK\n");
	}
	if (!persistent || (squid_ldap_errno(ld) != LDAP_SUCCESS && squid_ldap_errno(ld) != LDAP_INVALID_CREDENTIALS)) {
	    ldap_unbind(ld);
	    ld = NULL;
	}
    }
    if (ld)
	ldap_unbind(ld);
    return 0;
}

static int
searchLDAP(LDAP * ld, char *group, char *member, char *grouprdn)
{
int rc;
char filter[256];
static char searchbase[256];
LDAPMessage *res = NULL;
LDAPMessage *entry;

  if (grouprdn)
    snprintf(searchbase, sizeof(searchbase), "%s,%s", grouprdn, basedn);
  else
    snprintf(searchbase, sizeof(searchbase), "%s", basedn);

  ldap_build_filter( filter, sizeof(filter), searchfilter, NULL, NULL, group, member, NULL );
  if (debug) printf("filter %s\n",filter);


  if (ldap_search_s(ld, searchbase , searchscope, filter, NULL, 1, &res) != LDAP_SUCCESS) {
      int rc = ldap_result2error(ld, res, 0);
      if (noreferrals && rc == LDAP_PARTIAL_RESULTS) { 
	  /* Everything is fine. This is expected when referrals
	   * are disabled.
	   */
      } else { 
	  fprintf(stderr, "squid_ldap_match: WARNING, LDAP search error '%s'\n", ldap_err2string(rc));
      } 
      ldap_msgfree(res);
      return 1;
  }
  entry = ldap_first_entry(ld, res);
  if (!entry) {
      ldap_msgfree(res);
      return 1;
  }

  ldap_msgfree(res);
  return 0;
}