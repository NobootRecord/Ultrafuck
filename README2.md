<div align="center">

<img src="img/logo.png" alt="Ultrafuck" title="Ultrafuck">

# Ultrafuck: how does it work?

[Home](README.md) / [Русская версия](README.ru.md)

</div>

<br>

There is one integer value called cmdIndex (in example). By entering **>** or **<** user increases/decreases its value (like switching TV sound volume lol). By entering ~ user resets cmdIndex value to zero. By entering ! command user executes some Brainfuck command depending on this array:

* **NOP**\
    It does nothing. This is default cmdIndex value.
* ***>**\
    Go to next memory cell
* **<**\
    Go to previous memory cell
* **+**\
    Increase (+1) current memory cell value
* **-**\
    Decrease (-1) current memory cell value
* **.**\
    Write current memory cell value into console as ASCII character
* **,**\
    Read ASCII character from keyboard and write into current memory cell

There are also available loop commands **[** and **]** ported from original Brainfuck:

* **[**\
    Start loop (current memory cell value != 0)
* **]**\
    End loop (current memory cell value = 0)

Ultrafuck supports multi-line comments that can make your life code much easier to understand (I hope).

```
***

This is simple multi-line comment in my shitty coded Ultrafuck program!!!!111

MUM IM CODIN DON DIZTRUB ME PLAZ

***
```
