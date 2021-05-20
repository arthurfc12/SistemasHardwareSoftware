qemu-system-x86_64 \
                     -nographic \
                     -kernel /home/arthu/Documents/SisHard/SistemasHardwareSoftware/material/aulas/12-linux-do-zero/linux-5.11.16/arch/x86_64/boot/bzImage \
                     -append "quiet root=PARTUUID=c97393b8-01 console=ttyS0"  \
                     /dev/loop31
