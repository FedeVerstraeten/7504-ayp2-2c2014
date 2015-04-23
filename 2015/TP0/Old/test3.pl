#! /usr/bin/perl
#
# test3.pl - genera una secuencia de pares complejos rotando en
# incrementos de pi/10, generando un valor constante en la salida
# demodulada.
#
# $Id: test3.pl,v 1.3 2015/04/05 22:36:19 lesanti Exp $

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
