Adhesive
----------------
Adhesive is designed to be a very light, portable utility that allows you to easily call functions from any other language.

Running examples
---------------
First, fire up a new terminal, create an empty folder for your project, go into that folder, and type:

```bash
git clone https://github.com/JacksonCoder/adhesive
```

To set up the node enviroment (make sure you have node installed first) type:
```bash
npm install child_process
```
which should get all script dependencies installed.


To compile the C++ program, type:
```bash
make app
```
To test the python script, type:
```bash
python test.py
```

The output should be:
```bash
Hello
```

To test the C++ executable, type:
```bash
./test
```

The output should be
```bash
hello?
```

To test the JS script, type:
```bash
node test.js
```

The output should be
```bash
Hello
```
