$pi = abs(atan2(0, -1));
for (1 .. 4) {
for (1 .. 4) {
$phi += $pi / 10;
$re = cos($phi);
$im = sin($phi);
$sign *= -1.0;
print "($re, $im)\n" x 11;
}
}
