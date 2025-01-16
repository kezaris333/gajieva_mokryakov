#!/bin/bash

#проверка на наличие аргументов
if [ "$#" -ne 1 ]; then
    echo "Использование: $0 <файл_со_списком>"
    exit 1
fi

#имя файла со списком
file_list="$1"

#проверка существования файла
if [ ! -f "$file_list" ]; then
    echo "Файл $file_list не существует."
    exit 1
fi

#чтение файла и удаление указанных файлов
while IFS= read -r file; do
    if [ -e "$file" ]; then
        rm "$file"
        echo "Удалён файл: $file"
    else
        echo "Файл $file не найден."
    fi
done < "$file_list"
