// =====================================================================
//
// templates.cxx
//
// Author: Dave Freese, W1HKJ
// Copyright: 2010
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  It is
// copyright under the GNU General Public License.
//
// You should have received a copy of the GNU General Public License
// along with the program; if not, write to the Free Software
// Foundation, Inc.
// 59 Temple Place, Suite 330
// Boston, MA  02111-1307 USA
//
// =====================================================================

#include "templates.h"

//======================================================================
// ICS213
//======================================================================
// rtf ICS-213 template created from Open Office rich text format
// document.
// all occurances of '\ first substituted with '\\'
// all occurances of new line character substituted with "\n\" plus the
// new line character.
// resulting text is then wrapped in double quotes and the
// const char name[] = 
// or
// const char name * = is then added to the beginning of the text.

const char ics_rtf_template[] = \
"{\\rtf1\\ansi\\deff1\\adeflang1025\n\
{\\fonttbl{\\f0\\froman\\fprq2\\fcharset0 Liberation Serif{\\*\\falt Times New Roman};}{\\f1\\froman\\fprq2\\fcharset0 Times New Roman;}{\\f2\\fswiss\\fprq2\\fcharset0 Liberation Sans{\\*\\falt Arial};}{\\f3\\froman\\fprq2\\fcharset0 Times New Roman;}{\\f4\\fswiss\\fprq2\\fcharset0 Arial;}{\\f5\\fnil\\fprq2\\fcharset0 DejaVu Sans;}{\\f6\\fnil\\fprq2\\fcharset0 Tahoma Slashed;}{\\f7\\fnil\\fprq0\\fcharset0 Tahoma Slashed;}}\n\
{\\colortbl;\\red0\\green0\\blue0;\\red242\\green242\\blue242;\\red229\\green229\\blue229;\\red128\\green128\\blue128;}\n\
{\\stylesheet{\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\aspalpha\\rtlch\\afs24\\lang1025\\ltrch\\dbch\\af1\\langfe1033\\hich\\f1\\fs24\\lang1033\\loch\\f1\\fs24\\lang1033\\snext1 Normal;}\n\
{\\s2\\sb240\\sa120\\keepn\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\aspalpha\\rtlch\\af6\\afs28\\lang1025\\ltrch\\dbch\\af5\\langfe1033\\hich\\f2\\fs28\\lang1033\\loch\\f2\\fs28\\lang1033\\sbasedon1\\snext3 Heading;}\n\
{\\s3\\sa120\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\aspalpha\\rtlch\\afs24\\lang1025\\ltrch\\dbch\\af1\\langfe1033\\hich\\f1\\fs24\\lang1033\\loch\\f1\\fs24\\lang1033\\sbasedon1\\snext3 Body Text;}\n\
{\\s4\\sa120\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\aspalpha\\rtlch\\af7\\afs24\\lang1025\\ltrch\\dbch\\af1\\langfe1033\\hich\\f1\\fs24\\lang1033\\loch\\f1\\fs24\\lang1033\\sbasedon3\\snext4 List;}\n\
{\\s5\\sb120\\sa120\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\aspalpha\\rtlch\\af7\\afs24\\lang1025\\ai\\ltrch\\dbch\\af1\\langfe1033\\hich\\f1\\fs24\\lang1033\\i\\loch\\f1\\fs24\\lang1033\\i\\sbasedon1\\snext5 caption;}\n\
{\\s6\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\aspalpha\\rtlch\\af7\\afs24\\lang1025\\ltrch\\dbch\\af1\\langfe1033\\hich\\f1\\fs24\\lang1033\\loch\\f1\\fs24\\lang1033\\sbasedon1\\snext6 Index;}\n\
{\\s7\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\aspalpha\\rtlch\\afs24\\lang1025\\ltrch\\dbch\\af1\\langfe1033\\hich\\f1\\fs24\\lang1033\\loch\\f1\\fs24\\lang1033\\sbasedon1\\snext7 Table Contents;}\n\
{\\s8\\cf0\\qc{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\aspalpha\\rtlch\\afs24\\lang1025\\ab\\ltrch\\dbch\\af1\\langfe1033\\hich\\f1\\fs24\\lang1033\\b\\loch\\f1\\fs24\\lang1033\\b\\sbasedon7\\snext8 Table Heading;}\n\
{\\*\\cs10\\cf0\\rtlch\\af1\\afs24\\lang1033\\ltrch\\dbch\\af1\\langfe1033\\hich\\f1\\fs24\\lang1033\\loch\\f1\\fs24\\lang1033 Default Paragraph Font;}\n\
}\n\
{\\info{\\title GENERAL MESSAGE}{\\author Dave, W1HKJ}{\\creatim\\yr2009\\mo9\\dy25\\hr15\\min10}{\\author Dave, W1HKJ}{\\revtim\\yr2009\\mo9\\dy25\\hr15\\min10}{\\printim\\yr0\\mo0\\dy0\\hr0\\min0}{\\comment StarWriter}{\\vern3000}}\\deftab720\n\
{\\*\\pgdsctbl\n\
{\\pgdsc0\\pgdscuse195\\pgwsxn12240\\pghsxn15840\\marglsxn1800\\margrsxn1800\\margtsxn1440\\margbsxn1440\\pgdscnxt0 Standard;}}\n\
{\\*\\pgdscno0}\\paperh15840\\paperw12240\\margl1800\\margr1800\\margt1440\\margb1440\\sectd\\sbknone\\pgwsxn12240\\pghsxn15840\\marglsxn1800\\margrsxn1800\\margtsxn1440\\margbsxn1440\\ftnbj\\ftnstart1\\ftnrstcont\\ftnnar\\aenddoc\\aftnrstcont\\aftnstart1\\aftnnrlc\n\
\\trowd\\trql\\trleft0\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl10\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr10\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\clcbpat2\\cellx8619\n\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s1\\cf0\\qc{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 GENERAL MESSAGE}\n\
\\cell\\row\\pard \\trowd\\trql\\trleft0\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl10\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr10\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\cellx4148\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx8619\n\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 TO:\\tab <to:}\n\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 POSITION:\\tab <p1:}\n\
\\cell\\row\\pard \\trowd\\trql\\trleft0\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl10\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr10\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\cellx4148\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx8619\n\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 FROM: \\tab <fm:}\n\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 POSITION:\\tab <p2:}\n\
\\cell\\row\\pard \\trowd\\trql\\trleft0\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl10\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr10\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\cellx4148\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\cellx6380\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx8619\n\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 SUBJ: \\tab <sb:}\n\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 DATE:\\tab <d1:}\n\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 TIME:\\tab <t1:}\n\
\\cell\\row\\pard \\trowd\\trql\\trleft0\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl10\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr10\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\clcbpat3\\cellx8619\n\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 MESSAGE:}\n\
\\cell\\row\\pard \\trowd\\trql\\trleft0\\trrh4752\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl10\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr10\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx8619\n\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 <mg:}\n\
\\cell\\row\\pard \\trowd\\trql\\trleft0\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl10\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr10\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\cellx4431\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx8619\n\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 SIGNATURE:}\n\
\\par \\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 <s1:}\n\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 POSITION:}\n\
\\par \\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 <p3:}\n\
\\cell\\row\\pard \\trowd\\trql\\trleft0\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl10\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr10\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\clcbpat3\\cellx8619\n\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 REPLY:}\n\
\\cell\\row\\pard \\trowd\\trql\\trleft0\\trrh4680\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl10\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr10\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx8619\n\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 <rp:}\n\
\\cell\\row\\pard \\trowd\\trql\\trleft0\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl10\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr10\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\cellx1733\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\cellx3429\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx8619\n\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 DATE:}\n\
\\par \\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 <d2:}\n\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 TIME:}\n\
\\par \\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 <t2:}\n\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 SIGNATURE/POSITION:}\n\
\\par \\pard\\plain \\intbl\\ltrpar\\s1\\cf0{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\ql\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs20\\lang1033\\i0\\b0 <s2: / <p4:}\n\
\\cell\\row\\pard \\pard\\plain \\ltrpar\\s1\\cf0\\qj{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\rtlch\\af4\\afs20\\lang1025\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs20\\lang1033\\loch\\f4\\fs20\\lang1033 \n\
\\par }\n\
";

// rtf formated new line
// rtf substitute for the '\n' character in C++ string
// used to modify the body of the message or reply section. 

const char nuline[] = "\\line ";

// ICS213 HTML TEMPLATE
const char ics_html_template[] =
"<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\" \"http://www.w3.org/TR/html4/strict.dtd\">\n\
<html><head><meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\"><title>ics_html_template</title></head><body>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr align=\"center\">\n\
<td colspan=\"3\" style=\"vertical-align: top; background-color: rgb(238, 238, 238);\"><big><span style=\"font-weight: bold;\"><br>\n\
GENERAL MESSAGE</span></big><br>\n\
(ics-213)<br>\n\
<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">TO: <to:<br>\n\
</td>\n\
<td style=\"vertical-align: top; width: 50%;\" colspan=\"2\">POSITION: <p1:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">FROM: <fm:<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">POSITION: <p2:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">SUBJ: <sb:<br>\n\
</td>\n\
<td style=\"vertical-align: top; width: 25%;\">DATE: <d1:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">TIME: <t1:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"3\" style=\"vertical-align: top; background-color: rgb(238, 238, 238);\">MESSAGE:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"3\" style=\"vertical-align: top;\"><mg:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">SIGNATURE: <s1:<br>\n\
</td>\n\
<td colspan=\"2\" style=\"vertical-align: top;\">POSITION: <p3:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"3\" style=\"vertical-align: top; background-color: rgb(238, 238, 238);\">REPLY:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td colspan=\"3\" style=\"vertical-align: top;\"><rp:<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">\n\
<table style=\"text-align: left; width: 100%;\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 50%; height: 100%;\">DATE:<br>\n\
<d2:<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">TIME:<br>\n\
<t2:<br>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</td>\n\
<td style=\"vertical-align: top;\" colspan=\"2\">SIGNATURE/POSITION:<br>\n\
<s2:/<p4:<br>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
</body></html>\
";

const char ics_text_template[] = \
"ICS 213 GENERAL MESSAGE\n\n\
TO: <to:\n\
FROM: <fm:\n\
SUBJ: <sb:\n\
TIME: <t1:\n\
MESSAGE:\n\
<mg:\n\
SIGNATURE: <s1:\n\
POSITION: <p3:\n\
REPLY:\n\
<rp:\n\
DATE: <d2:\n\
TIME: <t2:\n\
SIGNATURE: <s2:\n\
POSITION: <p4:\n";

//======================================================================
// RADIOGRAM
//======================================================================
const char rg_html_template[] = \
"<html>\n\
<head>\n\
<meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\n\
<title>rg_html_template</title>\n\
</head>\n\
<body>\n\
<table style=\"text-align: left; width: 1000px; \" border=\"0\" cellpadding=\"0\" cellspacing=\"2\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">\n\
<div style=\"text-align: center;\"><font size=\"3\"><b>THE AMERICAN RADIO RELAY LEAGUE</b></font><br>\n\
<font size=\"6\"><b>RADIOGRAM</b></font><br>\n\
<font size=\"3\"><b>VIA AMATEUR RADIO</b></font><br>\n\
<br>\n\
</div>\n\
<table style=\"width: 1000px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 8%;\">NR</td>\n\
<td style=\"vertical-align: top; width: 17%;\">PREC</td>\n\
<td style=\"vertical-align: top; width: 15%;\">HX__</td>\n\
<td style=\"vertical-align: top; width: 10%;\">STN ORIG</td>\n\
<td style=\"vertical-align: top; width: 8%;\">CK</td>\n\
<td style=\"vertical-align: top; width: 22%;\">PLACE OF ORIGIN</td>\n\
<td style=\"vertical-align: top; width: 12%;\">TIME FILED</td>\n\
<td style=\"vertical-align: top; width: 8%;\">MON DY</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><nbr:<br></td>\n\
<td style=\"vertical-align: top;\"><prec:<br></td>\n\
<td style=\"vertical-align: top;\"><hx:<hn:<br></td>\n\
<td style=\"vertical-align: top;\"><sta:<br></td>\n\
<td style=\"vertical-align: top;\"><ck:<br></td>\n\
<td style=\"vertical-align: top;\"><org:<br></td>\n\
<td style=\"vertical-align: top;\"><t1:<br></td>\n\
<td style=\"vertical-align: top;\"><d1:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">TO<br>\n\
</td>\n\
<td style=\"vertical-align: top;\">THIS RADIO MESSAGE WAS RECEIVED AT<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 50%\"><to:<br>\n\
</td>\n\
<td style=\"vertical-align: top; width: 50%;\"><rx:<br>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">TELEPHONE NUMBER<br>\n\
</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><tel:<br>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"2\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">\n\
<p><msg:</p>\n\
<p><sig:</p>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
</body></html>";

const char rg_html_fcopy_template[] = 
"<html>\n\
<head>\n\
<meta content=\"text/html; charset=ISO-8859-1\" http-equiv=\"content-type\">\n\
<title>rg_html_template</title>\n\
</head>\n\
<body>\n\
<table style=\"text-align: left; width: 1000px; \" border=\"0\" cellpadding=\"0\" cellspacing=\"2\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">\n\
<div style=\"text-align: center;\"><font size=\"3\"><b>THE AMERICAN RADIO RELAY LEAGUE</b></font><br>\n\
<font size=\"6\"><b>RADIOGRAM</b></font><br>\n\
<font size=\"3\"><b>VIA AMATEUR RADIO</b></font><br>\n\
<font size=\"2\"><b>FILE COPY</b></font><br>\n\
<br>\n\
</div>\n\
<table style=\"width: 1000px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 8%;\">NR</td>\n\
<td style=\"vertical-align: top; width: 17%;\">PREC</td>\n\
<td style=\"vertical-align: top; width: 15%;\">HX__</td>\n\
<td style=\"vertical-align: top; width: 10%;\">STN ORIG</td>\n\
<td style=\"vertical-align: top; width: 8%;\">CK</td>\n\
<td style=\"vertical-align: top; width: 22%;\">PLACE OF ORIGIN</td>\n\
<td style=\"vertical-align: top; width: 12%;\">TIME FILED</td>\n\
<td style=\"vertical-align: top; width: 8%;\">MON DY</td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><nbr:<br></td>\n\
<td style=\"vertical-align: top;\"><prec:<br></td>\n\
<td style=\"vertical-align: top;\"><hx:<hn:<br></td>\n\
<td style=\"vertical-align: top;\"><sta:<br></td>\n\
<td style=\"vertical-align: top;\"><ck:<br></td>\n\
<td style=\"vertical-align: top;\"><org:<br></td>\n\
<td style=\"vertical-align: top;\"><t1:<br></td>\n\
<td style=\"vertical-align: top;\"><d1:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; width 50%;\">TO<br></td>\n\
<td style=\"vertical-align: top; width 50%;\">THIS RADIO MESSAGE WAS RECEIVED AT<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 50%;\"><to:<br></td>\n\
<td style=\"vertical-align: top; width: 50%;\"><rx:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">TEL<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\"><tel:<br></td>\n\
</tr>\n\
<tr>\n\
<td style=\"vertical-align: top;\">OP NOTE <opn:<br></td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top;\">\n\
<p><msg:</p>\n\
<p><sig: OP NOTE <op2:</p>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 15%;\">FROM<br><rfm:</td>\n\
<td style=\"vertical-align: top; width: 15%;\">NET<br><rnt:</td>\n\
<td style=\"vertical-align: top; width: 20%;\">DATE/TIME<br><dt2:</td>\n\
<td style=\"vertical-align: top; wisth: 15%;\">SENT TO<br><sto:</td>\n\
<td style=\"vertical-align: top; width: 15%;\">NET<br><snt:</td>\n\
<td style=\"vertical-align: top; width: 20%;\">DATE/TIME<br><dt3:</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<table style=\"text-align: left; width: 1000px;\" border=\"1\" cellpadding=\"0\" cellspacing=\"0\">\n\
<tbody>\n\
<tr>\n\
<td style=\"vertical-align: top; width: 500px\">ORIG - FROM / DATE/TIME<br><ori:</td>\n\
<td style=\"vertical-align: top; width: 500px\">DLVD - to / DATE/TIME<br><dlv:</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
</td>\n\
</tr>\n\
</tbody>\n\
</table>\n\
<br>\n\
</body></html>";

const char rg_rtf_template[] = "\
{\\rtf1\\ansi\\deff1\\adeflang1025\
{\\fonttbl{\\f0\\froman\\fprq2\\fcharset0 Liberation Serif{\\*\\falt Times New Roman};}{\\f1\\froman\\fprq2\\fcharset0 Times New Roman;}{\\f2\\fswiss\\fprq2\\fcharset0 Arial;}{\\f3\\froman\\fprq2\\fcharset0 Times New Roman;}{\\f4\\fswiss\\fprq2\\fcharset0 Liberation Sans{\\*\\falt Arial};}}\
{\\colortbl;\\red0\\green0\\blue0;\\red128\\green128\\blue128;}\
{\\stylesheet{\\s1\\aspalpha\\rtlch\\afs24\\lang255\\ltrch\\dbch\\langfe1033\\hich\\fs24\\lang1033\\loch\\fs24\\lang1033\\snext1 Normal;}\
{\\s2\\sb240\\sa120\\keepn\\aspalpha\\rtlch\\af4\\afs28\\lang255\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs28\\lang1033\\loch\\f4\\fs28\\lang1033\\sbasedon1\\snext3 Heading;}\
{\\s3\\sa120\\aspalpha\\rtlch\\afs24\\lang255\\ltrch\\dbch\\langfe1033\\hich\\fs24\\lang1033\\loch\\fs24\\lang1033\\sbasedon1\\snext3 Body Text;}\
{\\s4\\sa120\\aspalpha\\rtlch\\afs24\\lang255\\ltrch\\dbch\\langfe1033\\hich\\fs24\\lang1033\\loch\\fs24\\lang1033\\sbasedon3\\snext4 List;}\
{\\s5\\sb120\\sa120\\aspalpha\\rtlch\\afs24\\lang255\\ai\\ltrch\\dbch\\langfe1033\\hich\\fs24\\lang1033\\i\\loch\\fs24\\lang1033\\i\\sbasedon1\\snext5 caption;}\
{\\s6\\aspalpha\\rtlch\\afs24\\lang255\\ltrch\\dbch\\langfe1033\\hich\\fs24\\lang1033\\loch\\fs24\\lang1033\\sbasedon1\\snext6 Index;}\
{\\s7\\sb120\\sa120\\aspalpha\\rtlch\\afs24\\lang255\\ai\\ltrch\\dbch\\langfe1033\\hich\\fs24\\lang1033\\i\\loch\\fs24\\lang1033\\i\\sbasedon1\\snext7 caption;}\
{\\s8\\sb120\\sa120\\aspalpha\\rtlch\\afs24\\lang255\\ai\\ltrch\\dbch\\langfe1033\\hich\\fs24\\lang1033\\i\\loch\\fs24\\lang1033\\i\\sbasedon1\\snext8 WW-caption;}\
{\\s9\\sb120\\sa120\\aspalpha\\rtlch\\afs24\\lang255\\ai\\ltrch\\dbch\\langfe1033\\hich\\fs24\\lang1033\\i\\loch\\fs24\\lang1033\\i\\sbasedon1\\snext9 WW-caption1;}\
{\\s10\\sb120\\sa120\\aspalpha\\rtlch\\afs24\\lang255\\ai\\ltrch\\dbch\\langfe1033\\hich\\fs24\\lang1033\\i\\loch\\fs24\\lang1033\\i\\sbasedon1\\snext10 WW-caption11;}\
{\\s11\\aspalpha\\rtlch\\afs24\\lang255\\ltrch\\dbch\\langfe1033\\hich\\fs24\\lang1033\\loch\\fs24\\lang1033\\sbasedon1\\snext11 Table Contents;}\
{\\s12\\qc\\aspalpha\\rtlch\\afs24\\lang255\\ab\\ltrch\\dbch\\langfe1033\\hich\\fs24\\lang1033\\b\\loch\\fs24\\lang1033\\b\\sbasedon11\\snext12 Table Heading;}\
{\\*\\cs14\\rtlch\\afs24\\lang255\\ltrch\\dbch\\langfe1033\\hich\\fs24\\lang1033\\loch\\fs24\\lang1033 Default Paragraph Font;}\
}\
{\\info{\\title GENERAL MESSAGE}{\\author Dave}{\\creatim\\yr2010\\mo5\\dy9\\hr3\\min22}{\\revtim\\yr2010\\mo5\\dy9\\hr3\\min47}{\\printim\\yr0\\mo0\\dy0\\hr0\\min0}{\\comment StarWriter}{\\vern3000}}\\deftab720\
{\\*\\pgdsctbl\
{\\pgdsc0\\pgdscuse195\\pgwsxn12240\\pghsxn15840\\marglsxn720\\margrsxn720\\margtsxn1440\\margbsxn720\\pgdscnxt0 Standard;}}\
{\\*\\pgdscno0}\\paperh15840\\paperw12240\\margl720\\margr720\\margt1440\\margb720\\sectd\\sbknone\\pgwsxn12240\\pghsxn15840\\marglsxn720\\margrsxn720\\margtsxn1440\\margbsxn720\\ftnbj\\ftnstart1\\ftnrstcont\\ftnnar\\aenddoc\\aftnrstcont\\aftnstart1\\aftnnrlc\
\\trowd\\trql\\trleft3\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl115\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr115\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx10800\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s1\\qc\\aspalpha\\li14\\ri0\\lin14\\rin0\\fi0\\sb60\\sa60\\rtlch\\afs24\\lang255\\ltrch\\dbch\\langfe1033\\hich\\fs24\\lang1033\\loch\\fs24\\lang1033{\\rtlch \\ltrch\\loch\\f1\\fs24\\lang1033\\i0\\b0{\\rtlch\\ltrch\\hich\\b\\loch\\b THE AMERICAN RADIO RELAY LEAGUE}}{\\rtlch \\ltrch\\loch\\f1\\fs24\\lang1033\\i0\\b0 \\line {\\rtlch\\ltrch\\hich\\fs48\\b\\loch\\fs48\\b RADIOGRAM}\\line {\\rtlch\\ltrch\\hich\\fs20\\loch\\fs20 VIA AMATEUR RADIO}}\
\\cell\\row\\pard \\trowd\\trql\\trleft3\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl115\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr115\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx1050\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx2675\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx3740\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx5753\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx6764\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx8980\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx9900\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx10800\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s1\\qj\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 NUMBER}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\qj\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 PRECEDENCE}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\qj\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 HX}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\ql\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 STATION OF ORIGIN}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\qj\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 CHECK}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\qj\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 PLACE OF ORIGIN}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\qj\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 TIME}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\qj\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 DATE}\
\\cell\\row\\pard \\trowd\\trql\\trleft3\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl115\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr115\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx1050\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx2675\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx3740\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx5753\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx6764\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx8980\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx9900\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx10800\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s1\\ql\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 <nbr:}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\ql\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 <prec:}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\ql\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 <hx:}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\ql\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 <sta:}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\ql\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 <ck:}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\ql\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 <org:}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\ql\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 <t1:}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\aspalpha\\ql\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 <d1:}\
\\cell\\row\\pard \\pard\\plain \\ltrpar\\s1\\qj\\rtlch\\af2\\afs20\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs20\\lang1033\\loch\\f2\\fs20\\lang1033 \
\\par \\trowd\\trql\\trleft3\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl115\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr115\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx5402\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx10800\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s1\\qj\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 TO}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\qj\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 THIS RADIO MESSAGE WAS RECEIVED AT}\
\\cell\\row\\pard \\trowd\\trql\\trleft3\\trpaddft3\\trpaddt0\\trpaddfl3\\trpaddl115\\trpaddfb3\\trpaddb0\\trpaddfr3\\trpaddr115\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx5402\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx10800\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s1\\ql\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 <to:}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s1\\aspalpha\\ql\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 <rx:}\
\\cell\\row\\pard \\pard\\plain \\ltrpar\\s1\\qj\\rtlch\\af2\\afs20\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs20\\lang1033\\loch\\f2\\fs20\\lang1033 \
\\par \\pard\\plain \\ltrpar\\s1\\qj\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\af2\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 TELEPHONE NUMBER}\
\\par \\pard\\plain \\ltrpar\\s1\\aspalpha\\ql\\rtlch\\af2\\afs18\\lang255\\ltrch\\dbch\\langfe1033\\hich\\f2\\fs18\\lang1033\\loch\\f2\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f2\\fs18\\lang1033\\i0\\b0 <tel:}\
\\par \\pard\\plain \\ltrpar\\s1\\aspalpha\\ql\\rtlch\\afs24\\lang255\\ltrch\\dbch\\langfe1033\\hich\\fs24\\lang1033\\loch\\fs24\\lang1033 \
\\par \\trowd\\trql\\trrh1936\\trpaddft3\\trpaddt55\\trpaddfl3\\trpaddl55\\trpaddfb3\\trpaddb55\\trpaddfr3\\trpaddr55\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx10800\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s12\\aspalpha\\ql\\rtlch\\af4\\afs18\\lang255\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs18\\lang1033\\loch\\f4\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs18\\lang1033\\i0\\b0 <msg:}\
\\cell\\row\\pard \\pard\\plain \\ltrpar\\s1\\qj\\rtlch\\af4\\afs18\\lang255\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs18\\lang1033\\loch\\f4\\fs18\\lang1033 \
\\par \\trowd\\trql\\trpaddft3\\trpaddt55\\trpaddfl3\\trpaddl55\\trpaddfb3\\trpaddb55\\trpaddfr3\\trpaddr55\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\cellx3240\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\cellx5401\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\cellx8626\\clbrdrt\\brdrs\\brdrw1\\brdrcf1\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx10800\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s12\\aspalpha\\ql\\rtlch\\af4\\afs18\\lang255\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs18\\lang1033\\loch\\f4\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs18\\lang1033\\i0\\b0 FROM}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s12\\aspalpha\\ql\\rtlch\\af4\\afs18\\lang255\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs18\\lang1033\\loch\\f4\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs18\\lang1033\\i0\\b0 DATE/TIME}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s12\\aspalpha\\ql\\rtlch\\af4\\afs18\\lang255\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs18\\lang1033\\loch\\f4\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs18\\lang1033\\i0\\b0 TO}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s12\\aspalpha\\ql\\rtlch\\af4\\afs18\\lang255\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs18\\lang1033\\loch\\f4\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs18\\lang1033\\i0\\b0 DATE/TIME}\
\\cell\\row\\pard \\trowd\\trql\\trpaddft3\\trpaddt55\\trpaddfl3\\trpaddl55\\trpaddfb3\\trpaddb55\\trpaddfr3\\trpaddr55\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\cellx3240\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\cellx5401\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\cellx8626\\clbrdrl\\brdrs\\brdrw1\\brdrcf1\\clbrdrb\\brdrs\\brdrw1\\brdrcf1\\clbrdrr\\brdrs\\brdrw1\\brdrcf1\\cellx10800\
\\pard\\intbl\\pard\\plain \\intbl\\ltrpar\\s12\\aspalpha\\ql\\rtlch\\af4\\afs18\\lang255\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs18\\lang1033\\loch\\f4\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs18\\lang1033\\i0\\b0 <sig:}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s12\\aspalpha\\ql\\rtlch\\af4\\afs18\\lang255\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs18\\lang1033\\loch\\f4\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs18\\lang1033\\i0\\b0 <dt2:}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s12\\aspalpha\\ql\\rtlch\\af4\\afs18\\lang255\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs18\\lang1033\\loch\\f4\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs18\\lang1033\\i0\\b0 <sto:}\
\\cell\\pard\\plain \\intbl\\ltrpar\\s12\\aspalpha\\ql\\rtlch\\af4\\afs18\\lang255\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs18\\lang1033\\loch\\f4\\fs18\\lang1033 {\\rtlch \\ltrch\\loch\\f4\\fs18\\lang1033\\i0\\b0 <dt3:}\
\\cell\\row\\pard \\pard\\plain \\ltrpar\\s1\\qj\\rtlch\\af4\\afs18\\lang255\\ltrch\\dbch\\af4\\langfe1033\\hich\\f4\\fs18\\lang1033\\loch\\f4\\fs18\\lang1033 \
\\par }";


const char rg_txt_template[] = \
"<nbr: <prec:<hx: <sta: <ck: <org: <t1: <d1:\n\
<to:\n\
<tel:<opn:\n\
BT\n\
<msg:\n\
BT\n\
<sig:<op2:\n\
AR\n\
";

