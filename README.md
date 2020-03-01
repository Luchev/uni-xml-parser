# XML Parser

This is a library-like project for parsing XML files and strings to an XML tree.

## Use as a standalone program

### Build

Execute the following commands, after that the binary will be in ***uni-xml-parser/bin/xml-parser***

````bash
git clone git@github.com:Luchev/uni-xml-parser.git
cd uni-xml-parser
make init
make release
````

### Run unit tests

Execute the following commands to run all unit tests. Run a single unit test with `make unit-<DesiredObjectToTest>`

```bash
git clone git@github.com:Luchev/uni-xml-parser.git
cd uni-xml-parser
make init
make clean
make unit-all
```

### Parse file

After building the binary execute the following, the program will parse the file and output each element on new line to `stdout`

```bash
uni-xml-parser/bin/xml-parser file-to-parse.xml
```

## Use as a library

To use this code as a library for parsing XML you need to include everything in the `src/`, `lib/` and `include/` directories in your project and add the project root directory and lib/ to the compiler path.

Example:

Let's say you have the following project structure where `./` is your project root directory

```
./src
./lib
./include
./data
./...
```

You need to add to the g++ compiler the following flags `-I . -I lib`

