# lab04

編譯linux kernal

## 使用說明

將此處所有檔案複製到ubuntu桌面並且執行 `bash auto_bash.sh`

### Notes

1. 成功進入時會卡在`a start job is running for hold until boot process finishes up`一段時間，正常等待即可
2. 進入grub的方法
    1. 修改設定文件
        
        `sudo vim /etc/default/grub`
        
        修改`GRUB_TIMEOUT_STYLE=menu`, `GRUB_TIMEOUT=10`
        
        `sudo grub-mkconfig -o /boot/grub/grub.cfg`
        
    2. 或使用鍵盤進入
        
        `shift` or `esc`
        
3. 注意: 一旦編譯失敗則須執行清理指令
    
    ```bash
    sudo make clean
    ```
    
4. 需保留足夠的空間，嘗試多次失敗並將文件丟到Trash可能導致空間不足，需清理垃圾桶
    
    ```bash
    rm -rf ~/.local/share/Trash/*
    ```

### Troubleshooting

- init … too big
    
    在VMware上疑似使用BIOS啟動，更換成VirtualBox並以UEFI啟動即可解決

    VMware預設使用BIOS啟動，若要修改為UEFI，則須在安裝時將`.vmx`檔案中的設定加入`firmware = "efi"`，若已安裝則需修改`.vmx`檔案中的設定並且重新安裝
    
- Loading initial Ramdisk
    
    問題: 使用Zorin時出現 卡在此處無法進入系統 可能是編譯失敗
    
    解決: 重新編譯並設定grub即可