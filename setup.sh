mkdir toolchain
mkdir build

mkdir toolchain/tmp
mkdir toolchain/bin
mkdir toolchain/bin/i386elfgcc

chmod +x toolchain.sh
. "$(pwd)/toolchain.sh"

chmod +x toolchain-cleanup.sh
. "$(pwd)/toolchain-cleanup.sh"

echo "did not install qemu. to install qemu, run install-qemu.sh"
