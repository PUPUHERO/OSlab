cp /boot/config-`uname -r` linux-5.4.2/.config
yes '' | make oldconfig

sed -i 's/debian\/canonical-certs\.pem//' linux-5.4.2/.config

sudo make -j$(nproc)
sudo make modules_install -j 4
sudo make install -j 4
sudo update-grub
sudo reboot

