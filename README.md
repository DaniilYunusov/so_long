# so_long - это игра, в которой персонаж, двигаясь по карте, собирает предметы. После сбора всех предметов открываются двери, выходя в которые игра/уровень заканчивается. В бонусной части реализован патруль, который, когда видит персонажа, начинает двигаться в его сторону (1 ход персонажа сопровождается 1 ходом вражеского персонажа/патруля). Также реализована анимация персонажа и патруля и счетчик ходов. Также я реализовал несколько уровней.
make - компляция безбонусной части, где отсутствует патруль и анимация с счетчиком ходов. ./so_long <name_map> запускает игру с заданной валидной картой
make bonus - компиляция бонусной части,в которой есть патруль, анимации как вражеских персонажей, так и игрового персонажа и счетчик ходов соответственно.  ./so_long_bonus <name_map> запускает игру с заданной волидной картой
./game - запуск 4 специально спроектированных уровней, где 2 первых уровня - ознокомительные, а 2 последних, на мой чисто субъективный взгляд, достаточно сложные в прохождении.
Данный проект поддерживается на Macintosh Operating System (Mac OS), на других операционных системах он не поддерживается.
