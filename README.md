**Project: "Ncoin"**
**Name: "Ncoin"**
**Ticker: "XFC"**

**1. Clone Ncoin-Wallet sources**

git clone https://github.com/Nephatiu/Ncoin-Wallet

**2. Set symbolic link to coin sources at the same level as `src`. For example:**

ln -s ../Ncoin Ncoin

**-. Alternative way is to create git submodule:**

git submodule add https://github.com/Nephatiu\Ncoin Ncoin

Replace URL with git remote repository of your coin.

**3. Build**

mkdir build && cd build && cmake .. && make
