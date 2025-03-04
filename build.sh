echo -n "compiling... "
nasm -f bin -o build/bootloader.bin src/bootloader/boot.asm
nasm -f elf -o build/kernel_entry.o src/kernel/kernel_entry.asm
toolchain/bin/i386elfgcc/bin/i386-elf-gcc -ffreestanding -c src/kernel/kernel.c -o build/kernel.o
toolchain/bin/i386elfgcc/bin/i386-elf-ld -o build/kernel.bin -T src/link.ld build/kernel_entry.o build/kernel.o --oformat binary
echo "done"
echo -n "collecting binaries... "
cat build/bootloader.bin build/kernel.bin > build/os-image.bin
echo "done"
echo "making new diskimage... "
dd if=/dev/zero of=build/harddisk.img bs=512 count=32768
dd if=build/bootloader.bin of=build/harddisk.img bs=512 count=1 conv=notrunc
dd if=build/kernel.bin of=build/harddisk.img bs=512 seek=1 conv=notrunc

# dd if=build/boot.bin of=build/hdd.img conv=notrunc
echo "done"
echo ""
echo "BUILD READY"
