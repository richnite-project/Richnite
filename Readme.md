# RICHNITE (RICH) cryptocurrency 

![image](https://media.discordapp.net/attachments/589835363091087385/589837465100222464/Picture100000000.png?width=400&height=180)

Richnite is a cryptonight based cryptocurrency (ticker : RICH)

This is the richnite core source code and binary release.

[Main website](https://richnite-project.github.io/Richnite/)

[Pools](http://pool.stx.nl/RICH/#)

[Richnite-wallet (source and binaries)](https://github.com/richnite-project/Richnite/releases/tag/V5.0.0)


Libraries needed : boost >=1.70

**master branch is now the default behavior, with blood and tears.**

If you want to compile the latest stable release, currently in production, clone the master branch :
```
git clone -b master https://github.com/richnitedev/richnite.git
```

## Linux
Compilation informations : 
```
$ git clone -b master https://github.com/richnitedev/richnite.git
$ cd richnite
$ mkdir richnite-build
$ cd richnite-build
$ cmake -D STATIC=ON -D CMAKE_BUILD_TYPE=RELEASE ..
$ PORTABLE=1 make
```


## Windows
Prerequisites
You can build for 32-bit or 64-bit Windows. If you're not sure, pick 64-bit.
```
Install Visual Studio 2017 Community Edition
When installing Visual Studio, it is required that you install Desktop development with C++
Install the latest version of Boost (currently Boost 1.70). Select the appropriate version for your system:
Boost 64-bit
Boost 32-bit
Install the latest full version of OpenSSL (currently OpenSSL 1.1.1b). Select the appropriate version for your system:
OpenSSL 64-bit
OpenSSL 32-bit
Building
```

## For 64-bit:
```
From the start menu, open 'x64 Native Tools Command Prompt for vs2017'.
cd <your_richnite_directory>
mkdir build
cd build
set PATH="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin";%PATH%
cmake -G "Visual Studio 15 2017 Win64" .. -DBOOST_ROOT=C:/local/boost_1_70_0
MSBuild richnite.sln /p:Configuration=Release /m
```
## For 32-bit:
```
From the start menu, open 'x86 Native Tools Command Prompt for vs2017'.
cd <your_richnite_directory>
mkdir build
cd build
set PATH="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin";%PATH%
cmake -G "Visual Studio 15 2017" .. -DBOOST_ROOT=C:/local/boost_1_70_0
MSBuild richnite.sln /p:Configuration=Release /p:Platform=Win32 /m
The binaries will be in the src/Release folder when you are complete.

cd src
cd Release
richnited.exe --version
```



### [JOIN DISCORD](https://discord.gg/m7rdznM)


### [JOIN DISCORD](https://discord.gg/m7rdznM)
