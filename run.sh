#qemu-system-x86_64 -hda build/hdd.img -nographic  -k en-us
#qemu-system-x86_64 -fda build/os-image.bin -nographic
#qemu-system-x86_64 -hda build/harddisk.img -nographic -d int
qemu-system-x86_64 -drive format=raw,file=build/os.img
