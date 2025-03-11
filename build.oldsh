echo -n "doing the dishes... "

rm -rf build
mkdir build
(make -C src/kernel clean) > logs/clean.log

echo "done"
echo -n "compiling bootloader... "

nasm -o build/boot src/bootloader/boot.asm

echo "done"
echo -n "compiling kernel... "

(make -C src/kernel) > logs/kernel.log
mv src/kernel/kernel build/kernel
mv src/kernel/kernel.elf build/kernel.elf

echo "done"

#echo "BUILD DIR STATE: "
# ls build

echo -n "making new diskimage... "

(
kernel_size=$(wc -c < build/kernel)
kernel_sectors=$(( ($kernel_size + 511) / 512 ))
printf %02x $kernel_sectors | xxd -r -p | dd of=build/boot bs=1 seek=2 count=1 conv=notrunc

cp build/boot ./os.img
cat build/kernel >> os.img
dd if=/dev/zero bs=1 count=512 >> os.img
mv os.img build/os.img
) 2>logs/diskimg.log
echo "done"

echo "build finished."
