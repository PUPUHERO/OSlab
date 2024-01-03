# example1

## 注意事項

1. 編譯時要加上 `-lrt` 參數，否則會出現 `undefined reference to 'mq_open'` 的錯誤訊息。

2. 在WSL中，使用strcmp()比較字串時，要注意檔案末端字串的結尾為`"\r\n\?"`，CRLF + Delete
