#ifndef BANNERS_H
#define BANNERS_H
// Copyright (c) 2017-2019, The Iridium developers
// Ascii Arts by Thunderosa and Stevebrush - Remember the good old time
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#endif // BANNERS_H
#pragma once

#include <string>
namespace Common {
const std::string brightRed("\033[0;91m");
const std::string Red("\033[0;31m");
const std::string Green("\033[0;32m");
const std::string White("\033[1;37m");
const std::string reset("\033[0m");

const std::string windowsBanner =
"\n"
"*******************************************************************************\n"
"*                      _      _     _ _                                       *\n"
"*                     (_)_ __(_) __| (_)_   _ _ __ ___                        *\n"
"*                     | | '__| |/ _` | | | | | '_ ` _ \\                       *\n"
"*                     | | |  | | (_| | | |_| | | | | | |                      *\n"
"*                     |_|_|  |_|\\__,_|_|\\__,_|_| |_| |_|                      *\n"
"*                                                                             *\n"
"*                              People are power                               *\n"
"*******************************************************************************\n"
;

const std::string WTBanner =
"\n"
"-------------------------------------------------------------------------------"
" 	        ..~~..                                                              "
"        ..~~~~~~~~..                                                           "
"     .~~~~~~~~~~~~~~~.        II  .RRRR.  II  .DDDD.   II  UU   UU  .MM     MMM"
"  .:~~~~~~~~~~~~~~~~~~~:.     II  RR''RR  II  DD''DD.  II  UU   UU  MMMM   MMMM"
" 88~~~~~~~~~~~~~~~~~~~~~77    II  RR  RR  II  DD   DD  II  UU   UU  MMMM. .MMMM"
" 88888~~~~~~~~~~~~~~~77777    II  RR  RR  II  DD   DD  II  UU   UU  MM.M. .M.MM"
" 88888888~~~~~~~~~77777777    II  RR  R.  II  DD   DD  II  UU   UU  MM.MM MM.MM"
" 88888888888~~~77777777777    II  RRRRR.  II  DD   DD  II  UU   UU  MM .M M. MM"
" 888888888888Z777777777777    II  RR. RR  II  DD   DD  II  UU   UU  MM  M.M  MM"
" 888888888888Z777777777777    II  RR  RR  II  DD   DD  II  UU   UU  MM  MMM  MM"
" 888888888888Z777777777777    II  RR  RR  II  DD..DD.  II  .UU UU.  MM  .M.  MM"
" ~88888888888Z77777777777~    II  RR  RR  II  DDDDD.   II   .UUU.   MM   M   MM"
"   .888888888Z7777777777.                                                      "
"     .~888888Z777777~.        PERSONAL DIGITAL MONEY | A FAIR LAUNCHED CURRENCY"
"        .~888Z777~.                                                            "
"            ~~~                                                                "
"-------------------------------------------------------------------------------"
;

const std::string othersBanner = Red +
"\n"
"*******************************************************************************\n"
"*                      _      _     _ _                                       *\n"
"*                     (_)_ __(_) __| (_)_   _ _ __ ___                        *\n"
"*                     | | '__| |/ _` | | | | | '_ ` _ \\                       *\n"
"*                     | | |  | | (_| | | |_| | | | | | |                      *\n"
"*                     |_|_|  |_|\\__,_|_|\\__,_|_| |_| |_|                      *\n"
"*                                                                             *\n"
"*                ┌─┐┌─┐┌─┐┌─┐┬  ┌─┐  ┌─┐┬─┐┌─┐  ┌─┐┌─┐┬ ┬┌─┐┬─┐               *\n"
"*                ├─┘├┤ │ │├─┘│  ├┤   ├─┤├┬┘├┤   ├─┘│ ││││├┤ ├┬┘               *\n"
"*                ┴  └─┘└─┘┴  ┴─┘└─┘  ┴ ┴┴└─└─┘  ┴  └─┘└┴┘└─┘┴└─               *\n"
"*******************************************************************************\n"
 + reset;

const std::string bannerText =
"          Your node is now synchronized with the Iridium network\n"
"             Type \"help\" for the list of available commands\n"
;

const std::string TBanner = brightRed +
"\n"
"--------------------------------------------------------------------------------\n"+ White +
"           ..~~..\n"
"        ..~~~~~~~~..\n"
"     .~~~~~~~~~~~~~~~.        II  .RRRR.  II  .DDDD.   II  UU   UU  .MM     MMM\n"
"  .:~~~~~~~~~~~~~~~~~~~:.     II  RR''RR  II  DD''DD.  II  UU   UU  MMMM   MMMM\n"
" 88~~~~~~~~~~~~~~~~~~~~~77    II  RR  RR  II  DD   DD  II  UU   UU  MMMM. .MMMM\n"
" 88888~~~~~~~~~~~~~~~77777    II  RR  RR  II  DD   DD  II  UU   UU  MM.M. .M.MM\n"
" 88888888~~~~~~~~~77777777    II  RR  R.  II  DD   DD  II  UU   UU  MM.MM MM.MM\n"
" 88888888888~~~77777777777    II  RRRRR.  II  DD   DD  II  UU   UU  MM .M M. MM\n"
" 888888888888Z777777777777    II  RR. RR  II  DD   DD  II  UU   UU  MM  M.M  MM\n"
" 888888888888Z777777777777    II  RR  RR  II  DD   DD  II  UU   UU  MM  MMM  MM\n"
" 888888888888Z777777777777    II  RR  RR  II  DD..DD.  II  .UU UU.  MM  .M.  MM\n"
" ~88888888888Z77777777777~    II  RR  RR  II  DDDDD.   II   .UUU.   MM   M   MM\n"
"   .888888888Z7777777777.\n"
"     .~888888Z777777~.        PERSONAL DIGITAL MONEY | A FAIR LAUNCHED CURRENCY\n"
"        .~888Z777~.\n"
"            ~~~\n"+brightRed+
"--------------------------------------------------------------------------------\n"+Green
;

#ifdef _WIN32
//windows has non ansi chars ?
const std::string banner = WTBanner;
#else
const std::string banner = TBanner;
#endif
}
