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

