//======================================================================
// RADIOGRAM templates
//======================================================================

#include "templates.h"

const char rg_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\
<html><head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\"><title>radiogram</title>\
<meta content=\"w1hkj\" name=\"author\">\
<style>\n\
F2{font-family: \"sans-serif\"; font-size: 10pt}\n\
F3{font-family: \"sans-serif\"; font-size: 14pt}\n\
F4{font-family: \"monospace\"; font-size: 12pt}\n\
F5{font-family: \"sans-serif\"; font-size: 16pt}\n\
</style>\n\
</head><body>\n\
<table style=\"text-align: left; width: 100%;\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">\n\
<table style=\"text-align: left; width: 100%; margin-left: auto; margin-right: auto;\" border=\"0\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">\n\
<div style=\"text-align: center;\"><font size=\"3\"><b>THE AMERICAN RADIO RELAY LEAGUE</b></font><br>\n\
</div>\n\
<div style=\"text-align: center;\"><font size=\"6\"><b>RADIOGRAM</b></font><br>\n\
</div>\n\
<div style=\"text-align: center;\"><font size=\"3\"><b>VIA AMATEUR RADIO<br>\n\
</b></font></div>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<table style=\"text-align: left; width: 100%;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center; width: 7%;\"><F2>NUMBER</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 14%;\"><F2>PRECEDENCE</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 7%;\"><F2>HX</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 20%;\"><F2>STATION OF ORIGIN</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 8%;\"><F2>CHECK</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 20%;\"><F2>PLACE OF ORIGIN</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 10%;\"><F2>TIME FILED</F2></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F2>DATE</F2></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:nbr:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:prec:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:hx:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:sta:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:ck:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:org:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:t1:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:d1:</F4></td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"4\" style=\"vertical-align: top;\">\n\
<F2>TO</F2><br>\n\
<F4>:to:</F4><br>\n\
</td>\n\
<td colspan=\"4\" style=\"vertical-align: top;\">\n\
<div style=\"text-align: center;\"><F2>THIS RADIO MESSAGE WAS RECEIVED AT</F2><br>\n\
</div>\n\
<F4>:rx:</F4><br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"8\" style=\"vertical-align: top;\"><F2>PHONE NUMBER</F2><br>\n\
<F4>:tel:</F4><br>\n\
</td>\n\
</tr>\
<tr>\
<td colspan=\"8\" style=\"vertical-align: top;\"><pre><F4>:msg:</F4></pre><br>\
<F4>:sig:</F4><br>\
</td>\
</tr>\
</tbody>\
</table>\
<table style=\"text-align: left; width: 100%;\" border=\"0\" cellpadding=\"2\" cellspacing=\"2\">\
<tbody>\
<tr>\
<td style=\"vertical-align: top;\"><br>\
<F2>:exp:</F2></td>\
</tr>\
</tbody>\
</table>\
</td>\
</tr>\
</tbody>\
</table>\
<br>\
</body></html>";

const char rg_html_fcopy_template[] = 
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\
<html><head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\"><title>radiogram</title>\
<meta content=\"w1hkj\" name=\"author\">\
<style>\n\
F2{font-family: \"sans-serif\"; font-size: 10pt}\n\
F3{font-family: \"sans-serif\"; font-size: 14pt}\n\
F4{font-family: \"monospace\"; font-size: 12pt}\n\
F5{font-family: \"sans-serif\"; font-size: 16pt}\n\
</style>\n\
</head><body>\n\
<table style=\"text-align: left; width: 100%;\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">\n\
<table style=\"text-align: left; width: 100%; margin-left: auto; margin-right: auto;\" border=\"0\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">\n\
<div style=\"text-align: center;\"><font size=\"3\"><b>THE AMERICAN RADIO RELAY LEAGUE</b></font><br>\n\
</div>\n\
<div style=\"text-align: center;\"><font size=\"6\"><b>RADIOGRAM</b></font><br>\n\
</div>\n\
<div style=\"text-align: center;\"><font size=\"3\"><b>VIA AMATEUR RADIO<br>\n\
</b></font></div>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<table style=\"text-align: left; width: 100%;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center; width: 7%;\"><F2>NUMBER</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 14%;\"><F2>PRECEDENCE</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 7%;\"><F2>HX</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 20%;\"><F2>STATION OF ORIGIN</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 8%;\"><F2>CHECK</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 20%;\"><F2>PLACE OF ORIGIN</F2></td>\n\
<td style=\"vertical-align: top; text-align: center; width: 10%;\"><F2>TIME FILED</F2></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F2>DATE</F2></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:nbr:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:prec:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:hx:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:sta:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:ck:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:org:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:t1:</F4></td>\n\
<td style=\"vertical-align: top; text-align: center;\"><F4>:d1:</F4></td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"4\" style=\"vertical-align: top;\">\n\
<F2>TO</F2><br>\n\
<F4>:to:</F4><br>\n\
</td>\n\
<td colspan=\"4\" style=\"vertical-align: top;\">\n\
<div style=\"text-align: center;\"><F2>THIS RADIO MESSAGE WAS RECEIVED AT</F2><br>\n\
</div>\n\
<F4>:rx:</F4><br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"8\" style=\"vertical-align: top;\"><F2>PHONE NUMBER</F2><br>\n\
<F4>:tel:</F4><br>\n\
</td>\n\
</tr>\
<tr>\
<td colspan=\"8\" style=\"vertical-align: top;\"><pre><F4>:msg:</F4></pre><br>\
<F4>:sig:</F4><br>\
</td>\
</tr>\
</tbody>\
</table>\
<table style=\"text-align: left; width: 100%;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\
<tbody>\
<tr>\
<td style=\"vertical-align: top; width: 50%\"><F2>ORIG - FROM / DATE/TIME</F2><br><F4>:ori:</F4></td>\
<td style=\"vertical-align: top; width: 50%\"><F2>DLVD - TO / DATE/TIME</F2><br><F4>:dlv:</F4></td>\
</tr>\
</tbody>\
</table>\
</td>\
</tr>\
</tbody>\
</table>\
<br>\
</body></html>";

const char rg_txt_template[] =
":nbr: :prec::hx: :sta: :ck: :org: :t1: :d1:\n\
:to:\n\
:tel::opn:\n\
BT\n\
:msg:\n\
BT\n\
:sig::op2:\n\
AR\n\
";

