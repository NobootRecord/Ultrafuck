<div align="center">

<img src="img/logo.png" alt="Ultrafuck" title="Ultrafuck">

# Ultrafuck: как это работает

Спойлер: никак)))

[Домой](README.ru.md) / [English version](README2.md)

</div>

<br>

За определённую Brainfuck-команду отвечает переменная cmdIndex. Команды > и < переключают на следующую/предыдущую Brainfuck-команду в их несуществующем меню (чем-то напоминает управление громкостью на телевизоре, не так ли?). Команда ~ сбрасывает значение cmdIndex на 0. А команда ! в зависимости от значения переменной исполняет нужную Brainfuck-команду:

* **NOP**\
    Нифига не делает. Дефолтное значение переменной cmdIndex.
* **>**\
    Перейти к следующей ячейке памяти
* **<**\
    Перейти к предыдущей ячейке памяти
* **+**\
    Инкремент (+1) значения ячейки
* **-**\
    Декремент (+1) значения ячейки
* **.**\
    Записать значение ячейки в консоль в формате символа ASCII
* **,**\
    Считать символ ASCII с клавиатуры и записать в ячейку

Также в Ultrafuck доступны команды запуска цикла **[** и **]** прямиком из оригинального Brainfuck:

* **[**\
    Начало цикла (значение ячейки != 0)
* **]**\
    Конец цикла (значение ячейки = 0)

А ещё Ultrafuck поддерживает комментарии, которые делают жизнь программиста ярче и веселее (ну типа). Смотрите сами:

```
***

=== ваня хакер 0x824A51D0 !!!!!!!11!! ===
взломаю школьный сервер прошиваю bios/uefi на утюги :3
девочки звоните 88005553535 пишите в контакте: http://vkontakte.ru/durov

***
```

Вот как-то так.
