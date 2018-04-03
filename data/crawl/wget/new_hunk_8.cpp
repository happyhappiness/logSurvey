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

# Create certindex
open  CERTID, ">", "$cdir/certs/certindex" or
      warn "Cannot overwrite file $cdir/certs/certindex";
close CERTID;

# Create certserial
open  CERTSN, ">", "$cdir/certs/certserial" or
      warn "Cannot overwrite file $cdir/certs/certserial";
print CERTSN "1122";
close CERTSN;

# Create crlnumber
open  CRLN, ">", "$cdir/certs/crlnumber" or
      warn "Cannot overwrite file $cdir/certs/crlnumber";
close CRLN;

my $caconf     = "$cdir/certs/rootca.conf";
my $cacrt      = "$cdir/certs/test-ca-cert.pem";
my $cakey      = "$cdir/certs/test-ca-key.pem";

# Prepare server certificate
my $servercrt  = "certs/tmpserver.crt";
my $serverkey  = "certs/tmpserver.key";
my $servercsr  = "$cdir/certs/tmpserver.csr";
my $serversubj = "/C=US/ST=CA/L=Server Mystery Spot/O=Serv/CN=".
                 "$testhostname/emailAddress=servertester";
my $servercmd  = "openssl genrsa -out $serverkey 4096 && openssl req -new".
                 " -sha256 -key $serverkey -out $servercsr -days 365 ".
                 " -subj \"$serversubj\" &&".
                 "openssl ca -batch -config $caconf -notext -in $servercsr".
                 " -out $servercrt";

system($servercmd);
my $servercheck =`(openssl x509 -noout -modulus -in $servercrt | openssl md5 ;
                   openssl rsa  -noout -modulus -in $serverkey | openssl md5) |
                   uniq | wc -l`;
# Check if certificate and key are made correctly.
unless(-e $servercrt && -e $serverkey && $servercheck == 1)
{
    exit 77; # skip
}

# Prepare client certifcate
my $clientcert     = "$cdir/certs/client.crt";
my $clientkey      = "$cdir/certs/client.key";
my $clientcsr      = "$cdir/certs/client.csr";
my $clientsubj     = "/C=US/ST=CA/L=Client Mystery Spot/O=Client/CN=".
                     "Client Tester/emailAddress=clienttester";
my $clientcertcmd  = "openssl genrsa  -out $clientkey 4096 &&".
                     " openssl req -new -key $clientkey -out $clientcsr".
                     "  -subj \"$clientsubj\" &&".
                     " openssl ca -config $caconf -in $clientcsr ".
                     "  -out $clientcert -batch";

system($clientcertcmd);
my $clientcheck=`(openssl x509 -noout -modulus -in $clientcert | openssl md5 ;
                  openssl rsa -noout -modulus -in $clientkey | openssl md5) |
                  uniq | wc -l`;

# Check if  signed certificate and key are made correctly.
unless(-e $clientcert && -e $clientkey && $clientcheck == 1)
{
    exit 77; # skip
}

# Try Wget using SSL with mismatched client cert & key . Expect error
my $cmdline = $WgetTest::WGETPATH . " --certificate=$clientcert ".
                                    " --private-key=$serverkey ".
                                    " --ca-certificate=$cacrt".
                                    " https://$testhostname:55443/somefile.txt";
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
                           certfile  => $servercrt,
                           keyfile   => $serverkey,
                           lhostname => $testhostname);
if ($sslsock->run() == 0)
{
  exit 0;
}

# Retry wget using SSL with client certificate. Expect success
$cmdline = $WgetTest::WGETPATH . " --certificate=$clientcert".
                                 " --private-key=$clientkey ".
                                 " --ca-certificate=$cacrt".
                                 " https://$testhostname:55443/somefile.txt";

$expected_error_code = 0;

my $retryssl = SSLTest->new(cmdline  => $cmdline,
                           input     => \%urls,
                           errcode   => $expected_error_code,
                           existing  => \%existing_files,
                           output    => \%expected_downloaded_files,
                           certfile  => $servercrt,
                           keyfile   => $serverkey,
                           lhostname => $testhostname);
exit $retryssl->run();
# vim: et ts=4 sw=4
