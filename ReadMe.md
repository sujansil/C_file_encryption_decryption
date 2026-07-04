# File Encrypter Decrypter🔐
This is a terminal based file encryptor decryptor. Takes input directly from terminal for any .txt file.

## Features 
1. **Encryption** : The input of the user is encrypted by shifting the ASCII value by 3 and lopping that.
2. **Decryption** : Take the encrypted file (or any file) and decrease the ASCII value by 3.
3. **Command** : The user can directly give the command `-e` for Encryption and `-d` for decryption on the terminal itself.
4. **Text File** : Again the user can directly input the text file in the command line. 

## How to use
After compiling the code user need to enter :

For Encryption - 
```bash
./cypher -e <the text file>
```

For Decryption - 
```bash
./cypher -d <the text file>
```

## Tools Used 
1. C

## Personal Note 
This is my first project where i actually wrote something inside the `int main()` and directly used terminal to take input.

