# OSLAB 13

## Exercise 2

注意到由於邏輯上理想的順序應為`next wait` -> `signal`，但是由於thread的執行順序不確定，因此可能會出現`signal` -> `next wait`的情況，從而造成`wait`的thread永遠等待下去，因此需要將`wait`改為確保上一個thread已經執行完畢後才會執行`wait`，因此需要一個`wait`的`flag(printingNumber)`，當`printingNumber`為上一個數字時，才會執行`wait`，從而使錯過的signal可以再發送一次。