# RICHNITE (RICH) cryptocurrency 

![image](https://media.discordapp.net/attachments/589835363091087385/589837465100222464/Picture100000000.png?width=400&height=180)

Richnite is a cryptonight based cryptocurrency (ticker : RICH)

This is the richnite core source code and binary release.

[Main website](https://richnite-project.github.io/Richnite/)

[Pools](http://pool.stx.nl/RICH/#)

[Richnite-wallet (source and binaries)](https://github.com/richnite-project/Richnite/releases/tag/v0.2.0)


Libraries needed : boost >=1.58

**development branch is now the default behavior, with blood and tears.**

If you want to compile the latest stable release, currently in production, clone the master branch :
```
git clone -b master https://github.com/richnitedev/richnite.git
```

Compilation informations : 
```
$ git clone -b master https://github.com/richnitedev/richnite.git
$ cd richnite
$ mkdir richnite-build
$ cd richnite-build
$ cmake -D STATIC=ON -D CMAKE_BUILD_TYPE=RELEASE ..
$ PORTABLE=1 make
```
