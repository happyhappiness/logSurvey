EOT
}

sub find_documentation
{
    my ($push, $opt) = (shift, shift);
    my $info = [];

    my $opt_name = $opt->{'long_name'};
    for my $doc (@_) {
        next if $opt->{'deprecated'};
        if ($doc->{$opt_name}
            || ($opt_name !~ /^no/ && $doc->{"no-$opt_name"})) {
            push @$info, 1;
        } else {
            push @$info, 0;
        }
    }
    push @$push, [$opt_name, @$info] if grep {$_ eq 0} @$info;
}

sub emit_undocumented_opts
{
    my ($tex, $main, $opts) = @_;

    my (%tex_items, %main_items);
    while ($tex =~ /^\@item\w*? \s+? --([\w\-]+)/gmx) {
        $tex_items{$1} = true;
    }
    ($main) = $main =~ /(\nprint_help.*\n}\n)/s;
    while ($main =~ /--([-a-z0-9]+)/g) {
        $main_items{$1} = true;
    }
    my @options;
    foreach my $opt (@$opts) {
        find_documentation (\@options, $opt, \%tex_items, \%main_items);
    }

    local $" = "\n";
    print <<EOT;
Undocumented options          Not In:
====================          ==================
EOT
    for my $opt (@options) {
        printf("%-29s ", $opt->[0]);
        print 'texinfo ' unless $opt->[1];
        print 'nor ' unless $opt->[1] or $opt->[2];
        print '--help ' unless $opt->[2];
        print "\n";
    }
}

sub emit_undocumented_cmds
