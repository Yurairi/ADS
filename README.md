1. Стек с динамическим распределением памяти.
Стандартный набор операций:
•	проверка пустоты стека
•	проверка заполненности стекового массива
•	добавление элемента в вершину стека
•	удаление элемента из вершины стека

•	вывод текущего состояния стека на экран
Доп операции:
•	Возможность занесения в стек сразу нескольких значений.
  Количество вводимых значений должно запрашивается у пользователя,
  а сами значения можно формируются случайным образом с помощью функции Random.
•	при удалении элемента из основного стека запросить у пользователя,
  что делать далее с этим элементом: действительно удалить с освобождением памяти или включить его в вершину вспомогательного стека удаленных элементов.
•	при добавлении нового элемента запросить у пользователя происхождение
  этого элемента: действительно создание нового элемента или выбор его с вершины вспомогательного стека.
•	вывод содержимого вспомогательного стека удаленных элементов.


2. Кольцевая очередь на основе массива.
Стандартный набор операций:
•	проверку пустоты очереди
•	проверку заполненности очереди
•	добавление элемента в конец очереди
•	удаление элемента из начала очереди
•	вывод текущего состояния очереди на экран

3. Кольцевая очередь на основе динамического распределения памяти.
Реализовать стандартный набор операций.
Доп операции:
• моделирования работы очереди со случайным числом добавляемых и удаляемых элементов.

4. Упорядоченный список на основе массива.
Стандартный набор операций:
•	проход по списку с выводом на экран информационных частей элементов
•	поиск элемента с заданной информационной частью
•	добавление нового элемента после заданного(информационно) и перед заданным со сдвигом (при необходимости)
  хвостовой части вправо для освобождения ячейки массива.
•	удаление заданного элемента со сдвигом (при необходимости) хвостовой части влево для заполнения образовавшейся пустой ячейки.

5. Линейный список на базе массива с указателями-индексами.
Список должен иметь заголовок (нулевая ячейка массива) с номером первого элемента списка.
Набор операций  - стандартный. Для отслеживания свободных ячеек использовать
простейшую схему – отмечать свободные ячейки специальным значением индекса ( -1).

6. Линейный динамический список со стандартным набором операций.
Доп операции:
•	изменить процедуру удаления элемента из основного списка, заменив операцию освобождения памяти
  операциями добавления удаленного элемента во вспомогательный список (стек).
•	добавить обычную процедуру вывода вспомогательного списка (стека).

7. Линейный динамический двунаправленный список.
Доп операции:
•	просмотр списка в прямом и обратном направлениях.
•	поиск заданного элемента в прямом и обратном направлениях.
•	добавление элемента перед или после заданного.
•	удаление заданного элемента.

8. Набор подпрограмм для выполнения основных операций со списком списков.
Основные операции:
•	полный проход по всей структуре.
•	поиск заданного элемента.
•	добавление нового элемента в массив с пустым связанным списком.
•	добавление нового элемента в связанный список.
•	удаление элемента из связанного списка.
•	удаление элемента из базового массива.

9. Идеально сбалансированные двоичные деревья. 
Реализовать программу, выполняющую следующий набор операций:
•	построение идеально сбалансированного двоичного дерева с заданным числом вершин.
•	построчный вывод дерева на основе процедуры обхода в прямом порядке.
•	построчный вывод дерева на основе процедуры обхода в симметричном порядке.
•	построчный вывод дерева на основе процедуры обхода в обратно-симметричном порядке.

10. Добавить в предыдущую программу нерекурсивный вариант процедуры обхода дерева в симметричном порядке.

11. Произвольные двоичные деревья.
Основные операции:
•	поиск вершины с заданным значением информационной части.
•	добавление левого или правого потомка для заданной вершины.
•	построчный вывод дерева с помощью основных правил обхода.
•	уничтожение всего дерева.

12. Двоичные деревья поиска.
Стандартный набор операций:
•	поиск вершины с заданным значением ключа с выводом счетчика числа появлений данного ключа.
•	добавление новой вершины в соответствии со значением ее ключа или увеличение счетчика числа появлений.
•	построчный вывод дерева в наглядном виде с помощью обратно-симметричного обхода.
•	вывод всех вершин в одну строку по порядку следования ключей с указанием для каждой вершины значения ее счетчика появлений.
•	удаление вершины с заданным значением ключа.




