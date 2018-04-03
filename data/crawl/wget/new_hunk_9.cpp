#!/usr/bin/env perl

use strict;
use warnings;

use SSLTest;

###############################################################################

# code, msg, headers, content
my %urls = (
    '/somefile.txt' => {
        code => "200",
        msg => "Dontcare",
        headers => {
            "Content-type" => "text/plain",
        },
        content => "blabla",
    },
);

my $cdir = $ENV{'PWD'};

# HOSTALIASES env variable allows us to create hosts file alias.
my $testhostname = "wgettesterr";
my $testhostfile = "$cdir/wgethosts";
open(my $fh, '>', $testhostfile);
print $fh "$testhostname 127.0.0.1\n";
close $fh;
$ENV{'HOSTALIASES'} = "$cdir/wgethosts";

# Prepare self-signed certifcates
my $certfile="tmpsscert.pem";
my $keyfile="tmpsskey.pem";
my $certsubj="/C=US/ST=CA/L=Mystery Spot/O=Dis/CN=$testhostname/emailAddress=tester";
my $sscertcmd="openssl req -x509 -nodes -newkey rsa:4096 -keyout $keyfile -out $certfile -days 365 -subj \"$certsubj\"";

system($sscertcmd);
my $sscheck=`(openssl x509 -noout -modulus -in $certfile | openssl md5 ;   openssl rsa -noout -modulus -in $keyfile | openssl md5) | uniq|wc -l`;

# Check if Self signed certificate and key are made correctly.
unless(-e $certfile && -e $keyfile && $sscheck == 1) {
    exit 77; # skip
}

# Try Wget using SSL first without --no-check-certificate. expect error
my $cmdline = $WgetTest::WGETPATH . " --ca-certificate=$cdir/certs/test-ca-cert.pem https://$testhostname:55443/somefile.txt";
my $expected_error_code = 5;
my %existing_files = (
);

my %expected_downloaded_files = (
  'somefile.txt' => {
    content => "blabla",
  },
);

my $sslsock = SSLTest->new(cmdline   => $cmdline,
                           input     => \%urls,
                           errcode   => $expected_error_code,
                           existing  => \%existing_files,
                           output    => \%expected_downloaded_files,
                           certfile  => $certfile,
                           keyfile   => $keyfile,
                           lhostname => $testhostname);
$sslsock->run();

# Retry the test with --no-check-certificate. expect success
$cmdline = $WgetTest::WGETPATH . " --no-check-certificate --ca-certificate=$cdir/certs/test-ca-cert.pem https://$testhostname:55443/somefile.txt";

$expected_error_code = 0;

my $retryssl = SSLTest->new(cmdline  => $cmdline,
                           input     => \%urls,
                           errcode   => $expected_error_code,
                           existing  => \%existing_files,
                           output    => \%expected_downloaded_files,
                           certfile  => $certfile,
                           keyfile   => $keyfile,
                           lhostname => $testhostname);
$retryssl->run();
# vim: et ts=4 sw=4
