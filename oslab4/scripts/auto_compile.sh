cd "linux-5.4.2"
sudo cp /boot/config-`uname -r` .config
yes '' |sudo make oldconfig

sed -i 's/debian\/canonical-certs\.pem//' .config

sudo make -j$(nproc)
sudo make modules_install -j 4
sudo make install -j 4
sudo update-grub
