# samp-rce

Small presentation example of Remote Code Execution in SA:MP. This vuln is fixed in latest RC samp 0.3.7-R5

### Setup
1. #### Download files
2. #### Compile `src/` (cpp) project to .dll
   - `src/` is just small example of downloading samp037r5 file and run it with telegram logger
   - #### Note: you already have build file in dir `release/` with name `sampRCE.dll`
3. #### Rename file to change extension from `.dll` to `.asi`
4. #### Move the file to dir `sRDI/`
   - #### sRDI is external tool you can get it here: https://github.com/monoxgas/sRDI
5. #### Convert to shellcode
   ```
   py .\ConvertToShellcode.py .\sampRCE.asi
   ```
6. #### Move converted `sampRCE.asi` to `server/scriptfiles/`
7. #### Run server with `sampctl run`, join into game and that's it

### 
```
|----------|                   |---------|                                         |--------|
| samp svr | ---> [rce.pwn] -> | payload | <---> [ scriptfiles/sampRCE.asi ] ----> | client |
|----------|                   |---------|                                         |------- |
```
### demo images
#### client
![demo1](images/serverside_demo.png)
#### telegram logger example
![demo2](images/telegram_demo.png)
