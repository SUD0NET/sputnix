mkdir toolchain
mkdir build

mkdir toolchain/tmp
mkdir toolchain/bin
mkdir toolchain/bin/i386elfgcc

apt -y install \
    build-essential \
    clang \
    curl \
    gdb \
    git \
    lld \
    lldb \
    llvm \
    nasm \
    qemu-system \
    xxd \
    zsh

chmod +x toolchain.sh
. "$(pwd)/toolchain.sh"

chmod +x toolchain-cleanup.sh
. "$(pwd)/toolchain-cleanup.sh"

echo "did not install qemu. to install qemu, run install-qemu.sh"
