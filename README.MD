# Task Tracker

���������� ���������� ��� ����� ����� ���������.

## � �������
���������� ���������� ��� ������� ����� ����� � ���������, ����������� ��� ������.\
��� �������� ������ ������������ ���� PostgreSQL.

## �������

### ����������
```bash
./task-tracker add student "���" "�������" # �������� ��������
./task-tracker add task "�������� ������" 1 4 # �������� ������ ��������� (1, 4 - ID ���������)
```


### ��������
```bash
./task-tracker delete student 1 # ������� �������� � ID 1
./task-tracker delete task 5 # ������� ������ � ID 5
```

### ��������� ������� �����
```bash
./task-tracker mark done 3 # �������� ������ 3 ��� �����������
./task-tracker mark in-progress 2 # �������� ������ 2 ��� "� ������"
./task-tracker mark to-do 4 # ������� ������ 4 � ������ "� ����������"
```

### ��������
```bash
./task-tracker list students # ������ ���� ���������
./task-tracker list tasks # ������ ���� �����
./task-tracker list done # ������ ����������� �����
./task-tracker list in-progress # ������ ����� � ������
./task-tracker list to-do # ������ ����� � ����������
```

### ����������
```bash
./task-tracker update task 1 "����� ��������" # �������� �������� ������ 1
```