# Task Tracker

Консольное приложение для учета задач студентов.

## О проекте
Данное консольное приложение позволяет вести учёт задач и студентов, которые эти задачи выполняют.\
Для хранения данных используется база данных PostgreSQL.

## Команды:

### Добавление
```bash
./task-tracker add student "Имя" "Фамилия" # Добавить студента
./task-tracker add task "Название задачи" 1 4 # Добавить задачу студентам (1, 4 - ID студентов)
```


### Удаление
```bash
./task-tracker delete student 1 # Удалить студента с ID 1
./task-tracker delete task 5 # Удалить задачу с ID 5
```

### Изменение статуса задач
```bash
./task-tracker mark done 3 # Пометить задачу 3 как выполненную
./task-tracker mark in-progress 2 # Пометить задачу 2 как "в работе"
./task-tracker mark to-do 4 # Вернуть задачу 4 в статус "к выполнению"
```

### Просмотр
```bash
./task-tracker list students # Список всех студентов
./task-tracker list tasks # Список всех задач
./task-tracker list done # Список выполненных задач
./task-tracker list in-progress # Список задач в работе
./task-tracker list to-do # Список задач к выполнению
```

### Обновление
```bash
./task-tracker update task 1 "Новое название" # Обновить название задачи 1
```