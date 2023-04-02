#!/usr/bin/perl

print "Enter a string: ";
my $str = <STDIN>;
chomp($str);
my $rev_str = reverse($str);
if ($str eq $rev_str)
    print "The string is a palindrome!\n";
else
    print "The string is not a palindrome.\n";