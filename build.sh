echo -n "compiling... "
nasm -f bin src/bootloader/boot.asm -o build/boot.bin
echo "done"
echo "making new diskimage... "
dd if=/dev/zero of=build/hdd.img bs=512 count=131072
echo "done"
echo "copying bin to diskimage... "
dd if=build/boot.bin of=build/hdd.img conv=notrunc
echo "done"
echo ""
echo "BUILD READY"
