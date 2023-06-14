<div align="center">

<img src="img/logo.png" alt="Ultrafuck" title="Ultrafuck">

# Ultrafuck

Brainfuck programming language made more hardcore and minimalistic

[Русская версия](README.ru.md)

</div>

<br><br>

# 0x00. What is this?

<b>Ultrafuck</b> is an modified version of legendary Brainfuck (BF) esoterical programming language. It has very minimalistic syntax and supports a few commands (and comments too).

Original Brainfuck has been created by Urban Müller in 1993 year, inspired by FALSE programming language. It has about 8 commands that makes much harder programming in Brainfuck (unlike other languages). Brainfuck is very popular language nowadays - it has 10+ active forks and modifications. Ultrafuck project is one of these :)

In Brainfuck language user needs to control one big memory array, increase/decrease memory cell values, write data into console and do other stuff. In Ultrafuck user needs to select some Brainfuck command by... other commands. That's why Ultrafuck is much harder in coding, as I think.

<br>

# 0x01. How does it work?

See [README2](README2.md) for more details. Read at your own risk.

<br>

# 0x02. Usage

Ultrafuck must be executed from command line in this format:

&emsp;&emsp;```$UF_EXECUTABLE [filename] <arguments>```

* ```$UF_EXECUTABLE```\
Ultrafuck interpretator executable file.\
**Linux:** ```./ue``` or ```./ue64```\
**Windows:** ```ue.exe``` or ```ue64.exe```
* ```[filename]```\
Ultrafuck code filename. Recommended using UTF-8 encoded TXT files. You can also (just for fun) rename file to ```*.UF``` extension
* ```<arguments>```\
Additional command-line arguments. Currently supported:\
--- ```-q / --quiet```\
Be quiet, do not display any additional messages - program output only.

What about code editors, you can use even classic Windows Notepad, as Ultrafuck practically _does not_ have any syntax and looks like plain text.

<br>

# 0x03. Compile options

Ultrafuck is currently being compiled and released using MinGW (the latest versions are recommended for usage). There is no different OS API used, so that's why the project can be easily compiled under any OS different from Windows. By the way, you can also use some other compilers like Visual C++, Tiny C Compiler, etc. - why not?

If you have any problems with compiling Ultrafuck on your platform, please contact me immediately - I will help you as much as I can.

<br>

# 0x04. License

Ultrafuck project is licensed under the terms of **The Unlicense**. See [LICENSE](LICENSE) file for more info.

You can do with Ultrafuck what the hell you want. I do not care about this project too much :)

<br>

# 0x05. Authors

* **Ivan Movchan**\
		Ultrafuck author and maintainer

* **Urban Müller**\
		Original Brainfuck author
	
<br>
	
Copyright &copy; 2023. No rights reserved.

<br><br>
