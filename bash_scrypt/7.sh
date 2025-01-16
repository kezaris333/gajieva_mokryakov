#!/bin/bash

#проверка на наличие необходимых аргументов
if [ "$#" -lt 3 ]; then
    echo "Использование: $0 [-s] -o <выходной_каталог> <каталог_поиска> <строка_для_поиска>"
    exit 1
fi

#инициализация переменных
use_symbolic_links=0
output_dir=""
start_dir=""
search_string=""

#оработка параметров
while getopts "so:" opt; do
    case $opt in
        s) use_symbolic_links=1 ;;
        o) output_dir="$OPTARG" ;;
        *) echo "Неверный аргумент." && exit 1 ;;
    esac
done
shift $((OPTIND - 1))

#получение оставшихся аргументов
start_dir="$1"
search_string="$2"

#проверка существования каталогов
[ ! -d "$start_dir" ] && { echo "Каталог $start_dir не существует."; exit 1; }
[ -z "$output_dir" ] && output_dir="."

#поиск и создание ссылок
grep -rl "$search_string" "$start_dir" | while read -r file; do
    link_name="$output_dir/$(basename "$file")"
    if [ "$use_symbolic_links" -eq 1 ]; then
        ln -s "$file" "$link_name"
        echo "Создана символическая ссылка: $link_name"
    else
        ln "$file" "$link_name"
        echo "Создана жесткая ссылка: $link_name"
    fi
done
