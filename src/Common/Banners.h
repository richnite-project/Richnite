#ifndef BANNERS_H
#define BANNERS_H
// Copyright (c) 2017-2019, The Iridium developers
// You should have received a copy of the GNU Lesser General Public License
// If not, see <http://www.gnu.org/licenses/>.

#endif // BANNERS_H
#pragma once

#include <string>
namespace Common {
const std::string brightRed("\033[0;91m");
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


const std::string othersBanner = brightRed +
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
"          Type \"help\" for the list of available commands.\n"
;

#ifdef _WIN32
//windows has non ansi chars ?
+const std::string banner = windowsBanner;
#else
const std::string banner = othersBanner;
#endif
}
