1. 卸载vim（whereis vim	sudo apt remove vim）
2. 安装vim的依赖文件一大堆
3. 安装cmake,make,build-essential,git-all，检查python版本以及目录
4. vim-plug安装方法
5. 仓库地址。。。。
6. 克隆。。。
7. 配置信息及要求
8. 漫长等待

更新源

```sh
sudo apt update
sudo apt upgrade
```

更新软件

```sh
sudo apt install cmake make git-all build-essential
```

检查python3版本与路径python3-config-dir

```sh
$python3 --version
Python 3.8.5
路径
/usr/lib/python3.8/config-3.8-x86_64-linux-gnu
```

卸载vi vim（终端输入vim没效果）

```sh
whereis vi
whereis vim
```

安装依赖

```sh
sudo apt install libncurses5-dev libgtk2.0-dev libatk1.0-dev libcairo2-dev libx11-dev libxpm-dev libxt-dev python2-dev python3-dev ruby-dev lua5.2 liblua5.2-dev libperl-dev
```

克隆仓库（github下载速度慢怎么办）

```sh
cd vim
./configure --with-features=huge --enable-multibyte --enable-rubyinterp=yes --enable-python3interp=yes --with-python3-config-dir=/usr/lib/python3.8/config-3.8-x86_64-linux-gnu --enable-perlinterp=yes --enable-luainterp=yes --enable-gui=gtk2 --enable-cscope --prefix=/usr/local
cd src
make
make install
```

检查python3是否安装成功（:version ; has echo('python3')）

安装curl和vim-plug（安装不成功的方法）

```sh
sudo apt install curl
curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
```

配置vim-plug

安装vimcdoc

编译对资源消耗非常巨大，这里使用消耗较小的Release版本，如果还是遇到报错，请扩展swap（链接）同时留出大概100G的完整硬盘空间（链接）

克隆llvm-project（使用镜像）

https://gitee.com/mirrors/llvm-project

```sh
cd llvm-project
git checkout main
mkdir build
cd build
cmake -DLLVM_ENABLE_PROJECTS="clang;libcxx;libcxxabi;clang-tools-extra;libunwind;lldb;compiler-rt;lld;polly;debuginfo-tests" -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" ../llvm
cmake --build . -- -j 4
make install
```

```
Plugin 'SirVer/ultisnips'
Plugin 'derekwyatt/vim-protodef'
Plugin 'scrooloose/nerdtree'
Plugin 'fholgado/minibufexpl.vim'
Plugin 'gcmt/wildfire.vim'
Plugin 'sjl/gundo.vim'
Plugin 'Lokaltog/vim-easymotion'
Plugin 'suan/vim-instant-markdown'
Plugin 'lilydjwg/fcitx.vim'

/usr/lib/python3.8/config-3.8-x86_64-linux-gnu
./configure --with-features=huge --enable-multibyte --enable-rubyinterp=yes --enable-python3interp=yes --with-python3-config-dir=/usr/lib/python3.8/config-3.8-x86_64-linux-gnu --enable-perlinterp=yes --enable-luainterp=yes --enable-gui=gtk2 --enable-cscope --prefix=/usr/local

sudo apt install libncurses5-dev libgtk2.0-dev libatk1.0-dev libcairo2-dev libx11-dev libxpm-dev libxt-dev python3-dev ruby-dev lua5.2 liblua5.2-dev libperl-dev git

curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

cmake -DLLVM_ENABLE_PROJECTS="clang;libcxx;libcxxabi;clang-tools-extra;libunwind;lldb;compiler-rt;lld;polly;debuginfo-tests" -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" ../llvm

cmake --build . -- -j 4

dd if=/dev/zero of=/media/darcy/swapfile.img bs=1024 count=20M
mkswap /media/darcy/swapfile.img
/media/darcy/swapfile.img swap swap sw 0 0
swapon /media/darcy/swapfile.img
cat /proc/swaps
grep 'Swap' /proc/meminfo

fdisk /dev/sda
mkfs.ext2 /dev/sda3

./configure --prefix=/usr/local


" 设置 tagbar 子窗口的位置出现在主编辑区的左边 
let tagbar_left=1 
" 设置显示／隐藏标签列表子窗口的快捷键。速记：identifier list by tag
nnoremap <Leader>ilt :TagbarToggle<CR> 
" 设置标签子窗口的宽度 
let tagbar_width=32 
" tagbar 子窗口中不显示冗余帮助信息 
let g:tagbar_compact=1
" 设置 ctags 对哪些代码标识符生成标签
let g:tagbar_type_cpp = {
    \ 'kinds' : [
         \ 'c:classes:0:1',
         \ 'd:macros:0:1',
         \ 'e:enumerators:0:0', 
         \ 'f:functions:0:1',
         \ 'g:enumeration:0:1',
         \ 'l:local:0:1',
         \ 'm:members:0:1',
         \ 'n:namespaces:0:1',
         \ 'p:functions_prototypes:0:1',
         \ 's:structs:0:1',
         \ 't:typedefs:0:1',
         \ 'u:unions:0:1',
         \ 'v:global:0:1',
         \ 'x:external:0:1'
     \ ],
     \ 'sro'        : '::',
     \ 'kind2scope' : {
         \ 'g' : 'enum',
         \ 'n' : 'namespace',
         \ 'c' : 'class',
         \ 's' : 'struct',
         \ 'u' : 'union'
     \ },
     \ 'scope2kind' : {
         \ 'enum'      : 'g',
         \ 'namespace' : 'n',
         \ 'class'     : 'c',
         \ 'struct'    : 's',
         \ 'union'     : 'u'
     \ }
\ }

" 设置插件 indexer 调用 ctags 的参数
" 默认 --c++-kinds=+p+l，重新设置为 --c++-kinds=+p+l+x+c+d+e+f+g+m+n+s+t+u+v
" 默认 --fields=+iaS 不满足 YCM 要求，需改为 --fields=+iaSl
let g:indexer_ctagsCommandLineOptions="--c++-kinds=+p+l+x+c+d+e+f+g+m+n+s+t+u+v --fields=+iaSl --extra=+q"
```



```
sudo vi /etc/apt/sources.list

# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-updates main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-backports main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-backports main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-security main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-security main restricted universe multiverse

# 预发布软件源，不建议启用
# deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-proposed main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ focal-proposed main restricted universe multiverse

sudo apt update
sudo apt upgrade
sudo apt autoremove
sudo apt install build-essential git-all cmake curl wget make 

sudo apt remove vim vi gvim vim-runtime
whereis vi
whereis vim

sudo apt install libncurses5-dev libgtk2.0-dev libatk1.0-dev libcairo2-dev libx11-dev libxpm-dev libxt-dev python3-dev ruby-dev lua5.2 liblua5.2-dev libperl-dev

cd
git clone https://github.com.cnpmjs.org/vim/vim.git
cd vim
./configure --with-features=huge --enable-multibyte --enable-rubyinterp=yes --enable-python3interp=yes --with-python3-config-dir=/usr/lib/python3.8/config-3.8-x86_64-linux-gnu --enable-perlinterp=yes --enable-luainterp=yes --enable-gui=gtk2 --enable-cscope --prefix=/usr/local

cd src
make
sudo make install
sudo update-alternatives --install /usr/bin/editor editor /usr/local/bin/vim 1
sudo update-alternatives --set editor /usr/local/bin/vim
sudo update-alternatives --install /usr/bin/vi vi /usr/local/bin/vim 1
sudo update-alternatives --set vi /usr/local/bin/vim

git clone https://gitee.com/mirrors/llvm-project
cd llvm-project
git checkout main
mkdir build
cd build

cmake -DLLVM_ENABLE_PROJECTS="clang;libcxx;libcxxabi;clang-tools-extra;libunwind;lldb;compiler-rt;lld;polly;debuginfo-tests" -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" ../llvm

cmake --build . -- -j 6
sudo make install

cd
git clone https://github.com.cnpmjs.org/ycm-core/YouCompleteMe

sudo apt install vim-nox python3-dev mono-complete golang nodejs default-jdk npm

python3 install.py --clangd-completer

EDA4F400B6DDF888
```

https://github.com/ycm-core/YouCompleteMe/wiki/Building-Vim-from-source