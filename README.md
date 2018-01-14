Ncoin
=====

**Project: "Ncoin-qt"**  
**Name: "Ncoin"**  
**Ticker: "N"**

This is the reference code for the [Ncoin](http://ncoin.ggtm.eu) CryptoCurrency...

-----

General Information (or what makes us us):
------------------------------------------

**01. Total money supply** (src/CryptoNoteConfig.h)

*48.484.848.484,00000000 N*

**02. Emission curve** (src/CryptoNoteConfig.h)

*30*

**03. Difficulty target** (src/CryptoNoteConfig.h)

*300*

**04. Default ports for P2P and RPC networking** (src/CryptoNoteConfig.h)

*P2P: 48537*  
*RPC: 48137*

**05. Network identifier** (src/P2p/P2pNetworks.h)

*0x6c, 0x75, 0x76, 0x73, 0x6f, 0x66, 0x69, 0x65, 0x76, 0x65, 0x72, 0x76, 0x6c, 0x6f, 0x65, 0x74*

**06. Seed nodes** (src/CryptoNoteConfig.h)

*home.ggtm.eu:48537*  
*lenonine.ggtm.eu:48537*  
*starincl.ggtm.eu:48537*

**07. Minimum transaction fee** (src/CryptoNoteConfig.h)

*100000*

**08. Penalty free block size** (src/CryptoNoteConfig.h)

*25000*

**09. Address prefix** (src/CryptoNoteConfig.h)

*0x1481* **//** *"Nc"*

**10. Base transaction hash** (src/CryptoNoteConfig.h)

*013c01ff00019fba94e910029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121013973f1352b41a2ea4e29c98192e3d8c7bee71058a0f42eb7c04090f7c576e279*

-----

To Build:
---------

## __Unix:__

**01. Clone the Ncoin base sources**

*git clone https://github.com/Nephatiu/Ncoin*

**02. Clone the Ncoin-Wallet sources**

*git clone https://github.com/Nephatiu/Ncoin-Wallet*

**03. Create a symbolic link to the Ncoin sources in the Ncoin-Wallet sources named 'Ncore':**

*cd Ncoin-Wallet*  
*ln -s ../Ncoin Ncore*

**03. An alternative way is to create a git submodule directly:**

*cd Ncoin-Wallet*  
*git submodule add https://github.com/Nephatiu/Ncoin Ncore*

**04. Build**

*mkdir build && cd build && cmake .. && make*

## __Windows:__

**00. Yet to be documented**

## Precompiled Binaries:

**Can be found here:**

*[Our Releases](https://github.com/Nephatiu/Ncoin-Wallet/releases)*

-----
