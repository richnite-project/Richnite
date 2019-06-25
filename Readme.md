# RICHNITE cryptocurrency (RICH)

![image](https://discordapp.com/channels/589813035422449684/589835363091087385/589837465100222465)

Iridium is a cryptonight based cryptocurrency (ticker : IRD)

This is the iridium core source code and binary release.

[Main website](http://ird.cash)

[BitcoinTalk main announcement thread](https://bitcointalk.org/index.php?topic=2150442.0;all)

[iridium-wallet gui (source and binaries)](https://github.com/iridiumdev/Iridium-wallet)

[iridium graphicals elements](https://github.com/iridiumdev/iridium-graphics)


Libraries needed : boost >=1.58

**development branch is now the default behavior, with blood and tears.**

If you want to compile the latest stable release, currently in production, clone the master branch :
```
git clone -b master https://github.com/iridiumdev/iridium.git
```

Compilation informations : 
```
$ git clone -b master https://github.com/iridiumdev/iridium.git
$ cd iridium
$ mkdir iridium-build
$ cd iridium-build
$ cmake -D STATIC=ON -D CMAKE_BUILD_TYPE=RELEASE ..
$ PORTABLE=1 make
```
