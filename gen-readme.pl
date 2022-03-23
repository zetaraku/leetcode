#!/usr/bin/perl
use File::Basename;

my @fileinfo;

foreach my $filepath (<code/*>) {
  my $filename = basename($filepath);
  my ($no) = $filename =~ /^(\d+)/;
  my ($title, $link, $tc, $sc);

  open my $fd, '<', $filepath or die "Can't open $filepath: $!";
  while (<$fd>) {
    $title = $1 if m"^(?://|#|--) Title: (.*)$";
    $title =~ s/<Insert Problem Name>//;
    $link = $1 if m"^(?://|#|--) Link: (.*)$";
    $link =~ s/<Put the link to the problem here>//;
    $tc = $1 if m"^(?://|#|--) Time complexity: (.*)$";
    $sc = $1 if m"^(?://|#|--) Space complexity: (.*)$";
  }
  close $fd;

  push @fileinfo, {
    no => $no // 9999,
    title => $title || undef,
    link => $link || undef,
    filename => $filename,
    filepath => $filepath,
    tc => $tc // 'N/A',
    sc => $sc // 'N/A',
  };
}

print <<EOF;
# leetcode

My [LeetCode](https://leetcode.com/) submissions

## Index

| No. | Title | Code | Time complexity | Space complexity |
| ---:| ----- | ---- | --------------- | ---------------- |
EOF

foreach (sort { $a->{no} <=> $b->{no} } @fileinfo) {
  my $title = defined $_->{link} ? "[$_->{title}]($_->{link})" : "$_->{title}";
  my $code = "[$_->{filename}](./$_->{filepath})";

  print <<LINE;
| $_->{no} | $title | $code | `$_->{tc}` | `$_->{sc}` |
LINE
}
