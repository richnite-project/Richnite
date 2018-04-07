# iridium cryptocurrency (IRD)

![iridium logo](https://avatars1.githubusercontent.com/u/31619794?s=460&v=4)

Iridium is a cryptonight based cryptocurrency (ticker : IRD)

This is the iridium core source code and binary release.

[Main website](http://ird.cash)

[BitcoinTalk main announcement thread](https://bitcointalk.org/index.php?topic=2150442.0;all)

[iridium-wallet gui (source and binaries)](https://github.com/iridiumdev/Iridium-wallet)

[iridium graphicals elements](https://github.com/iridiumdev/iridium-graphics)


Libraries needed : boost >=1.58

How to compile this : 
```
$ git clone https://github.com/iridiumdev/iridium.git
$ cd iridium
$ mkdir iridium-build
$ cd iridium-build
$ cmake -D STATIC=ON -D CMAKE_BUILD_TYPE=RELEASE ..
$ PORTABLE=1 make
```
