#!/bin/bash

#проверка на наличие аргументов
if [ "$#" -ne 1 ]; then
    echo "использование: $0 <файл_со_списком>"
    exit 1
fi

#имя файла со списком
file_list="$1"

#проверка существования файла
if [ ! -f "$file_list" ]; then
    echo "файл $file_list не существует."
    exit 1
fi

#чтение файла и удаление указанных файлов
while IFS= read -r file; do
    if [ -e "$file" ]; then
        rm "$file"
        echo "удалён файл: $file"
    else
        echo "файл $file не найден."
    fi
done < "$file_list"
