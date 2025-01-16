#!/bin/bash

# Установка значения по умолчанию для сигнала
signal=15  # По умолчанию SIGTERM

#обработка аргументов
while getopts "s:" opt; do
    case $opt in
        s) signal="$OPTARG" ;;
        *) echo "Неверный аргумент." && exit 1 ;;
    esac
done
shift $((OPTIND - 1))

#проверка на наличие имени процесса
if [ "$#" -ne 1 ]; then
    echo "Использование: $0 [-s <номер_сигнала>] <имя_процесса>"
    exit 1
fi

process_name="$1"

#получение PID процессов с указанным именем
pids=$(pgrep "$process_name")

#проверка, найдены ли процессы
if [ -z "$pids" ]; then
    echo "Процесс '$process_name' не найден."
    exit 0
fi

#отправка сигнала к процессам
for pid in $pids; do
    kill -"$signal" "$pid"
    echo "Отправлен сигнал $signal процессу с PID $pid."
done
